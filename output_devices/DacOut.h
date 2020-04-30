#pragma once
#include "Arduino.h"
#include "OutputDevice.h"

class DacOut : public OutputDevice{
public:
    DacOut(int p, int bit) : OutputDevice(p, bit) {}

    void writePin(int val){
        analogWrite(pin, val);
    }
};
