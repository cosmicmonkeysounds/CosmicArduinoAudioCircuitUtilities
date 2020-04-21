#pragma once
//#include <Arduino.h>

class DigitalDevice
{
  
public:

    int pin; bool readEnable, pinReading = false, onOrOff = false;

    DigitalDevice( int p, bool re );
    DigitalDevice( int p );

    void readPin();
    void writePin( int v );
    void writePin();
    void changeState( bool io );
    void changeState();
    
};
