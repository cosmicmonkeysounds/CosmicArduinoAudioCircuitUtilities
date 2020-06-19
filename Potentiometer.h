#pragma once
#include "Arduino.h"
#include "UI_Element.h"

struct Potentiometer : UI_Element
{
    int pin, bitDepth;
    int (*taper)(int) = []( int input ) -> int { return input; };

    Potentiometer( int p, const char* _name )          : Potentiometer( p, 10, _name ) {}
    Potentiometer( int p, int bd, const char* _name )  : pin(p), bitDepth(bd), UI_Element(_name) {}
    
    Potentiometer( int p, const char* _name, int (*customTaper)(int) )          : Potentiometer(p, 10, _name, customTaper) {}
    Potentiometer( int p, int bd, const char* _name, int (*customTaper)(int) )  : pin(p), bitDepth(bd), UI_Element(_name), taper(customTaper) {}

    int currentValue = 0;
    static const int numReadings = 10;
    int readings[numReadings]    = {currentValue};
    unsigned long lastTimeRead   = millis();
    int readIndex                = 0;

    void update()
    {   
        if( millis() - lastTimeRead > 10 )
        {
            readings[readIndex] = analogRead(pin);
            ++readIndex;
            if( readIndex >= numReadings ) readIndex = 0;
            int avg = 0;
            for( int i = 0; i < numReadings; ++i ){ avg += readings[i]; }
            currentValue = avg / numReadings;
            lastTimeRead = millis();
        }        
    }

    int getValue()
    {
      return taper(currentValue); 
    }
};
