#include "State.h"

State& State::getInstance()
{
    if( instance == nullptr ) instance = new State();
    return *instance;
}

void State::deleteInstance()
{
    delete instance;
    instance = nullptr;
}

void setupSequence( int leds[], int buttons[] )
{
    for ( int p = 0; p < ( sizeof(leds) / sizeof(leds[0]) ); ++p )
    {
        LED* l = new LED( leds[p] );
        LEDs.add(l);
    }

    for ( int p = 0; p < ( sizeof(buttons) / sizeof(buttons[0]) ); ++p )
    {
        PushButton* pb = new PushButton( buttons[p] );
        PushButtons.add(pb);
    }
}

void scanUI()
{
    PushButton* pb = nullptr;
    for( int i = 0; i < PushButtons.length; ++i )
    {
        pb = PushButtons[i];
        pb->scan();
        LEDs[i]->writePin( pb->state );
    }
}