#pragma once

#include "SysDefs.hpp"
#include "System.hpp"
#include "motor_at8236.hpp"
#include "pid.hpp"
#include "ultrasonic.hpp"

class Follow : public Application {
    friend class RobotSystem;

    SINGLETON(Follow) : Application("Follow") {};
    APPLICATION_OVERRIDE;

private:
    Ultrasonic_Capture follow_ultrasonic;
    Pids follow_pid;

    float speed_limit = 200;
    float targ_dist = 0.0f;
    float real_dist = 0.0f;

public:
};

extern Follow &follow;
