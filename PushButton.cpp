#include "PushButton.h"
#include "Arduino.h"

PushButton::PushButton( int p ) : DigitalDevice( p ) {}

void PushButton::scan()
{
    readPin();
    if( pinReading != lastState ) lastDebounceTime = millis();

    if( (millis() - lastDebounceTime) > 50 )
    {
        if( pinReading != state )
        {
            state = pinReading;
            if( state ) changeState();
        }
    }

    lastState = pinReading;
}
