#pragma once

/**
 *  The base-class for all pin inputs, analog or digital.
 *  When update is called, currentValue is updated and later used by ExternalParts sub-classes
 *  as an input in the ExternalParts' ModMatrix member variable.
*/

class InputDevice{
public:
    InputDevice(int p) : pin(p) {}
    int pin, currentValue = 0;
    virtual void update() = 0;
};
