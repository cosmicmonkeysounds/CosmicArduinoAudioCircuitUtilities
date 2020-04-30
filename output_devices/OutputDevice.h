#pragma once

/**
 *  The base-class for all analog and digital pin output devices.
 *  All ExternalParts own a unique OutputDevice which they use to convert their 
 *  custom range/transfer/modulation functions to actual values to be outputted by the MCU.
 *  
 *  Seems like a fairly useless class currently. But I think when I expand to using SPI devices,
 *  this may be a good call.
*/

class OutputDevice{
public:
    OutputDevice(int p, int bit) : pin(p), bitDepth(bit) {}
    virtual ~OutputDevice() {}
    int pin, bitDepth;

    virtual void writePin(int) = 0;
};
