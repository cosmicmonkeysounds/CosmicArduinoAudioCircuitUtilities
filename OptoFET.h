#pragma once
#include "Arduino.h"
#include "AnalogDevice.h"

class OptoFET : public AnalogDevice
{
    OptoFET( int p ) : AnalogDevice(p) {}
    
};