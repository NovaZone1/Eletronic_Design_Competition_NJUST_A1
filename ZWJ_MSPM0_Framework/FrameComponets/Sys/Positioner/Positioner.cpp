#include "Positioner.hpp"
#include "System.hpp"

void Positioner::Init() {
    // 目前不需要做什么初始化操作，但可以在这里添加日志或其他准备工作
    // System.monitor.LogInfo("Positioner initialized.");
}

/**
 * @brief 更新灰度传感器阵列定位源数据
 * @note
 * 至于我为什么分开更新每个定位源，主要是因为使用串口接收灰度传感器的数据时，灰度传感器发送频率太高了，如果放在一起更新的话，可能会导致串口数据接收不及时，出现数据丢失的情况，所以我把它单独放在一个任务里更新，这样就不会影响其他定位源的更新了
 */
void Positioner::_Update_GrayArray() {
    if (gray_array != nullptr && gray_array->CntFull()) {
        // 自动更新定位源状态缓存，供零开销跨库查询
        if (gray_array->IsOnline()) {
            gray_array->Update();
        }
        // else {
        //     System.monitor.LogError("Locator [%s] is offline!", gray_array->GetName());
        // }
    }
}

void Positioner::_Update_IMU() {
    if (imu != nullptr && imu->CntFull()) {
        // 自动更新定位源状态缓存，供零开销跨库查询
        if (imu->IsOnline()) {
            imu->Update();
        }
        // else {
        //     System.monitor.LogError("Locator [%s] is offline!", imu->GetName());
        // }
    }
}

void Positioner::_Update_Vision() {
    if (vision != nullptr && vision->CntFull()) {
        // 自动更新定位源状态缓存，供零开销跨库查询
        if (vision->IsOnline()) {
            vision->Update();
        }
        // else {
        //     System.monitor.LogError("Locator [%s] is offline!", vision->GetName());
        // }
    }
}

void Positioner::_Update_Odometry() {
    if (odometry != nullptr && odometry->CntFull()) {
        // 自动更新定位源状态缓存，供零开销跨库查询
        if (odometry->IsOnline()) {
            odometry->Update();
        }
        // else {
        //     System.monitor.LogError("Locator [%s] is offline!", odometry->GetName());
        // }
    }
}

/**
 * @brief 注册定位源实例
 */
bool Positioner::RegistLocator(Locator *locator) {
    if (locator == nullptr) {
        // System.monitor.LogError("Failed to register locator: null pointer!");
        return false;
    }

    switch (locator->GetType()) {
    case Locator::TYPE_GRAY_ARRAY:
        gray_array = locator;
        break;
    case Locator::TYPE_IMU:
        imu = locator;
        break;
    case Locator::TYPE_VISION:
        vision = locator;
        break;
    case Locator::TYPE_ODOMTRY:
        odometry = locator;
        break;
    default:
        // System.monitor.LogError("Failed to register locator [%s]: unknown type!", locator->GetName());
        return false;
    }

    // System.monitor.LogOK("Locator [%s] registered successfully!", locator->GetName());
    locator->Start(); // 注册后立即启动定位源

    return true;
}

bool Locator::CntFull() {
    if (++prescaler_cnt >= prescaler) {
        prescaler_cnt = 0;
        return true;
    }
    return false;
}
