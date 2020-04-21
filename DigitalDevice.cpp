#include "DigitalDevice.h"
#include "Arduino.h"

DigitalDevice::DigitalDevice( int p, bool re ) : pin(p), readEnable(re) {}
DigitalDevice::DigitalDevice( int p )          : DigitalDevice( p, true ) {}

void DigitalDevice::readPin()
{ 
    if( readEnable ) pinReading = digitalRead( pin ); 
}

void DigitalDevice::writePin() 
{ 
    writePin( onOrOff ); 
}

void DigitalDevice::writePin( int v )      
{ 
    if( readEnable == false ) digitalWrite( pin, v ); 
}

void DigitalDevice::changeState() 
{ 
    changeState( !onOrOff ); 
}

void DigitalDevice::changeState( bool io ) 
{ 
    onOrOff = io; 
}
