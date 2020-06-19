#pragma once
#include <string>
#include "CircuitParameter.h"

struct State
{
    State();
    State( const State& );
    State( State&& );

    ~State();
    
    State& operator= ( const State& );
    State& operator+ ( const State& );
};
