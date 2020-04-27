#pragma once
#include "Arduino.h"

class DigitalDevice
{
  
public:

    int pin; bool readEnable, pinReading = false, onOrOff = false;

    DigitalDevice( int p, bool re ) : pin(p), readEnable(re) {}
    DigitalDevice( int p )          : DigitalDevice( p, true ) {}

    void readPin(){ 
        if( readEnable ) pinReading = digitalRead( pin ); 
    }

    void writePin( int v ){
        if( !readEnable ) digitalWrite( pin, v );
    };

    void writePin(){
        writePin(!onOrOff);
    }

    void changeState( bool io ){
        onOrOff =  io;
    }
    void changeState(){
        changeState( !onOrOff );
    }
    
};
