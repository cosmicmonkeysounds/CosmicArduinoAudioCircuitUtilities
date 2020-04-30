#pragma once
#include "Arduino.h"
#include "OutputDevice.h"

class PWM : public OutputDevice{
public:
    PWM(int p) : OutputDevice(p, 8) {}

    void writePin(int v){
        analogWrite(pin, v);
    }
};
