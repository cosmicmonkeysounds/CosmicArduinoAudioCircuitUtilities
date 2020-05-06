#pragma once

#include "Arduino.h"

#include "IsrObject.h"

class IsrHandler;

class RotaryPin : public IsrObject
{
public:
    RotaryPin(int p, IsrHandler& h) :IsrObject(p, h) {}

    void callback()
    {
        Serial.println("Hello");
    }

    static void staticCallback()
    {
        Serial.println("Allo");
    }
};