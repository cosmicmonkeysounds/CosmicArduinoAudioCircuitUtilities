#include "Arduino.h"
#include "PushButton.h"

void PushButton::update()
{
    if( sw.debounce() )
    {
        if( sw.pinReading != sw.state )
        {
            sw.state = sw.pinReading;
            if( sw.state ) onOrOff = !onOrOff;
        }
    }
}