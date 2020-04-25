#pragma once 
#include "LED.h"
#include "PushButton.h"


/*
State is a singleton struct that holds all the global variables in the program.
All the components are composed with references to the State instance.
The only way to get a reference to the State instance is to call State::getInstance();
*/

class State
{
public:
  
    LED* LEDs[2] = {nullptr};
    PushButton* PushButtons[2] = {nullptr};

    void setupSequence( int leds[], int buttons[] );
    void scanUI();

    static State* getInstance(int*, int*);
    

private:

    static State* instance;
    
    State( int lPins[], int bPins[] ) 
    {
        for( int p = 0; p < ( sizeof(lPins) / sizeof(lPins[0]) ); ++p )
        {
        LED* l = new LED( lPins[p] );
        LEDs[p] = l;
        }

        for( int p = 0; p < ( sizeof(bPins) / sizeof(bPins[0]) ); ++p )
        {
        PushButton* l = new PushButton( bPins[p] );
        PushButtons[p] = l;
        }
    }
    
    ~State() { delete instance; }


};
