#pragma once

#include "AP_FutabaSBUS2_config.h"

#if AP_FUTABASBUS2_ENABLED
class AP_FutabaSBUS2_Backend {
public:
    virtual ~AP_FutabaSBUS2_Backend() {}

    virtual void init() = 0;
    virtual void update() = 0;

protected:
    AP_FutabaSBUS2_Backend() {}
};
#endif
