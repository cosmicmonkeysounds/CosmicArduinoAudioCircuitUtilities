#pragma once
#include "CircuitElement.h"

struct CircuitParameter
{
    CircuitParameter();
    virtual ~CircuitParameter();

    char label[15];
    CircuitElement& element;
};
