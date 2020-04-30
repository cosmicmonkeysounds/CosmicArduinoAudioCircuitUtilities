#pragma once
#include "Arduino.h"
#include "OutputDevice.h"

class PWM : public OutputDevice{
public:
    PWM(int);
    ~PWM() override;
    void writePin(int v) override;
};
