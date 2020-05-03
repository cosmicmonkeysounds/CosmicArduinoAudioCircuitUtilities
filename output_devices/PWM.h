#pragma once

/**
 *  A simple 10-bit PWM output device.
*/

#include "Arduino.h"
#include "OutputDevice.h"

class PWM : public OutputDevice{
public:
    PWM(int);
    ~PWM() override;
    void writePin(int v) override;
};
