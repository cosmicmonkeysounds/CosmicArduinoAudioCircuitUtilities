#pragma once
#include "Arduino.h"
#include "OutputDevice.h"
#include "../OnOffDevice.h"

class LED : public OutputDevice, public OnOffDevice{
public:
    LED(int p) : OutputDevice(p, 0) {} 

    void writePin(int v){
        digitalWrite(pin, v);
    }

    int stupidCounter = 0;

    void crazyWrite(){
        analogWrite(pin, stupidCounter);
        stupidCounter = (stupidCounter + 1) % 256;
    }

};
