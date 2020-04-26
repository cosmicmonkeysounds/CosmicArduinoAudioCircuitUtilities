#pragma once
#include "AnalogDevice.h"
#include "Arduino.h"

class Potentiometer : public AnalogDevice
{
public:

    Potentiometer( int p ) : AnalogDevice(p) {}

    static const int numReadings = 10;
    int readings[numReadings]    = { analogRead(pin) };
    int readIndex                = 0, 
        averageVal               = readings[0];
    unsigned long lastTimeRead   = millis();

    void updateValue()
    {   
        if( millis() - lastTimeRead > 10 )
        {
            readings[readIndex] = analogRead(pin);
            ++readIndex;
            if( readIndex >= numReadings ) readIndex = 0;
            int avg = 0;
            for( int i = 0; i < numReadings; ++i ) { avg += readings[i]; }
            averageVal = avg / numReadings;
            lastTimeRead = millis();
        }        
    }

    int getValue( int x = 0, int y = 1023 ) { return map( averageVal, 0, 1023, x, y ); }
    int get8BitValue()  { return getValue( 0, 255 ); }
    int get12BitValue() { return getValue( 1434, 1514 ); }  
    
};
