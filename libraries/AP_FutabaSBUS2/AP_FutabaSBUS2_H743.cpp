#include "AP_FutabaSBUS2_H743.h"
#include <AP_HAL/AP_HAL.h>

#if AP_FUTABASBUS2_ENABLED
extern const AP_HAL::HAL& hal;

AP_FutabaSBUS2_H743::AP_FutabaSBUS2_H743(uint8_t uart_port)
    : _uart_port(uart_port)
{
}

void AP_FutabaSBUS2_H743::init()
{
    init_uart();
    init_timer();
}

void AP_FutabaSBUS2_H743::update()
{
    // optional periodic tasks
}

void AP_FutabaSBUS2_H743::init_uart()
{
    _uart = hal.serial(_uart_port);

    // 1. Start UART at 100000 baud
    _uart->begin(100000);

    // 2. Configure SBUS2 framing: 8E2 + inversion
    // Note: the inversion is required to be handled in hardware on H7, as the UART peripheral does not support it natively. This is a change from F7 where inversion was handled in software by the driver.
    // removing below code, TODO: add config to libraries/AP_HAL_ChibiOS/hwdef/MatekH743/hwdef.dat
    //_uart->set_options(
    //    UART_OPTION_INVERT_RX |
    //    UART_OPTION_INVERT_TX |
    //    UART_OPTION_EVEN_PARITY |
    //    UART_OPTION_TWO_STOP_BITS
    //);

    // 3. Enable DMA mode
    //_uart->set_dma_mode(true);

    // 4. Install ReceiveToIdle callback
    //_uart->set_receive_idle_callback(rx_event_callback, this);

    // 5. Provide RX buffer
    //_uart->set_rx_buffer(_rx_buffer, sizeof(_rx_buffer));
}

void AP_FutabaSBUS2_H743::rx_event_callback(AP_HAL::UARTDriver *uart, uint16_t nbytes, void *arg)
{
    ((AP_FutabaSBUS2_H743*)arg)->handle_rx(nbytes);
}

void AP_FutabaSBUS2_H743::handle_rx(uint16_t nbytes)
{
    // TODO: parse SBUS2 frame, extract footer, start timer
}

void AP_FutabaSBUS2_H743::init_timer()
{
    // TODO: configure TIM7
}

void AP_FutabaSBUS2_H743::timer_irq()
{
    // TODO: send next SBUS2 block
}

#endif
