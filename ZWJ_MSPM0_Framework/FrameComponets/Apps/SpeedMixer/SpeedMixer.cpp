#include "SpeedMixer.hpp"

SpeedMixer &speed_mixer = SpeedMixer::GetInstance();

// ========== App调用的设置方法 ==========
void SpeedMixer::SetTrackSpeed(float base_speed, float speed_diff) {
    track.base_speed = base_speed;
    track.speed_diff = speed_diff;
    track.valid = true;
}

void SpeedMixer::SetFollowOffset(float speed_offset) {
    follow.speed_offset = speed_offset;
    follow.valid = true;
}

void SpeedMixer::SetOvertakeSpeed(float left_speed, float right_speed) {
    overtake.left_speed = left_speed;
    overtake.right_speed = right_speed;
    overtake.valid = true;
}

void SpeedMixer::SetNavigationSpeed(float left_speed, float right_speed) {
    navigation.left_speed = left_speed;
    navigation.right_speed = right_speed;
    navigation.valid = true;
}

void SpeedMixer::ClearSource(Source source) {
    switch (source) {
    case Source::TRACK:
        track.valid = false;
        break;
    case Source::FOLLOW:
        follow.valid = false;
        break;
    case Source::OVERTAKE:
        overtake.valid = false;
        break;
    case Source::NAVIGATION:
        navigation.valid = false;
        break;
    default:
        break;
    }
}

void SpeedMixer::ClearAll() {
    track.valid = false;
    follow.valid = false;
    overtake.valid = false;
    navigation.valid = false;
}

// ========== ControlTask调用的获取方法 ==========
float SpeedMixer::GetFinalLeftSpeed() {
    Source highest = GetHighestPrioritySource();
    float left = 0.0f;

    switch (highest) {
    case Source::NAVIGATION:
        left = navigation.left_speed;
        break;
    case Source::OVERTAKE:
        left = overtake.left_speed;
        break;
    case Source::FOLLOW:
    case Source::TRACK:
        // 巡线+跟车模式：基础速度 + 差速 + 跟车偏移
        left = track.base_speed + track.speed_diff;
        if (follow.valid) {
            left += follow.speed_offset;
        }
        break;
    default:
        left = 0.0f;
        break;
    }

    // 限幅保护
    return StdMath::fclamp(left, -MAX_SPEED, MAX_SPEED);
}

float SpeedMixer::GetFinalRightSpeed() {
    Source highest = GetHighestPrioritySource();
    float right = 0.0f;

    switch (highest) {
    case Source::NAVIGATION:
        right = navigation.right_speed;
        break;
    case Source::OVERTAKE:
        right = overtake.right_speed;
        break;
    case Source::FOLLOW:
    case Source::TRACK:
        // 巡线+跟车模式：基础速度 - 差速 + 跟车偏移
        right = track.base_speed - track.speed_diff;
        if (follow.valid) {
            right += follow.speed_offset;
        }
        break;
    default:
        right = 0.0f;
        break;
    }

    // 限幅保护
    return StdMath::fclamp(right, -MAX_SPEED, MAX_SPEED);
}

// ========== 内部方法 ==========
SpeedMixer::Source SpeedMixer::GetHighestPrioritySource() {
    // 从高到低检查优先级
    if (navigation.valid)
        return Source::NAVIGATION;
    if (overtake.valid)
        return Source::OVERTAKE;
    if (follow.valid)
        return Source::FOLLOW;
    if (track.valid)
        return Source::TRACK;
    return Source::NONE;
}
