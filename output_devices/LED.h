#pragma once
#include "Arduino.h"
#include "OutputDevice.h"
#include "../OnOffDevice.h"

class LED : public OutputDevice, public OnOffDevice{
public:
    LED(int);
    ~LED() override;
    int stupidCounter = 0;
    void crazyWrite();
    void writePin(int v);
};
