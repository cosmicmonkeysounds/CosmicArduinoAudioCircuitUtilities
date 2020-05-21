#include "Arduino.h"
#include "./ISRHandler.h"
#include "./input_devices/SinglePoleSwitch.h"

ISRBase* ISRBase::instances[10] = {nullptr};

ISRBase::ISRBase( int p ) : pin(p) { } 

BypassISR::BypassISR( int p ) : ISRBase(p), sw(p)
{
    ISRBase::instances[BYPASS_FSW] = this;
    Serial.println("Registering ISR");
    attachInterrupt( digitalPinToInterrupt(p), ISR, CHANGE );
}

void BypassISR::innerISR()
{
    Serial.println("Inner ISR");
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
    Serial.println("Executing static ISR");
    ISRBase::instances[BYPASS_FSW]->innerISR();
}
