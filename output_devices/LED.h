#pragma once

/**
 *  A 1-bit, on or off LED output device.
*/

#include "OutputDevice.h"

class LED : public OutputDevice
{
public:
    LED(int);
    ~LED() override;

    bool onOrOff = false;

    void changeState( bool io ){
        onOrOff = io;
    }

    int stupidCounter = 0;
    void crazyWrite();

    void writePin(int v) override;
};
