#pragma once

#include "SysDefs.hpp"
#include "System.hpp"
#include "filter.hpp"
#include "pid.hpp"
#include "std_math.hpp"
#include "std_sensor.hpp"

class Track : public Application {
    SINGLETON(Track) : Application("Track") {
        prescaler = 1;
    };
    APPLICATION_OVERRIDE;

public:
    float track_error = 0.0f;
    float speed_diff = 0.0f;
    float base_speed = 120.0f; // 电机基础速度

    bool is_dashed_line = false; // 是否处于虚线
    bool is_enabled = true;
    App::Status last_status = App::Normal;

    void SetEnable(bool enable);
    void SetBaseSpeed(float speed);
    App::Status GetStatus() override;

private:
    GpioSensor gray_sensor;
    Pids track_pid;

    const float weights[8] = {-3.0f, -2.0f, -1.0f, -0.3f, 0.3f, 1.0f, 2.0f, 3.0f}; // 先用着，后面再调
    bool gray_state[8];

    float max_speed_diff = 150.0f;
    float line_threshold = 0.3f; // 巡线灵敏度   数值太大：容易丢线；数值太小：容易误判、抖动

    // 虚线检测防抖计数器
    uint8_t dash_detect_cnt = 0;           // 虚线检测计数器
    const uint8_t DASH_DETECT_THRESH = 15; // 虚线触发阈值
    const uint8_t DASH_RELEASE_THRESH = 5; // 虚线释放阈值

    void ProcessGrayData();  // 处理灰度数据
    void DetectDashedLine(); // 识别虚线
    void ResetController();  // 重置控制器
};

extern Track &track;