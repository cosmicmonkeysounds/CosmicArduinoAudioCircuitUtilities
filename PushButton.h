#pragma once
#include "Arduino.h"
#include "DigitalDevice.h"

class PushButton : public DigitalDevice
{
public:

    PushButton( int p ) : DigitalDevice( p ) {}

    bool state = false, lastState = false;
    unsigned long lastDebounceTime = 0;

    void scan()
    {
        readPin();
        if( pinReading != lastState ) lastDebounceTime = millis();

        if( millis() - lastDebounceTime > 50 )
        {
            if( pinReading != state )
            {
                state = pinReading;
                if( state ) changeState();
            }
        }

        lastState = pinReading;
    }

    
};
