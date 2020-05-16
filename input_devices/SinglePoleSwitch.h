#pragma once

#include "InputDevice.h"

class SinglePoleSwitch : public InputDevice
{
public:
    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;
    SinglePoleSwitch(int);
    ~SinglePoleSwitch() override;
    bool debounce();
};