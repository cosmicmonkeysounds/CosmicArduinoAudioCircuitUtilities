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

#include "input_devices/Potentiometer.h"

#include "./ISRHandler.h"

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
    
    BypassISR bypassFootswitch{13};
    
    State(){}



};
