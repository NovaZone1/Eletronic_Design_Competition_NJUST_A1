#include "Track.hpp"
#include "SpeedMixer.hpp"

GPIO_Regs *gray_regs[8] = {Sensor_1_PORT, Sensor_2_PORT, Sensor_3_PORT, Sensor_4_PORT,
                           Sensor_5_PORT, Sensor_6_PORT, Sensor_7_PORT, Sensor_8_PORT};
uint32_t gray_pins[8] = {Sensor_1_Sensor_1_PIN_PIN, Sensor_2_Sensor_2_PIN_PIN, Sensor_3_Sensor_3_PIN_PIN,
                         Sensor_4_Sensor_4_PIN_PIN, Sensor_5_Sensor_5_PIN_PIN, Sensor_6_Sensor_6_PIN_PIN,
                         Sensor_7_Sensor_7_PIN_PIN, Sensor_8_Sensor_8_PIN_PIN};

StdSensor::TriggerPolarity polarities[8] = {StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH,
                                            StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH,
                                            StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH};

Track &track_app = Track::GetInstance();

void Track::Start() {
    gray_sensor.Init(gray_regs, gray_pins, polarities);

    for (int i = 0; i < 8; i++) {
        gray_state[i] = false;
    }

    track_pid.Init(8.0f, 0.0f, 0.0f, false);
    track_pid.SetLimit(60.0f, max_speed_diff, 0.85f);
    track_pid.SetDeadband(0.1, 0.3);
}

void Track::Update() {
    if (!is_enabled) {
        ResetController();
        speed_mixer.ClearSource(SpeedMixer::Source::TRACK);
        return;
    }

    ProcessGrayData();
    DetectDashedLine();
    DetectFinishLine();

    float sum_weight = 0.0f;
    float sum_error = 0.0f;

    for (int i = 0; i < 8; i++) {
        float confidence = gray_state[i] ? 1.0f : 0.0f; // 白线（亮灯） = 0，黑线（灭灯） = 1
        sum_error += confidence * weights[i];
        sum_weight += confidence;
    }

    if (sum_weight < line_threshold) {
        last_status = App::Warning;
        speed_diff = 0.0f; // 重置速度差
        track_pid.Reset(); // 重置PID
        speed_mixer.SetTrackSpeed(base_speed, 0.0f);
        return;
    }
    last_status = App::Normal;

    track_error = sum_error / sum_weight;
    speed_diff = track_pid.Calc(0.0f, track_error, max_speed_diff);

    speed_mixer.SetTrackSpeed(base_speed, speed_diff);
}

void Track::SetBaseSpeed(float speed) {
    if (speed < 0)
        speed = 0;
    if (speed > 300)
        speed = 300;
    base_speed = speed;
}

App::Status Track::GetStatus() {
    return last_status;
}

void Track::ProcessGrayData() {
    gray_sensor.Update();

    for (uint8_t i = 0; i < 8; i++) {
        gray_state[i] = gray_sensor.sensor_states[i];
    }
}

void Track::DetectDashedLine() {
    // 判断中间两个传感器（黑线正中）是否都为低电平（白线/无黑线）
    bool gap_detected = (!gray_state[3] && !gray_state[4]);

    if (gap_detected) {
        // 累计空隙帧数
        if (dash_gap_counter < DASH_GAP_THRESHOLD + DASH_HOLD_FRAMES)
            dash_gap_counter++;
    } else {
        // 有黑线时衰减计数器（避免短时干扰）
        if (dash_gap_counter > 0)
            dash_gap_counter--;
    }

    // 超过阈值即判定为虚线区域，保持标志至少 DASH_HOLD_FRAMES 帧以免闪现
    if (dash_gap_counter >= DASH_GAP_THRESHOLD) {
        is_dashed_line = true;
    } else if (dash_gap_counter == 0) {
        // 计数器归零才清除虚线标志（保证连续检测到线一定时间）
        is_dashed_line = false;
    }
}

void Track::DetectFinishLine() {
    // 判断逻辑：中间四个灰度全黑
    bool middle_all_black = (gray_state[1] && gray_state[2] && gray_state[3] && gray_state[4] && gray_state[5] && gray_state[6]);
    // 增加短暂防抖：连续检测到若干帧才算有效，避免窄黑线误触发
    static uint8_t finish_cnt = 0;
    if (middle_all_black) {
        if (finish_cnt < 5)
            finish_cnt++;
    } else {
        if (finish_cnt > 0)
            finish_cnt--;
    }
    is_finish_line = (finish_cnt >= 3); // 连续3帧认为有效
}

void Track::ResetController() {
    track_pid.Reset();
    speed_diff = 0.0f;
    dash_gap_counter = 0;
    is_dashed_line = false;
    is_finish_line = false;
}
