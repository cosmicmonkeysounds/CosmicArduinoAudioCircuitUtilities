#pragma once

/**
 * ExternalPart is the base class used to represent real-world parts on a circuit board. 
 * 
 * Every ExternalPart has a unique ModMatrix to receive input data from, 
 * and a unique OutputDevice use as an output. 
 * 
*/

#include "../ModMatrix.h"
#include "../output_devices/OutputDevice.h"

class ExternalPart{
public:
    ExternalPart( ModMatrix* mod, OutputDevice* device ) 
                : modMatrix(mod), outputDevice(device) {}

    virtual ~ExternalPart() {}

    int outValue = 0;
    ModMatrix* modMatrix;
    OutputDevice* outputDevice;
    
    /**
     *  Returns some mapped integer value that might correspond with the range of output desired,
     *  in the case of the OptoFET sub-class, it maps the ModMatrix's n-bit value into a
     *  range that works well for that OptoFET's I/V characteristics.
     * 
     *  I know I *should* refactor this function into it's own TransferFunction class, 
     *  but what the hell, I just need this working simply before adding more complexity! 
    */
    virtual int transferFunction() = 0;

    // Is this too crude? Press F to pay respects.
    void processInputs(){
        outValue = map( transferFunction(), 
                        0, modMatrix->bitDepth,
                        0, outputDevice->bitDepth );
        outputDevice->writePin(outValue);
    }
};
