#include "State.h"
#include "LED.h"
#include "PushButton.h"


State* State::getInstance( int* l, int* pb )
{
    if( !instance ) instance = new State( l, pb );
    return instance;
}


void State::scanUI()
{
    for( int i = 0; i < 2; ++i )
    {
        PushButtons[i]->scan();
        LEDs[i]->writePin( PushButtons[i]->onOrOff );
    }
}
