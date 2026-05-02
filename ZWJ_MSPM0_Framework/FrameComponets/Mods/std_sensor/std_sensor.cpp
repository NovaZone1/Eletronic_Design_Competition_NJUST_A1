#include "std_sensor.hpp"

void GpioSensor::Init(GPIO_Regs **ports, uint32_t *pins, StdSensor::TriggerPolarity *polarities)
{
    // 检验参数有效性
    if (sensor_nums == 0 || ports == nullptr || pins == nullptr || polarities == nullptr)
    {
        return; // 无效参数，直接返回
    }

    // 保存极性配置
    for (uint8_t i = 0; i < sensor_nums; i++)
    {
        this->polarities[i] = polarities[i];
    }

    // 注册每个传感器对应的GPIO实例
    for (uint8_t i = 0; i < sensor_nums; i++)
    {
        // 注册GPIO实例，暂时不使用外部中断回调函数，因此传入nullptr
        BspGpio_InstRegister(&gpio_instance[i], ports[i], pins[i]);
    }
}

void GpioSensor::Update()
{
    for (size_t i = 0; i < sensor_nums; i++)
    {
        // 读取当前引脚电平
        uint32_t pin_state = BspGpio_GetState(&gpio_instance[i]);

        bool is_active = false;
        // 根据极性配置判断传感器是否被触发
        if (polarities[i] == StdSensor::ACTIVE_HIGH)
        {
            is_active = (pin_state == BSPGPIO_HIGH_STATE);
        }
        else // ACTIVE_LOW
        {
            is_active = (pin_state == BSPGPIO_LOW_STATE);
        }

        // 更新传感器状态
        sensor_states[i] = is_active;
    }
}

bool GpioSensor::GetState(uint8_t index) const
{
    if (index >= sensor_nums)
    {
        return false; // 索引越界，返回false
    }

    return sensor_states[index];
}

uint8_t GpioSensor::GetSensorNums() const
{
    return sensor_nums;
}

// GpioSensor test_sensor(8);
// GPIO_Regs *gpio_regs[8] = {Sensor_1_PORT, Sensor_2_PORT, Sensor_3_PORT, Sensor_4_PORT,
//                            Sensor_5_PORT, Sensor_6_PORT, Sensor_7_PORT, Sensor_8_PORT};
// uint32_t gpio_pins[8] = {Sensor_1_Sensor_1_PIN_PIN, Sensor_2_Sensor_2_PIN_PIN, Sensor_3_Sensor_3_PIN_PIN,
//                          Sensor_4_Sensor_4_PIN_PIN, Sensor_5_Sensor_5_PIN_PIN, Sensor_6_Sensor_6_PIN_PIN,
//                          Sensor_7_Sensor_7_PIN_PIN, Sensor_8_Sensor_8_PIN_PIN};

// StdSensor::TriggerPolarity polarities[8] = {StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH,
//                                             StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH,
//                                             StdSensor::ACTIVE_HIGH, StdSensor::ACTIVE_HIGH};

// bool state[8] = {false, false, false, false, false, false, false, false};

