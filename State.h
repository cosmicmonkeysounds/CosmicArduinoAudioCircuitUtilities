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

#include "output_devices/DacOut.cpp"

#include "output_devices/LED.cpp"

#include "external_parts/OptoFET.cpp"

#include "isr/IsrHandler.cpp"
#include "isr/RotaryPin.h"

#include "ModMatrix.h"

class State
{
public:

    IsrHandler& handler = IsrHandler::getInstance();
    RotaryPin rotA{1, handler};

    static State& getInstance(){
        static State instance;
        return instance;
    }
    

    void mainLoop()
    {
        for( auto* i : inputDevices )
        { 
            i->update(); 
        }
    
        if( crazyToggle.onOrOff ) led1.crazyWrite();
        if( !crazyToggle.onOrOff ) led1.writePin(0);
    
        for( auto* o : externalParts )
        { 
            o->processInputs(); 
        }
    }

private:

    State( State const& copy );
    State& operator= ( State const& copy );
    
    State()
    {
        lpFreq.modMatrix.inputs[0] = &lpPot;
        hpFreq.modMatrix.inputs[0] = &hpPot;
    }

    Potentiometer lpPot{pot1pin};
    Potentiometer hpPot{pot2pin};

    PushButton crazyToggle{btn1pin};

    InputDevice *inputDevices[3] = { &lpPot, &hpPot, &crazyToggle };

    LED led1{led1pin};

    ModMatrix lpFreqMod{};
    ModMatrix hpFreqMod{};

    DacOut lpDAC{opto1pin, 12};
    DacOut hpDAC{opto1pin, 12};

    OptoFET lpFreq{ lpFreqMod, lpDAC };
    OptoFET hpFreq{ hpFreqMod, hpDAC };

    ExternalPart *externalParts[2] = { &lpFreq, &hpFreq };

};
