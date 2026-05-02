#pragma once

#include "SysDefs.hpp"
#include "std_math.hpp"

/**
 * @brief 速度整合器：解决多个App同时设置速度的冲突
 * @note 极简设计，只做速度整合，不做硬件操作
 */
class SpeedMixer {
    SINGLETON(SpeedMixer) {};

private:
    // ========== 内部数据 ==========
    // 各个来源的速度数据
    struct {
        float base_speed = 0.0f;
        float speed_diff = 0.0f;
        bool valid = false;
    } track;

    struct {
        float speed_offset = 0.0f;
        bool valid = false;
    } follow;

    struct {
        float left_speed = 0.0f;
        float right_speed = 0.0f;
        bool valid = false;
    } overtake;

    struct {
        float left_speed = 0.0f;
        float right_speed = 0.0f;
        bool valid = false;
    } navigation;

    // 参数配置
    const float MAX_SPEED = 300.0f;

public:
    // ========== 速度来源优先级（数字越大优先级越高） ==========
    enum class Source {
        NONE = 0,
        TRACK = 1,     // 巡线（基础速度+差速）
        FOLLOW = 2,    // 跟车（速度偏移）
        OVERTAKE = 3,  // 超车（直接设置目标速度）
        NAVIGATION = 4 // 导航（直接设置目标速度，最高优先级）
    };

    // ========== 公共接口：各个App调用这些方法 ==========
    /**
     * @brief 设置巡线速度（基础速度+差速）
     * @param base_speed 基础速度(rpm)
     * @param speed_diff 速度差(rpm)
     */
    void SetTrackSpeed(float base_speed, float speed_diff);

    /**
     * @brief 设置跟车速度偏移
     * @param speed_offset 速度偏移量(rpm，叠加在基础速度上)
     */
    void SetFollowOffset(float speed_offset);

    /**
     * @brief 设置超车直接速度（高优先级）
     * @param left_speed 左电机速度(rpm)
     * @param right_speed 右电机速度(rpm)
     */
    void SetOvertakeSpeed(float left_speed, float right_speed);

    /**
     * @brief 设置导航直接速度（最高优先级）
     * @param left_speed 左电机速度(rpm)
     * @param right_speed 右电机速度(rpm)
     */
    void SetNavigationSpeed(float left_speed, float right_speed);

    /**
     * @brief 清除某个来源的速度设置
     * @param source 速度来源
     */
    void ClearSource(Source source);

    /**
     * @brief 清除所有速度设置
     */
    void ClearAll();

    // ========== 公共接口：ControlTask调用这些方法 ==========
    /**
     * @brief 获取最终左电机速度
     * @return float 速度(rpm)
     */
    float GetFinalLeftSpeed();

    /**
     * @brief 获取最终右电机速度
     * @return float 速度(rpm)
     */
    float GetFinalRightSpeed();

private:
    // ========== 内部方法 ==========
    /**
     * @brief 获取当前最高优先级的来源
     * @return Source 最高优先级来源
     */
    Source GetHighestPrioritySource();
};