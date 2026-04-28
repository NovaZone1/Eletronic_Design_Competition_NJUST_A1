#include "bsp_dwt.h"
#include "FreeRTOS.h"
#include "task.h"

static BspDwt_TimeType SysTime;
static uint32_t CPU_FREQ_Hz;

// 完全基于FreeRTOS Tick，100%可靠
void BspDwt_Init(uint32_t CPU_Freq_MHz) {
    (void) CPU_Freq_MHz;
    CPU_FREQ_Hz = 80000000;
}

void BspDwt_CntUpdate(void) {
    // 空函数，保留兼容
}

void BspDwt_SysTimeUpdate(void) {
    TickType_t ticks = xTaskGetTickCount();
    uint32_t ms = ticks * portTICK_PERIOD_MS;

    SysTime.s = ms / 1000;
    SysTime.ms = ms % 1000;
    SysTime.us = 0;
}

float BspDwt_GetTimeline_Sec(void) {
    BspDwt_SysTimeUpdate();
    return (float) SysTime.s + (float) SysTime.ms * 0.001f;
}

float BspDwt_GetTimeline_MSec(void) {
    BspDwt_SysTimeUpdate();
    return (float) SysTime.s * 1000.0f + (float) SysTime.ms;
}

uint64_t BspDwt_GetTimeline_USec(void) {
    BspDwt_SysTimeUpdate();
    return (uint64_t) SysTime.s * 1000000ULL + (uint64_t) SysTime.ms * 1000ULL;
}

// 关键修复：现在真的能计算DeltaTime了！
float BspDwt_GetDeltaTime(uint32_t *cnt_last) {
    TickType_t current_tick = xTaskGetTickCount();
    TickType_t delta_tick = current_tick - *cnt_last;

    // 更新上一次的Tick
    *cnt_last = current_tick;

    // 转换为秒（Tick数 * Tick周期(ms) / 1000）
    return (float) delta_tick * (float) portTICK_PERIOD_MS / 1000.0f;
}

// 64位版本也修复了
double BspDwt_GetDeltaTime64(uint32_t *cnt_last) {
    TickType_t current_tick = xTaskGetTickCount();
    TickType_t delta_tick = current_tick - *cnt_last;

    *cnt_last = current_tick;

    return (double) delta_tick * (double) portTICK_PERIOD_MS / 1000.0;
}

void BspDwt_Delay(float Delay) {
    uint32_t ms = (uint32_t) (Delay * 1000.0f);
    if (ms > 0) {
        vTaskDelay(pdMS_TO_TICKS(ms));
    }
}