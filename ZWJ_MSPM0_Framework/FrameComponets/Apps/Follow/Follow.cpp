#include "Follow.hpp"

Follow &follow = Follow::GetInstance();

void Follow::Start() {
    // 初始化超声波
    this->follow_ultrasonic.Init();
    this->follow_ultrasonic.Enable();

    // 注意：这里的输出限幅 speed_limit 必须是 rpm 值
    this->follow_pid.Init(5.0f, 0.2f, 0.5f, false);
    this->follow_pid.SetLimit(30.0f, 150.0f, 0.5f);
    this->follow_pid.SetDeadband(0.5f, 2.0f);
}

void Follow::Update() {
    this->real_dist = this->follow_ultrasonic.GetDistance();
    this->targ_dist = 20.0f;

    float targ_speed = this->follow_pid.Calc(targ_dist, real_dist, speed_limit);

    // motor_left.SetSpeed(targ_speed);
    // motor_right.SetSpeed(targ_speed);
}
