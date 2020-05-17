#pragma once

#include "Arduino.h"

class SinglePoleSwitch
{
public:

    int pin;
    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;

    SinglePoleSwitch( int p ) : pin(p) {}

    bool debounce()
    {
        pinReading = digitalRead(pin);
        if( pinReading != lastState ) lastDebounceTime = millis();
        lastState = pinReading;

        bool pressed = false;
        if( millis() - lastDebounceTime > 50 ) pressed = true;
        return pressed;
    }

};