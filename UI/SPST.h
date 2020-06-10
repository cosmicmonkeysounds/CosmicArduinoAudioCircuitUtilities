#pragma once

#include "Arduino.h"

struct SPST
{
    uint16_t pin;
    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;

    SPST( int p ) 
    {
        pin = p;
        pinMode( pin, INPUT );
    }

    SPST( SPST& );
    SPST( SPST&& );

    ~SPST();

    SPST& operator= ( SPST& );
    SPST& operator= ( SPST&& );

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
