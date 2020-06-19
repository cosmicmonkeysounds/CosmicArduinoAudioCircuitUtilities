#pragma once

#include "Arduino.h"

struct SPST
{
    uint8_t pin;
    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;

    SPST( uint8_t p ) 
    {
        pin = p;
        pinMode( pin, INPUT );
    }

    bool debounce()
    {
        pinReading = digitalRead(pin);
        if( pinReading != lastState ) lastDebounceTime = millis();
        lastState = pinReading;

        bool pressed = false;
        if( millis() - lastDebounceTime > 50 )
        {
          if( pinReading != state )
          {
            state = pinReading;
            if( state ) pressed = true;
          }
        }
        return pressed;
    }
};
