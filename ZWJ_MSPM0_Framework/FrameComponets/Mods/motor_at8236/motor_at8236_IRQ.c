#include "motor_at8236_IRQ.h"

#define Motor_MAX_CANINSTS 2
// 限制注册实例变量
// Motor_Instance *motor_irq[Motor_MAX_CANINSTS] = {NULL};
// uint8_t motor_irq_count = 0;

// void IRQRegister(Motor_Instance *inst, Motor_EncoderISR encoder_callback, Motor_SpeedUpdateISR speedupdate_callback) {
//     inst->EncoderISR = encoder_callback;
//     inst->SpeedUpdateISR = speedupdate_callback;

//     motor_irq[motor_irq_count++] = inst;
// }

/**
 * @brief 使用二倍频的中断函数
 * @note 需要使能
 */

// void GROUP1_IRQHandler(void) {
//     for (uint8_t i = 0; i < motor_irq_count; i++) {
//         Motor_Instance *inst = motor_irq[i];
//         inst->EncoderISR();
//     }
// }

void GROUP1_IRQHandler(void) {
    EncoderISR();   // 只调用一次，内部已遍历所有电机
}

/**
 * @brief 定时器归零中断，设置10ms自动触发来计算两个轮子的速度
 * @note  请填写对应的定时器
 */
// void TIMG6_IRQHandler(void) {
//     for (uint8_t i = 0; i < motor_irq_count; i++) {
//         Motor_Instance *inst = motor_irq[i];
//         inst->SpeedUpdateISR();
//     }
//     DL_Timer_clearInterruptStatus(TIMG6, DL_TIMER_IIDX_ZERO);
// }

void TIMG6_IRQHandler(void) {
    SpeedUpdateISR();
}
