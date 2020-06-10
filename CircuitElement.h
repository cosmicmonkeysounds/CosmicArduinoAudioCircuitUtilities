#pragma once
#include <string>

struct CircuitElement
{
    CircuitElement();
    virtual ~CircuitElement();

    uint16_t currentValue;
    const std::string& name;

    uint16_t transferFunction( uint16_t );
    void update( void(*)() );
};