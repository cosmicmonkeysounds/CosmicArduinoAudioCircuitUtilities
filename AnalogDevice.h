#pragma once 
#include "Arduino.h"

class AnalogDevice
{
public:
    int pin;
    AnalogDevice( int p ) : pin(p) {};
};