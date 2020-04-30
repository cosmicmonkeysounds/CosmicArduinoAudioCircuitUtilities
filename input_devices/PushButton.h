#pragma once
#include "InputDevice.h"
#include "../OnOffDevice.h"

class PushButton : public InputDevice, public OnOffDevice{
public:
    PushButton(int);
    ~PushButton() override;

    bool state = false, lastState = false, pinReading = false;
    unsigned long lastDebounceTime = 0;

    void update() override;
};
