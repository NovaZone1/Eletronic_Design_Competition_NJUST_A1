#pragma once

#include "Positioner.hpp"
#include "SysDefs.hpp"
#include "System.hpp"
#include "pid.hpp"
#include "std_math.hpp"

class Navigation : public Application {
    friend class RobotSystem;
    SINGLETON(Navigation) : Application("Navigation") {
        prescaler = 1;
    };
    APPLICATION_OVERRIDE;

public:
    bool is_enabled = false;
    bool is_complete = false;

    Vec2 target_pos{0.0f, 0.0f};
    Vec2 current_pos{0.0f, 0.0f};

    float left_speed_cmd = 0.0f;
    float right_speed_cmd = 0.0f;

    void SetEnable(bool enable);
    void SetTarget(float x, float y);

private:
};

extern Navigation &navigation_app;