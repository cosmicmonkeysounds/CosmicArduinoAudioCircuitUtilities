#pragma once

/**
 *  A simple n-bit DAC output. 
*/

#include "OutputDevice.h"

class DacOut : public OutputDevice
{
public:
    DacOut(int, int);
    ~DacOut() override;
    void writePin(int val) override;
};
