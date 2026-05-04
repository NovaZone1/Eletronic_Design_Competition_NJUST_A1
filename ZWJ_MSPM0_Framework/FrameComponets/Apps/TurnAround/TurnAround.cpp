#include "TurnAround.hpp"
#include "SpeedMixer.hpp"

TurnAround &turn_around_app = TurnAround::GetInstance();

void TurnAround::Start() {
    // 无需额外初始化，所有参数已在类内定义
}

void TurnAround::Update() {
    if (!is_enabled) {
        speed_mixer.ClearSource(SpeedMixer::Source::TURN_AROUND);
        first_enter = true;
        frame_counter = 0;
        is_complete = false;
        return;
    }

    // 首次进入掉头状态，初始化计时/计数
    if (first_enter) {
        first_enter = false;
        frame_counter = 0;
        is_complete = false;
    }

    // 检查是否已完成
    if (frame_counter >= TOTAL_FRAMES) {
        // 停止电机
        speed_mixer.SetTurnAroundSpeed(0.0f, 0.0f);
        is_complete = true;
        return;
    }

    // 执行原地旋转：左轮正转，右轮反转（根据实际接线调整正负号）
    speed_mixer.SetTurnAroundSpeed(ROTATE_SPEED, -ROTATE_SPEED);
    frame_counter++;
}

void TurnAround::SetEnable(bool enable) {
    if (!enable) {
        speed_mixer.ClearSource(SpeedMixer::Source::TURN_AROUND);
    }
    is_enabled = enable;
}

App::Status TurnAround::GetStatus() {
    return App::Normal;
}