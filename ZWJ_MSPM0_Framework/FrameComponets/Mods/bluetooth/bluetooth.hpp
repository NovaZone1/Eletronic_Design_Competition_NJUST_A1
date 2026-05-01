#pragma once

#include "bsp_uart.h"
#include "ti_msp_dl_config.h"

void BlueTooth_RxCallback(UART_Regs *uart_regs, uint8_t *rx_data, uint16_t rx_size);

class BlueTooth {
    friend void BlueTooth_RxCallback(UART_Regs *uart_regs, uint8_t *rx_data, uint16_t rx_size);

private:
    BspUart_Instance uart_inst;

    uint8_t rx_buf[64];
    // uint16_t rx_len;

    bool initialize = false;
    bool enabled = false;
    bool tx_occupied = false;
    bool rx_completed = false;

public:
    void Init(UART_Regs *uart_regs);

    void Enable();
    void Disable();

    void SendMsg(uint8_t *data, uint16_t data_len);
    bool Decoder(uint8_t *decoded_data, uint16_t data_len);
};
