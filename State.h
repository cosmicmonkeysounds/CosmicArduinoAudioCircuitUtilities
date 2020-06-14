#pragma once
#include <string>
#include <unordered_map>
#include "CircuitParameter.h"

struct State
{
    std::unordered_map< const std::string&, const CircuitParameter& > parameters;

    State();
    State( const State& );
    State( State&& );
    State( std::unordered_map< const std::string&, const CircuitParameter& > );

    ~State();
    
    State& operator= ( const State& );
    State& operator+ ( const State& );
};
