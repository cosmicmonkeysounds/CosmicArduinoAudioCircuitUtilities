#pragma once

#include "./input_devices/SinglePoleSwitch.h"

class ISRBase
{
public:

    static ISRBase* instances[10];
    
    const int pin;
    ISRBase( int );
    virtual void innerISR() = 0;

    enum isrTypes
    {
        BYPASS_FSW = 0,
        SECONDARY_FSW,
        PRE_EMPHASIS_A,
        PRE_EMPHASIS_B,
        PRE_EMPHASIS_SW,
        STABILITY_A,
        STABILITY_B,
        STABILITY_SW
    };

};

class BypassISR : public ISRBase
{
public:

    SinglePoleSwitch sw;
    bool onOrOff = false;
    BypassISR( int );

    void innerISR() override;

    static void ISR();
};
