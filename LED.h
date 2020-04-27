#pragma once
#include "DigitalDevice.h"

class LED : public DigitalDevice
{
public:
    LED( int p ) : DigitalDevice( p, false ) {} 
    
};
