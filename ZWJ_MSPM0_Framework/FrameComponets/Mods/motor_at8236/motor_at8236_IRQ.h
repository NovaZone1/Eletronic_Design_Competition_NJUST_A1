#ifndef __MOTOR_AT8236_IRQ__
#define __MOTOR_AT8236_IRQ__

#ifdef __cplusplus
extern "C" {
#endif

#include "ti_msp_dl_config.h"
#include <stdint.h>

// typedef void (*Motor_EncoderISR)();
// typedef void (*Motor_SpeedUpdateISR)();

// typedef struct {
//     Motor_EncoderISR EncoderISR;         // 编码器脉冲计数回调函数
//     Motor_SpeedUpdateISR SpeedUpdateISR; // 编码器速度计算回调函数
// } Motor_Instance;

// void IRQRegister(Motor_Instance *inst, Motor_EncoderISR encoder_callback,
//                  Motor_SpeedUpdateISR speedupdate_callback);
extern void EncoderISR(void);
extern void SpeedUpdateISR(void);

#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_AT8236_IRQ__ */
