#pragma once
#include "Arduino.h"
#include "InputDevice.h"
#include "../OnOffDevice.h"

class PushButton : public InputDevice, public OnOffDevice{
public:
    PushButton( int p ) : InputDevice( p ) {}

    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;

    void update() override{
        if( pinReading != lastState ) lastDebounceTime = millis();
        if( millis() - lastDebounceTime > 50 ){
            if( pinReading != state ){
                state = pinReading;
                if( state ) changeState();
            }
        }
        lastState = pinReading;
    }
    
};
