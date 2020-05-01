#pragma once 

/** State.h **
 * 
 *  State is a singleton class that is composed all the components needed in the program.
 *  It also stores business logic which will probably (definitely) be refactored.
 * 
 *  The only way to get a reference to the State instance is to call State::getInstance();
 * 
*/

#include "Arduino.h"

#include "input_devices/PushButton.cpp"
#include "input_devices/Potentiometer.cpp"

#include "output_devices/DacOut.cpp"

#include "output_devices/LED.cpp"

#include "external_parts/OptoFET.cpp"

#include "ModMatrix.h"

#define NAME_OF( component ) #component // "stringizing" operation; let's you get the actual variable name!

class State{
public:

    static State* getInstance(){
        if( !instance ) instance = new State();
        return instance;
    }
    
    void mainLoop(){
        for ( auto* i : inputDevices ){ 
            i->update(); 
            //Serial.print( NAME_OF(i) ); Serial.println( i->currentValue );
        }

        if( crazyToggle.onOrOff ) led1.crazyWrite();
        else led1.writePin(crazyToggle.onOrOff);

        for ( auto* o : externalParts ){ o->processInputs(); }
    }

private:

    static State* instance;
    ~State() { delete instance; }

    State(){
        lpFreq.modMatrix->inputs[0] = &lpKnob;
        hpFreq.modMatrix->inputs[0] = &hpKnob;
    }

    Potentiometer lpKnob{A2};
    Potentiometer hpKnob{A3};

    PushButton crazyToggle{10};

    InputDevice *inputDevices[3] = { &lpKnob, &hpKnob, &crazyToggle };

    LED led1{11};

    ModMatrix lpFreqMod{};
    ModMatrix hpFreqMod{};

    DacOut lpDAC{A0, 12};
    DacOut hpDAC{A1, 12};

    OptoFET lpFreq{ &lpFreqMod, &lpDAC };
    OptoFET hpFreq{ &hpFreqMod, &hpDAC };

    ExternalPart *externalParts[2] = { &lpFreq, &hpFreq };
};
