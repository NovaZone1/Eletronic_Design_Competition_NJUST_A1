#ifndef __BSP_DWT_H__
#define __BSP_DWT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "ti_msp_dl_config.h"

#define CPU_HERT_F407_MHZ 168
#define CPU_HERT_MSPM0_MHZ 80

typedef struct {
    uint32_t s;
    uint16_t ms;
    uint16_t us;
} BspDwt_TimeType;

#define TIME_ELAPSE(dt, code)                                                                                          \
    do {                                                                                                               \
        float tstart = BspDwt_GetTimeline_Sec();                                                                       \
        code;                                                                                                          \
        dt = BspDwt_GetTimeline_Sec() - tstart;                                                                        \
    } while (0)

void BspDwt_Init(uint32_t CPU_Freq_MHz);
float BspDwt_GetDeltaTime(uint32_t *cnt_last);
double BspDwt_GetDeltaTime64(uint32_t *cnt_last);
float BspDwt_GetTimeline_Sec(void);
float BspDwt_GetTimeline_MSec(void);
uint64_t BspDwt_GetTimeline_USec(void);
void BspDwt_Delay(float Delay);
void BspDwt_SysTimeUpdate(void);
void BspDwt_CntUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* __BSP_DWT_H__ */