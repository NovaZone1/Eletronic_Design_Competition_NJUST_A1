#pragma once

#include "SysDefs.hpp"
#include "std_cpp.h"
#include "std_math.hpp"
#include "std_sensor.hpp"
#include "stdint.h"
#include "string.h"

class Positioner;

/* ===================== 定位源抽象基类 ===================== */
class Locator {
    friend class Positioner;

public:
    enum Type : uint8_t {
        TYPE_GRAY_ARRAY, // 灰度传感器阵列
        TYPE_IMU,        // 惯性测量单元
        TYPE_VISION,     // 视觉模块
        TYPE_ODOMTRY,    // 里程计
    };

    enum Status : uint8_t {
        Online = 0,  // 定位源在线，数据正常
        Offline = 1, // 定位源离线，数据不可用
    };

    uint8_t prescaler = 1; // 定位源预分频
    bool CntFull();        // 监测预分频计数器是否满了

    Type GetType() const {
        return type;
    }
    const char *GetName() const {
        return name;
    }

    // [状态量] 用于向系统反馈定位源状态，影响系统对数据的使用和错误处理
    // 注意：Locator 内部不要直接修改这个变量
    Status status = Online;

private:
    Type type;
    char name[24];
    uint8_t prescaler_cnt = 0; // 预分频计数器

protected:
    Locator(Type type, const char *name) {
        this->type = type;
        strncpy(this->name, name, 23);
        this->name[23] = '\0'; // 确保字符串结尾
    }
    virtual ~Locator() = default;

    // 纯虚函数，要求子类必须实现这些方法来定义定位源的行为
    virtual void Start() = 0;          // 启动定位源
    virtual void Update() = 0;         // 更新数据
    virtual bool IsOnline() const = 0; // 定位源是否在线
};

/* ===================== 定位管理器（单例） ===================== */
/**
 * @brief 定位模块
 * @note 机器人系统将利用本模块，综合各个信息来源的数据，给出机器人的位置
 */
class Positioner {
    friend void GrayArrayCpp();
    friend class RobotSystem;

    SINGLETON(Positioner) {};

private:
    Locator *gray_array = nullptr; // 灰度传感器阵列定位源实例指针
    Locator *imu = nullptr;        // IMU定位源实例指针
    Locator *vision = nullptr;     // 视觉模块定位源实例指针
    Locator *odometry = nullptr;   // 里程计定位源实例指针

    void _Update_GrayArray();
    void _Update_IMU();
    void _Update_Vision();
    void _Update_Odometry();

public:
    /// @brief 初始化定位模块
    void Init();

    /// @brief 注册定位源实例
    bool RegistLocator(Locator *locator);

    /// @brief 查找定位源实例
    template <typename T>
    T *FindLocator();
};
