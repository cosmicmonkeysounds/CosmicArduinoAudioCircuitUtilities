#pragma once

/**
 *  A stupid simple on/off pushbutton with debounce
*/

#include "SinglePoleSwitch.cpp"

class PushButton
{
public:
    SinglePoleSwitch sw;
    bool onOrOff = false;
    PushButton(int p) : sw(p) {}
    void update();
};
