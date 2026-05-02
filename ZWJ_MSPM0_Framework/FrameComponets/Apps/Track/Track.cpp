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

Track &track = Track::GetInstance();

void Track::Start() {
    gray_sensor.Init(gray_regs, gray_pins, polarities);

    for (int i = 0; i < 8; i++) {
        gray_state[i] = false;
    }

    track_pid.Init(18.0f, 2.5f, 6.0f, false);
    track_pid.SetLimit(60.0f, max_speed_diff, 0.85f);
    track_pid.SetDeadband(0.08f, 0.2f);
}

void Track::Update() {
    if (!is_enabled) {
        ResetController();
        return;
    }

    ProcessGrayData();
    DetectDashedLine();

    float sum_weight = 0.0f;
    float sum_error = 0.0f;
    for (int i = 0; i < 8; i++) {
        float confidence = gray_state[i];
        sum_error += confidence * weights[i];
        sum_weight += confidence;
    }

    if (sum_weight < line_threshold) {
        last_status = App::Warning;
        speed_diff = 0.0f; // 重置速度差
        track_pid.Reset(); // 重置PID
        return;
    }
    last_status = App::Normal;

    track_error = sum_error / sum_weight;
    speed_diff = track_pid.Calc(0.0f, track_error, max_speed_diff);

    speed_mixer.SetTrackSpeed(base_speed, speed_diff);
}

void Track::SetEnable(bool enable) {
    if (enable && !is_enabled) {
        ResetController();
    }
    is_enabled = enable;
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
    bool middle_dark = (gray_state[3] > 0.6f && gray_state[4] > 0.6f);
    bool side_light = (gray_state[0] < 0.3f && gray_state[7] < 0.3f);

    if (middle_dark && side_light) {
        dash_detect_cnt++;
        if (dash_detect_cnt > DASH_DETECT_THRESH) {
            dash_detect_cnt = DASH_DETECT_THRESH;
            is_dashed_line = true;
        }
    } else {
        if (dash_detect_cnt > 0)
            dash_detect_cnt--;
        if (dash_detect_cnt < DASH_RELEASE_THRESH) {
            is_dashed_line = false;
        }
    }
}

void Track::ResetController() {
    track_pid.Reset();
    speed_diff = 0.0f;
    dash_detect_cnt = 0;
    is_dashed_line = false;
}
