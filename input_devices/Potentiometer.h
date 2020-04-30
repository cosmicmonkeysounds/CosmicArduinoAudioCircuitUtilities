#pragma once
#include "InputDevice.h"
#include "Arduino.h"

/**
 *  A simple class that takes the average of values read from the pin 
 *  an assigns that average to it's currentValue member variable.
*/

class Potentiometer : public InputDevice{
public:
    Potentiometer( int p ) : InputDevice(p) {}
    
    static const int numReadings = 10;
    int readings[numReadings]    = {currentValue};
    unsigned long lastTimeRead   = millis();
    int readIndex                = 0;

    void update() override
    {   
        if( millis() - lastTimeRead > 10 )
        {
            readings[readIndex] = analogRead(pin);
            ++readIndex;
            if( readIndex >= numReadings ) readIndex = 0;
            int avg = 0;
            for( int i = 0; i < numReadings; ++i ) { avg += readings[i]; }
            currentValue = avg / numReadings;
            lastTimeRead = millis();
        }        
    }

};
