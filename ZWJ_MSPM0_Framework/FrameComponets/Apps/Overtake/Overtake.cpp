#include "Overtake.hpp"
#include "SpeedMixer.hpp"

Overtake &overtake = Overtake::GetInstance();

void Overtake::Start() {
    overtake_pid.Init(15.0f, 1.0f, 3.0f, false);
    overtake_pid.SetLimit(30.0f, 150.0f, 0.8f);
}

void Overtake::Update() {
    if (!is_enabled)
        return;
    ExecuteStep();
}

void Overtake::SetEnable(bool enable) {
    if (enable && !is_enabled) {
        ResetStateMachine();
    }
    is_enabled = enable;
}

void Overtake::StartOvertake() {
    if (is_enabled && current_step == STEP_IDLE) {
        current_step = STEP_ACCELERATE;
        step_timer = 0;
        is_complete = false;
    }
}

App::Status Overtake::GetStatus() {
    return App::Normal;
}

// 核心状态机函数，要把这个函数注册到状态机中
void Overtake::ExecuteStep() {
    switch (current_step) {
    case STEP_IDLE:
        left_speed_cmd = 0.0f;
        right_speed_cmd = 0.0f;
        break;

    case STEP_ACCELERATE:
        left_speed_cmd = OVERTAKE_SPEED;
        right_speed_cmd = OVERTAKE_SPEED;
        step_timer++;
        if (step_timer >= ACCEL_TIME) {
            current_step = STEP_LEFT_LANE;
            step_timer = 0;
        }
        break;

    case STEP_LEFT_LANE:
        left_speed_cmd = OVERTAKE_SPEED - TURN_SPEED_DIFF;
        right_speed_cmd = OVERTAKE_SPEED + TURN_SPEED_DIFF;
        step_timer++;
        if (step_timer >= LANE_CHANGE_TIME) {
            current_step = STEP_PASS;
            step_timer = 0;
        }
        break;

    case STEP_PASS:
        left_speed_cmd = OVERTAKE_SPEED;
        right_speed_cmd = OVERTAKE_SPEED;
        step_timer++;
        if (step_timer >= PASS_TIME) {
            current_step = STEP_RIGHT_LANE;
            step_timer = 0;
        }
        break;

    case STEP_RIGHT_LANE:
        left_speed_cmd = OVERTAKE_SPEED + TURN_SPEED_DIFF;
        right_speed_cmd = OVERTAKE_SPEED - TURN_SPEED_DIFF;
        step_timer++;
        if (step_timer >= LANE_CHANGE_TIME) {
            current_step = STEP_FINISH;
            step_timer = 0;
        }
        break;

    case STEP_FINISH:
        left_speed_cmd = 0.0f;
        right_speed_cmd = 0.0f;
        is_complete = true;
        break;
    }

    speed_mixer.SetOvertakeSpeed(left_speed_cmd, right_speed_cmd);
}

void Overtake::ResetStateMachine() {
    current_step = STEP_IDLE;
    step_timer = 0;
    is_complete = false;
    left_speed_cmd = 0.0f;
    right_speed_cmd = 0.0f;
    overtake_pid.Reset();
}
