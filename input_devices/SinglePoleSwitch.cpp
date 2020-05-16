#include "Arduino.h"
#include "SinglePoleSwitch.h"

SinglePoleSwitch::SinglePoleSwitch(int p) : InputDevice(p) {}
SinglePoleSwitch::~SinglePoleSwitch() {}

bool SinglePoleSwitch::debounce()
{
    pinReading = digitalRead(pin);
    if( pinReading != lastState ) lastDebounceTime = millis();
    lastState = pinReading;

    bool pressed = false;
    if( millis() - lastDebounceTime > 50 ) pressed = true;
    return pressed;
}