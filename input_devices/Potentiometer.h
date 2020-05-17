#pragma once

#include "Arduino.h"

/**
 *  A simple class that takes the average of values read from the pin 
 *  an assigns that average to it's currentValue member variable.
*/

class Potentiometer
{
public:

    Potentiometer( int p ) : pin(p)
    {
        currentValue = analogRead(pin);
    }

    int pin, currentValue;
    static const int numReadings = 10;
    int readings[numReadings]    = {currentValue};
    unsigned long lastTimeRead   = millis();
    int readIndex                = 0;

    void update()
    {   
        if( millis() - lastTimeRead > 10 )
        {
            readings[readIndex] = analogRead(pin);
            readIndex = (readIndex + 1) % 10;
            int avg = 0;
            for( int i = 0; i < numReadings; ++i ){ avg += readings[i]; }
            currentValue = avg / numReadings;
            lastTimeRead = millis();
        }        
    }
};
