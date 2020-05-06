#include "Arduino.h"
#include "LED.h"

LED::LED(int p) : OutputDevice(p, 1) {}
LED::~LED() {}

void LED::writePin(int val)
{
    analogWrite(pin, 0);
}

void LED::crazyWrite()
{
    analogWrite(pin, stupidCounter);
    stupidCounter = (stupidCounter + 1) % 256;
    delay(1);
}