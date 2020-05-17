#include "Arduino.h"
#include "./ISRHandler.h"
#include "./input_devices/SinglePoleSwitch.h"

ISRBase::ISRBase( int p ) : pin(p) {}

BypassISR::BypassISR( int p ) : ISRBase(p), sw(p)
{
    ISRHandler::instances[BYPASS_FSW] = this;
    attachInterrupt( digitalPinToInterrupt(p), ISR, CHANGE );
}

void BypassISR::innerISR()
{
    if( sw.debounce() )
    {
        if( sw.pinReading != sw.state )
        {
            sw.state = sw.pinReading;
            if( sw.state ) onOrOff = !onOrOff;
        }
    }
}

void BypassISR::ISR()
{
    ISRHandler::instances[BYPASS_FSW]->innerISR();
}
