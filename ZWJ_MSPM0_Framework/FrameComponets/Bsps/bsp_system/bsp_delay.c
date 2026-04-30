#include "bsp_delay.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ti_msp_dl_config.h"
#include "core_cm0plus.h"

#define DELAY_TIM_INST   TIMA1
#define TIM_16BIT_MAX    0xFFFF

// 80MHz 主频：1us = 80 个时钟周期
#define US_TO_CYCLES(us) ((us) * 80UL)

// 定时器溢出计数（仅忙等延时使用）
static volatile uint32_t tim_overflow_count = 0;

// TIMA1 中断服务函数
void TIMA1_IRQHandler(void)
{
    if(DL_Timer_getRawInterruptStatus(DELAY_TIM_INST, DL_TIMER_INTERRUPT_ZERO_EVENT))
    {
        DL_Timer_clearInterruptStatus(DELAY_TIM_INST, DL_TIMER_INTERRUPT_ZERO_EVENT);
        tim_overflow_count++;
    }
}

// 初始化 TIMA1 与中断（自动执行）
static void TIMA1_Delay_Init(void)
{
    tim_overflow_count = 0;
    DL_Timer_setTimerCount(DELAY_TIM_INST, 0);
    DL_Timer_clearInterruptStatus(DELAY_TIM_INST, DL_TIMER_INTERRUPT_ZERO_EVENT);
    DL_Timer_enableInterrupt(DELAY_TIM_INST, DL_TIMER_INTERRUPT_ZERO_EVENT);

    NVIC_EnableIRQ(TIMA1_INT_IRQn);
    NVIC_SetPriority(TIMA1_INT_IRQn, 0);
}

// 读取当前总周期（防溢出）
static inline uint64_t GetTotalCycles(void)
{
    uint32_t cnt, overflow;
    do {
        overflow = tim_overflow_count;
        cnt = DELAY_TIM_INST->COUNTERREGS.CTR;
    } while(overflow != tim_overflow_count);

    return (uint64_t)overflow * (TIM_16BIT_MAX + 1) + cnt;
}

// 微秒级忙等延时（核心，支持任意长度）
static void DelayUs_BusyWait(uint32_t us)
{
    if(us == 0) return;

    static bool init_flag = false;
    if(!init_flag)
    {
        TIMA1_Delay_Init();
        init_flag = true;
    }

    uint64_t target = US_TO_CYCLES(us);
    uint64_t start  = GetTotalCycles();

    while(GetTotalCycles() - start < target);
}

// ===================== 对外接口 =====================
// 微秒延时（FreeRTOS中可直接调用）
void BspDelay_us(uint32_t us)
{
    DelayUs_BusyWait(us);
}

// 毫秒延时（自动适配RTOS）
void BspDelay_ms(uint32_t ms)
{
    if(ms == 0) return;

    // 小于10ms 或 RTOS未启动 → 硬件微秒延时
    if(xTaskGetSchedulerState() == taskSCHEDULER_NOT_STARTED || ms <= 10)
    {
        DelayUs_BusyWait(ms * 1000);
    }
    // 大于10ms → RTOS延时（不占CPU）
    else
    {
        vTaskDelay(pdMS_TO_TICKS(ms));
    }
}