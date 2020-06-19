#pragma once
#include "Arduino.h"
#include "CosmicList.h"
#include "CosmicMap.h"
#include "Pushbutton.h"
#include "Potentiometer.h"
#include "Rotary.h"

struct Context
{
    CosmicMap<PushButton*> pushbuttons;
    CosmicMap<Potentiometer*> pots;
    CosmicMap<Rotary*> rotaries;

    Context() {}
    Context( const Context& );
    Context( Context&& );
};
