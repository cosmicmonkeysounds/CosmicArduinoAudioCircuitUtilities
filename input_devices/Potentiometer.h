#pragma once
#include "InputDevice.h"

/**
 *  A simple class that takes the average of values read from the pin 
 *  an assigns that average to it's currentValue member variable.
*/

class Potentiometer : public InputDevice{
public:
    Potentiometer(int);
    ~Potentiometer() override;

    static const int numReadings = 10;
    int readings[numReadings]    = {currentValue};
    unsigned long lastTimeRead   = millis();
    int readIndex                = 0;

    void update() override;      
};
