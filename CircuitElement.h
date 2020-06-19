#pragma once

struct CircuitElement
{
    CircuitElement( const char* s ) 
    {
        strcpy( label, s  );
    }
    
    ~CircuitElement() = default;

    uint16_t currentValue;
    char label[15];

    uint16_t transferFunction( uint16_t );
    void update( void(*)() );

};
