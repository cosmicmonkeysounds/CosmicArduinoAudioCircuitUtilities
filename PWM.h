#pragma once
#include "AnalogDevice.h"
#include "Arduino.h"

class PWM : public AnalogDevice
{
public:
    PWM( int p ) : AnalogDevice(p) {}
};