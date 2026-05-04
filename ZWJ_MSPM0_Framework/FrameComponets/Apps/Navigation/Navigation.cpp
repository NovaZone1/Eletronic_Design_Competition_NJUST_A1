#include "Navigation.hpp"
//长度单位为mm，角度单位为°
Navigation &navigation_app = Navigation::GetInstance();

void Navigation::Start() {
    // mpu6050初始化及校准
    Sensor_calibration();
    // bluetooth初始化
    this->bluetooth.Init(UART1);
    this->bluetooth.Enable();
    // pid初始化
    yaw_pid.Init(2.5f, 0.1f, 0.08f, false);
    yaw_pid.SetLimit(5.0f, 80.0f, 0.9f);
}

void Navigation::Update() {
    if (!is_enabled)
        return;
    ExecuteStep();
}

void Navigation::SetEnable(bool enable) {
    if (enable && !is_enabled) {
        ResetStateMachine();
    }
    is_enabled = enable;
}

void Navigation::Sensor_calibration() {
    // mpu6050初始化及校准
    MPU6050_Init();
    MPU6050Gyro_calibrate();
}

void Navigation::Heading_correction() {
    if (fabs(current_angle - target_angle) <= 3) {
        // 控制左电机旋转，右电机不转
    }
}

// 可以保持和角度更新的频率一样，2ms
void Navigation::odometry_update() {
    // PULSE_TO_MM 0.2617f 每一个脉冲的距离
    // WHEEL_BASE 156.5f   轮距（实际测量，单位mm）
    // 读取左右轮脉冲数
    // int32_t pulse_left
    // int32_t pulse_right

    // 计算左右轮位移
    // this->s_left = pulse_left * 0.2617f;
    // this->s_right = pulse_right * 0.2617f;

    // 差速模型计算位移和航向变化
    float s_avg = (s_left + s_right) / 2.0f;
    float delta_theta = (s_left - s_right) / 156.5f / 3.1415926f * 180.0f;
    current_angle += delta_theta;
    // 更新全局坐标
    current_pos.x += s_avg * sinf(current_angle * 3.1415926f / 180.0f);
    current_pos.y += s_avg * cosf(current_angle * 3.1415926f / 180.0f);
}
// 10ms一次
void Navigation::Navigation_Control() {
    odometry_update();
    float error_theta = target_angle - current_angle;
    // if (error_theta > 180)  error_theta -= 2 * PI;
    // if (error_theta < -PI) error_theta += 2 * PI;

    float delta_v = yaw_pid.Calc(0.0f, error_theta, 80);

    float left_speed_cmd = BASE_SPEED + delta_v;
    float right_speed_cmd = BASE_SPEED - delta_v;

    // 限幅：防止速度为负（禁止原地转向或倒车）
    left_speed_cmd = fmaxf(left_speed_cmd, 60.0f); // 最小速度待定，保证前进
    right_speed_cmd = fmaxf(right_speed_cmd, 60.0f);

    /*
    //如果不用pid
    speed_mixer.SetNavigationSpeed(left_speed_cmd, right_speed_cmd);//用基础速度或者慢一点的速度，让车走直线
    */

    speed_mixer.SetNavigationSpeed(left_speed_cmd, right_speed_cmd);
}

void Navigation::ExecuteStep() {
    switch (current_step) {
    case STEP_IDLE:
        if (this->bluetooth.rx_buf[0] == 0XFF) {
            current_step = STEP_RecieveCmd;
        }
        break;

    case STEP_RecieveCmd:
        if ((this->bluetooth.rx_buf[1] != 0) && (this->bluetooth.rx_buf[2] != 0)) {
            target_pos.x = this->bluetooth.rx_buf[1];
            target_pos.y = this->bluetooth.rx_buf[2];
            // 解析十六进制数，要加一个坐标和实际距离的换算
        }
        if ((target_pos.x != 0) && (target_pos.y != 0)) {
            this->target_angle = target_pos.Angle();
            current_step = STEP_StartNavi;
        }
        Heading_correction();
        break;

    case STEP_StartNavi:
        Navigation_Control();
        if ((fabs(current_pos.x - target_pos.x) <= 500) && (fabs(current_pos.y - target_pos.y) <= 500)) {
            current_step = STEP_FinishNavi;
        }
        break;

    case STEP_FinishNavi:
        left_speed_cmd = 0.0f;
        right_speed_cmd = 0.0f;
        speed_mixer.SetNavigationSpeed(left_speed_cmd,right_speed_cmd);
        is_complete = true;
        break;
    }
}

void Navigation::ResetStateMachine() {
    current_step = STEP_IDLE;
    is_complete = false;
    left_speed_cmd = 0.0f;
    right_speed_cmd = 0.0f;
    yaw_pid.Reset();
}