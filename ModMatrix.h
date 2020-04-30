#pragma once
#include "input_devices/InputDevice.h"

/**
 *  A class that has an array of input devices to be read from and combined 
 *  at the whims of the current mode in State and the ExternalDevice attached to it.
*/

class ModMatrix{
public:
    ModMatrix() {}
    InputDevice* inputs[10] = {nullptr};
    int lastOutput = 0, bitDepth = 10;

    int output(){
        int sum = 0;
        for( auto* in : inputs ){ if( in ) sum += in->currentValue; }
        return sum;
    }
};