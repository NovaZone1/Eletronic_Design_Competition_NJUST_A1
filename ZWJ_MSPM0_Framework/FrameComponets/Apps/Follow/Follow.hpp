#pragma once

#include "SysDefs.hpp"
#include "System.hpp"
#include "motor_at8236.hpp"
#include "pid.hpp"
#include "ultrasonic.hpp"
#include "filter.hpp"

class Follow : public Application {
    friend class RobotSystem;

    SINGLETON(Follow) : Application("Follow") {
        prescaler = 1;
    };
    APPLICATION_OVERRIDE;

public:
    float real_dist = 0.0f;
    float targ_dist = 20.0f;
    float speed_offset = 0.0f;
    bool is_enabled = false;
    App::Status last_status = App::Normal;

    void SetEnable(bool enable);
    void SetTargetDistance(float dist);
    App::Status GetStatus() override;

private:
    Ultrasonic_Capture follow_ultrasonic;
    Pids follow_pid;

    float dist_buffer[5];
    uint8_t dist_index = 0;
    float filtered_dist = 0.0f;
    float last_filtered_dist = 0.0f;

    float speed_limit = 150.0f;
    float min_valid_dist = 5.0f;
    float max_valid_dist = 100.0f;

    bool IsDistanceValid(float dist);
    void ResetController();
};

extern Follow &follow;
