#include "Arduino.h"
#include "PWM.h"

PWM::PWM(int p) : OutputDevice(p, 8) {}
PWM::~PWM() {}

void PWM::writePin(int v)
{
    analogWrite(pin, v);
}