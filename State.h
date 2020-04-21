#pragma once 
#include "LinkedList.h"
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

    LinkedList<LED*> LEDs;
    LinkedList<PushButton*> PushButtons;

    void setupSequence( int leds[], int buttons[] );
    void scanUI();

    static State& getInstance();
    static void deleteInstance();

private:

    static State* instance = nullptr;
    
    State() {}
    ~State() { deleteInstance(); }

    void makeLED        ( int pins[] );
    void makePushButton ( int pins[] );
    void makeSwitch     ( int pins[] );

};
