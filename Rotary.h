#pragma once

#include "Arduino.h"
#include "SPST.h"
#include "Pushbutton.h"
#include "UI_Element.h"

#define DEBOUNCE_INTERVAL 10

struct Rotary : UI_Element
{
    PushButton pushButton;
    uint8_t pinA, pinB;
    int rollover;
    
    Rotary( int _a, int _b, int _sw, int _rollover, const char* _name )
    : pinA(_a), pinB(_b), pushButton(_sw), rollover(_rollover), UI_Element(_name) 
    {
        pinMode( _a, INPUT );
        pinMode( _b, INPUT );
    }

    int counter = 0; 
    bool stateOfA = false, lastStateOfA = false;
    unsigned long lastTimeDebounced = millis();

    void update()
    {
        if( millis() - lastTimeDebounced > DEBOUNCE_INTERVAL )
        {
            lastTimeDebounced = millis();
            stateOfA = digitalRead(pinA);
            if( stateOfA != lastStateOfA )
            {
                if( digitalRead(pinB) != stateOfA )
                    ++counter;
                else
                    --counter;
            }
        }
        lastStateOfA = stateOfA;
        pushButton.update();
    }

    int getValue()
    {
        return counter % rollover;
    }
};
