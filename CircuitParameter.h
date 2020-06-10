#pragma once
#include <string>
#include <list>
#include "CircuitElement.h"

struct CircuitParameter
{
    CircuitParameter();
    virtual ~CircuitParameter();

    const std::string& name;
    CircuitElement& element;

};