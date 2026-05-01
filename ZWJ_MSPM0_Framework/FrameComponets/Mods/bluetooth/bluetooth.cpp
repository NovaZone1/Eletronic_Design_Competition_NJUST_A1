#include "bluetooth.hpp"
#include <string.h>

#define BLUETOOTH_IRQ BlueTooth_INST_INT_IRQN

static BlueTooth *bluetooth_insts[BSPUART_MAX_CANINSTS] = {nullptr};
static uint8_t bluetooth_insts_count = 0;

void BlueTooth::Init(UART_Regs *uart_regs) {
    if (uart_regs == NULL) {
        return;
    }

    BspUart_InstRegister(&this->uart_inst, uart_regs, BspUart_Type_DMA, BspUart_Type_DMA, 64, BlueTooth_RxCallback);
    BspUart_ConfigDMA(&this->uart_inst, DMA, BlueTooth_RX_DMA_CH_CHAN_ID, BlueTooth_TX_DMA_CH_CHAN_ID,
                      (uint32_t) (&this->uart_inst.uart_regs->RXDATA), (uint32_t) this->rx_buf);

    bluetooth_insts[bluetooth_insts_count++] = this;
    this->initialize = true;
}

void BlueTooth::Enable() {
    NVIC_EnableIRQ(BLUETOOTH_IRQ);
    this->enabled = true;
}

void BlueTooth::Disable() {
    NVIC_DisableIRQ(BLUETOOTH_IRQ);
    this->enabled = false;
}

void BlueTooth::SendMsg(uint8_t *data, uint16_t data_len) {
    if (!initialize || !enabled || data == NULL || data_len == 0 || tx_occupied) {
        return;
    }

    this->tx_occupied = true;
    BspUart_Transmit(uart_inst, data, data_len);
    this->tx_occupied = false;
}

bool BlueTooth::Decoder(uint8_t *decoded_data, uint16_t data_len) {
    if (decoded_data == nullptr) {
        return false;
    }

    // uint16_t copy_len = (data_len > sizeof(rx_buf)) ? sizeof(rx_buf) : data_len;
    // memcpy(this->rx_buf, decoded_data, copy_len);
    // this->rx_len = copy_len;

    return true;
}

void BlueTooth_RxCallback(UART_Regs *uart_regs, uint8_t *rx_data, uint16_t rx_size) {
    for (uint8_t i = 0; i < bluetooth_insts_count; i++) {
        BlueTooth &bluetooth = *bluetooth_insts[i];
        if (bluetooth.uart_inst.uart_regs == uart_regs) {
            bluetooth.rx_completed = true;
            if (bluetooth.Decoder(rx_data, rx_size)) {
                bluetooth.rx_completed = false;
            }
        }
    }
}
