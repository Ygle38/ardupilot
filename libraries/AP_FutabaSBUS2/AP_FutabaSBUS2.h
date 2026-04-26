#pragma once
#include <AP_Param/AP_Param.h>
#include "AP_FutabaSBUS2_config.h"
#include "AP_FutabaSBUS2_Backend.h"

#if AP_FUTABASBUS2_ENABLED
class AP_FutabaSBUS2 {
public:
    AP_FutabaSBUS2();
    static const AP_Param::GroupInfo var_info[];

    void init();
    void update();   // TODO: scheduler call implementation -or- consider making this private and using a callback from the backend

    bool enabled() const { return _enabled.get(); }

private:
    void load_parameters();

    AP_Int8 _enabled;
    AP_Int8 _uart_port;
    AP_FutabaSBUS2_Backend *_backend;
};
#endif
