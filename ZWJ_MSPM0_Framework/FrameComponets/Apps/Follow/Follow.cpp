#include "Follow.hpp"
#include "SpeedMixer.hpp"

Follow &follow_app = Follow::GetInstance();

void Follow::Start() {
    this->follow_ultrasonic.Init();
    this->follow_ultrasonic.Enable();

    for (int i = 0; i < 5; i++) {
        dist_buffer[i] = -1.0f;
    }

    // 注意：这里的输出限幅 speed_limit 必须是 rpm 值
    this->follow_pid.Init(5.0f, 0.2f, 0.5f, false);
    this->follow_pid.SetLimit(30.0f, speed_limit, 0.5f);
    this->follow_pid.SetDeadband(1.0f, 3.0f);
}

void Follow::Update() {
    if (!is_enabled) {
        ResetController();
        speed_mixer.ClearSource(SpeedMixer::Source::FOLLOW);
        return;
    }

    float raw_dist = follow_ultrasonic.GetDistance();

    if (!IsDistanceValid(raw_dist)) {
        last_status = App::Warning;
        speed_mixer.SetFollowOffset(0.0f); // 清除跟车影响
        return;
    }
    last_status = App::Normal;

    float median_dist = Filter::Median(dist_buffer, raw_dist, 5, dist_index);
    filtered_dist = Filter::FirstOrderComplementary(median_dist, last_filtered_dist, 0.4f);
    last_filtered_dist = filtered_dist;
    real_dist = filtered_dist;

    speed_offset = follow_pid.Calc(targ_dist, real_dist, speed_limit);
    speed_mixer.SetFollowOffset(speed_offset);
}

void Follow::SetEnable(bool enable) {
    if (enable && !is_enabled) {
        ResetController();
    }

    is_enabled = enable;

    if (!enable) {
        speed_mixer.ClearSource(SpeedMixer::Source::FOLLOW);
    }
}

void Follow::SetTargetDistance(float dist) {
    if (dist < 10.0f)
        dist = 10.0f;
    if (dist > 50.0f)
        dist = 50.0f;
    targ_dist = dist;
}

App::Status Follow::GetStatus() {
    return last_status;
}

bool Follow::IsDistanceValid(float dist) {
    return (dist >= min_valid_dist && dist <= max_valid_dist);
}

void Follow::ResetController() {
    follow_pid.Reset();
    speed_offset = 0.0f;
}
