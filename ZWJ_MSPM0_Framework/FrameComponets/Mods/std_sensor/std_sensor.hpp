#pragma once

#include "bsp_gpio.h"
#include "std_math.hpp"

// 该灰度遇到黑线灯灭，遇到白线灯亮
namespace StdSensor {
    typedef enum {
        ACTIVE_HIGH,
        ACTIVE_LOW,
    } TriggerPolarity;
}

class GpioSensor {
    friend class Track;

private:
    bool sensor_states[8];
    StdSensor::TriggerPolarity polarities[8]; // 补充：原polarities也是指针，建议改为数组
    BspGpio_Instance gpio_instance[8];        // 改为数组，存储8个GPIO实例

public:
    /// @brief GPIO传感器初始化函数
    void Init(GPIO_Regs **ports, uint32_t *pins, StdSensor::TriggerPolarity *polarities);

    /// @brief GPIO传感器更新函数
    void Update();

    /// @brief 获取指定索引传感器的状态
    bool GetState(uint8_t index) const;
};
