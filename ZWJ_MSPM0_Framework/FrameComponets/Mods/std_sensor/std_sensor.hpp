#pragma once

#include "bsp_gpio.h"
#include "std_math.hpp"

// 该灰度遇到黑线灯灭，遇到白线灯亮
namespace StdSensor
{
    typedef enum
    {
        ACTIVE_HIGH,
        ACTIVE_LOW,
    } TriggerPolarity;
}

class GpioSensor
{
private:
    uint8_t sensor_nums;
    DynamicArray sensor_states;
    StdSensor::TriggerPolarity *polarities;
    BspGpio_Instance *gpio_instance;

public:
    GpioSensor(uint8_t nums) : sensor_nums(nums), sensor_states(nums)
    {
        if (nums > 0)
        {
            polarities = new StdSensor::TriggerPolarity[nums];
            gpio_instance = new BspGpio_Instance[nums];
        }
        // 状态全部初始化为 false
        for (size_t i = 0; i < nums; i++)
        {
            sensor_states[i] = false;
        }
    }
    ~GpioSensor()
    {
        // 如果传入的传感器数量大于0，则释放动态分配的内存
        if (sensor_nums > 0)
        {
            delete[] polarities;
            delete[] gpio_instance;
        }
    }

    /// @brief GPIO传感器初始化函数
    void Init(GPIO_Regs **ports, uint32_t *pins, StdSensor::TriggerPolarity *polarities);

    /// @brief GPIO传感器更新函数
    void Update();

    /// @brief 获取指定索引传感器的状态
    bool GetState(uint8_t index) const;

    /// @brief 获取传感器数量
    uint8_t GetSensorNums() const;
};
