#pragma once
#include "OutputDevice.h"

class DacOut : public OutputDevice{
public:
    DacOut(int, int);
    ~DacOut() override;
    void writePin(int val) override;
};
