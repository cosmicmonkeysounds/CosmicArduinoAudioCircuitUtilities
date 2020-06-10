#pragma once
#include <unordered_set>
#include "CircuitParameter.h"

struct State
{
    std::unordered_set<CircuitParameter*> parameters;

    State();
    State( State& );
    State( State&& );
    State( std::unordered_set<CircuitParameter*> );

    ~State();

    State& operator= ( State& );
    State& operator+ ( State& );
};