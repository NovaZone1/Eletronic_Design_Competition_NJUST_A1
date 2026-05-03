#pragma once

#include "SysDefs.hpp"
#include "System.hpp"
#include "pid.hpp"
#include "std_math.hpp"

class Overtake : public Application {
    SINGLETON(Overtake) : Application("Overtake") {
        prescaler = 1;
    };
    APPLICATION_OVERRIDE;

private:
    typedef enum OvertakeStep {
        STEP_IDLE = 0,       // 空闲
        STEP_ACCELERATE = 1, // 加速
        STEP_LEFT_LANE = 2,  // 左变道
        STEP_PASS = 3,       // 直行超车
        STEP_RIGHT_LANE = 4, // 右变道
        STEP_FINISH = 5      // 完成超车
    } Step;

    Pids overtake_pid;
    uint32_t step_timer = 0; // 超车阶段计时器(Overtake App 是200Hz 运行的)

    const uint32_t ACCEL_TIME = 200;       // 加速阶段持续时间（单位：周期）
    const uint32_t LANE_CHANGE_TIME = 100; // 变道阶段持续时间（单位：周期）
    const uint32_t PASS_TIME = 300;        // 直行超车阶段持续时间（单位：周期）

    const float OVERTAKE_SPEED = 160.0f;  // 超车基础速度（单位：rpm，电机转速）
    const float TURN_SPEED_DIFF = 100.0f; // 变道速度差（单位：rpm）

    void ExecuteStep();
    void ResetStateMachine();

public:
    bool is_enabled = false;
    bool is_complete = false;
    Step current_step = STEP_IDLE;
    float left_speed_cmd = 0.0f;
    float right_speed_cmd = 0.0f;

    void SetEnable(bool enable);
    void StartOvertake();
    App::Status GetStatus() override;
};

extern Overtake &overtake_app;
