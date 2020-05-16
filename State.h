#pragma once 

/** State.h **
 * 
 *  State is a singleton class that is composed all the components needed in the program.
 *  It also stores business logic which will probably (definitely) be refactored.
 * 
 *  The only way to get a reference to the State instance is to call State::getInstance();
 * 
*/

#include <functional>

#include "Arduino.h"

#include "input_devices/PushButton.cpp"
#include "input_devices/Potentiometer.cpp"

class State
{
public:


    static State& getInstance()
    {
        static State instance;
        return instance;
    }
    

    void mainLoop()
    {

    }

private:

    // Not implementing to stop usage
    State( State const& copy );
    State& operator= ( State const& copy );
    
    State(){}

    Potentiometer lpPot{pot1pin};
    Potentiometer hpPot{pot2pin};

};
