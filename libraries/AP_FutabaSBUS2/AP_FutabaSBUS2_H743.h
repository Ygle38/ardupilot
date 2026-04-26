#pragma once

#include "AP_FutabaSBUS2_Backend.h"
#include <AP_HAL/AP_HAL.h>

#if AP_FUTABASBUS2_ENABLED

class AP_FutabaSBUS2_H743 : public AP_FutabaSBUS2_Backend {
public:
    AP_FutabaSBUS2_H743(uint8_t uart_port);

    void init() override;
    void update() override;

private:
    void init_uart();
    void init_timer();

    static void rx_event_callback(AP_HAL::UARTDriver *uart, uint16_t nbytes, void *arg);
    void handle_rx(uint16_t nbytes);

    void timer_irq();   // will be called from the TIM7 ISR binding

    AP_HAL::UARTDriver *_uart = nullptr;
    uint8_t _uart_port;

    uint8_t _rx_buffer[64];
};

#endif
