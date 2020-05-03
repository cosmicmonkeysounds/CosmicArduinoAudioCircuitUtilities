#pragma once
#include "Arduino.h"
#include "ExternalPart.h"

class OptoFET : public ExternalPart{
public:
    OptoFET( ModMatrix&, OutputDevice& );
    ~OptoFET() override;
    int transferFunction() override;
};
