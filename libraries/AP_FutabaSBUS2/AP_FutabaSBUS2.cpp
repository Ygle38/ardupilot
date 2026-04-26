#include "AP_FutabaSBUS2.h"
#include "AP_FutabaSBUS2_H743.h"
#include <AP_HAL/AP_HAL.h>

#if AP_FUTABASBUS2_ENABLED
extern const AP_HAL::HAL& hal;

const AP_Param::GroupInfo AP_FutabaSBUS2::var_info[] = {
    AP_GROUPINFO("ENABLE", 1, AP_FutabaSBUS2, _enabled, 0),
    AP_GROUPINFO("PORT",   2, AP_FutabaSBUS2, _uart_port, 8),
    AP_GROUPEND
};

AP_FutabaSBUS2::AP_FutabaSBUS2()
{
    AP_Param::setup_object_defaults(this, var_info);
}

void AP_FutabaSBUS2::init()
{
    if (!_enabled.get()) {
        return;
    }

    // for Matek H743 → dedicated hardware backend
    _backend = new AP_FutabaSBUS2_H743(_uart_port.get());

    _backend->init();
}

void AP_FutabaSBUS2::update()
{
    if (_backend) {
        _backend->update();
    }
}
#endif
