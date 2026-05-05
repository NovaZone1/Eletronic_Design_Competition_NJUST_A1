#include "TurnAround.hpp"
#include "SpeedMixer.hpp"
#include "Track.hpp"          // 新增：访问 track_app

TurnAround &turn_around_app = TurnAround::GetInstance();

void TurnAround::Start() {
    // 无需额外初始化
}

void TurnAround::Update() {
    if (!is_enabled) {
        speed_mixer.ClearSource(SpeedMixer::Source::TURN_AROUND);
        first_enter = true;
        frame_counter = 0;
        is_complete = false;
        return;
    }

    if (first_enter) {
        first_enter = false;
        frame_counter = 0;
        is_complete = false;
    }

    // 1. 灰度检测：0号传感器踩到黑线 → 立即完成掉头
    if (track_app.GetGrayState(0) && !track_app.GetGrayState(5) && !track_app.GetGrayState(6) && !track_app.GetGrayState(7)) {
        speed_mixer.SetTurnAroundSpeed(0.0f, 0.0f);
        is_complete = true;
        return;
    }

    // 2. 时间兜底：超过 TOTAL_FRAMES 仍未检测到黑线，也停止
    if (frame_counter >= TOTAL_FRAMES) {
        speed_mixer.SetTurnAroundSpeed(0.0f, 0.0f);
        is_complete = true;
        return;
    }

    // 3. 执行原地旋转（左轮正转，右轮反转，可据实际调整符号）
    speed_mixer.SetTurnAroundSpeed(ROTATE_SPEED, -ROTATE_SPEED);
    frame_counter++;
}

App::Status TurnAround::GetStatus() {
    return App::Normal;
}