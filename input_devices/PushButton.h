#pragma once
#include "InputDevice.h"

class PushButton : public InputDevice{
public:
    PushButton(int);
    ~PushButton() override;

    bool state = false, lastState = false, pinReading = false, onOrOff = false;
    unsigned long lastDebounceTime = 0;

    void changeState( bool io ){
        onOrOff = io;
    }

    void changeState(){
        changeState( !onOrOff );
    }

    void update() override;
};
