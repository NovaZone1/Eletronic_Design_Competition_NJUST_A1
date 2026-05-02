#include "std_sensor.hpp"

void GpioSensor::Init(GPIO_Regs **ports, uint32_t *pins, StdSensor::TriggerPolarity *polarities) {
    if (ports == nullptr || pins == nullptr || polarities == nullptr) {
        return;
    }

    // 保存极性（原代码用指针指向外部数组，改为拷贝到内部数组更安全）
    for (uint8_t i = 0; i < 8; i++) {
        this->polarities[i] = polarities[i];
    }

    // 注册GPIO实例（现在gpio_instance是数组，访问合法）
    for (uint8_t i = 0; i < 8; i++) {
        BspGpio_InstRegister(&this->gpio_instance[i], ports[i], pins[i]);
    }
}

void GpioSensor::Update() {
    for (size_t i = 0; i < 8; i++) {
        // 读取当前引脚电平
        uint32_t pin_state = BspGpio_GetState(&gpio_instance[i]);

        bool is_active = false;
        // 根据极性配置判断传感器是否被触发
        if (polarities[i] == StdSensor::ACTIVE_HIGH) {
            is_active = (pin_state == BSPGPIO_HIGH_STATE);
        } else // ACTIVE_LOW
        {
            is_active = (pin_state == BSPGPIO_LOW_STATE);
        }

        // 更新传感器状态
        sensor_states[i] = is_active;
    }
}

bool GpioSensor::GetState(uint8_t index) const {
    if (index >= 8) {
        return false; // 索引越界，返回false
    }

    return sensor_states[index];
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
