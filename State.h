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

#include "input_devices/PushButton.h"
#include "input_devices/Potentiometer.h"

#include "output_devices/DacOut.h"
#include "output_devices/LED.h"

#include "external_parts/OptoFET.h"

#include "ModMatrix.h"

class State{
public:

    static State* getInstance(){
        if( !instance ) instance = new State();
        return instance;
    }
    
    void mainLoop(){
        for ( auto* i : inputDevices ){ i->update(); }

        if( crazyToggle->onOrOff ) led1->crazyWrite();
        else led1->writePin(crazyToggle->onOrOff);

        for ( auto* o : externalParts ){ o->processInputs(); }
    }

private:

    static State* instance;
    ~State() { delete instance; }

    State(){
        lpKnob      = new Potentiometer(A2);
        hpKnob      = new Potentiometer(A3);
        crazyToggle = new PushButton(10);
        
        led1 = new LED(11);

        lpFreq = new OptoFET( new ModMatrix(), new DacOut(A0, 12) );
        lpFreq->modMatrix->inputs[0] = lpKnob;

        hpFreq = new OptoFET( new ModMatrix(), new DacOut(A1, 12) );
        hpFreq->modMatrix->inputs[0] = hpKnob;
    }

    Potentiometer *lpKnob, *hpKnob;
    PushButton *crazyToggle;
    InputDevice *inputDevices[3] = { lpKnob, hpKnob, crazyToggle };

    LED *led1;

    OptoFET *lpFreq, *hpFreq;
    ExternalPart *externalParts[2] = { lpFreq, hpFreq };
};
