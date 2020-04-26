#pragma once 
#include "Arduino.h"
#include "LED.h"
#include "PushButton.h"
#include "Potentiometer.h"


/*
State is a singleton struct that holds all the global variables in the program.
All the components are composed with references to the State instance.
The only way to get a reference to the State instance is to call State::getInstance();
*/

class State
{
public:
    
    LED* LEDs[2]               = {nullptr};
    PushButton* PushButtons[2] = {nullptr};
    Potentiometer* Pots[1]     = {nullptr};

    static State* getInstance(int*, int*, int*);
    void scanUI();

private:

    static State* instance;
    
    State( int lPins[], int bPins[], int pPins[] ) 
    {
        for( int p = 0; p <= ( sizeof(lPins) / sizeof(lPins[0]) ); ++p )
        {
            LEDs[p] = new LED( lPins[p] );
        }

        for( int p = 0; p <= ( sizeof(bPins) / sizeof(bPins[0]) ); ++p )
        {
            PushButtons[p] = new PushButton( bPins[p] );
        }

        for( int p = 0; p <= ( sizeof(pPins) / sizeof(pPins[0]) ); ++p )
        {
            Pots[p] = new Potentiometer( pPins[p] );
        }
    }
    
    ~State() { delete instance; }

};
