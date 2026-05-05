#include "ultrasonic_irq.h"
#include <FreeRTOS.h>
#include <task.h>
#include "bsp_delay.h"

void vApplicationTickHook(void) {
    DL_GPIO_writePins(TRIG_PORT, TRIG_TRIG_PIN_PIN);
    BspDelay_us(10);
    DL_GPIO_clearPins(TRIG_PORT, TRIG_TRIG_PIN_PIN);
}