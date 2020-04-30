#pragma once
#include "Arduino.h"
#include "ExternalPart.h"

class OptoFET : public ExternalPart{
public:
    OptoFET( ModMatrix* mod, OutputDevice* device ) : ExternalPart(mod, device) {}

    // This is a total hack please forgive me 
    int transferFunction() override{
        return map( modMatrix->output(),
                    0, modMatrix->bitDepth,
                    500, 700 );
    }
};
