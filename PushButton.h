#pragma once

#include "DigitalDevice.h"
#include "Arduino.h"

class PushButton : public DigitalDevice
{
public:

    PushButton( int p );

    bool state = false, lastState = false;
    unsigned long lastDebounceTime = 0;

    void scan();

    
};
