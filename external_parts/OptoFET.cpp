#include "Arduino.h"
#include "OptoFET.h"

OptoFET::OptoFET( ModMatrix& mod, OutputDevice& device ) : ExternalPart(mod, device) {}
OptoFET::~OptoFET() {}

// This is a total hack please forgive me 
int OptoFET::transferFunction()
{
    return map( modMatrix.output(),
                0, modMatrix.bitDepth,
                500, 700 );
}