#include "Arduino.h"
#include "State.h"
#include "LED.h"
#include "PushButton.h"
#include "Potentiometer.h"


State* State::getInstance( int* l, int* pb, int* p )
{
    if( !instance ) instance = new State( l, pb, p );
    return instance;
}


void State::scanUI()
{
    for( int i = 0; i < 2; ++i )
    {
        PushButtons[i]->scan();
        LEDs[i]->writePin( PushButtons[i]->onOrOff );
    }

    for( Potentiometer* p : Pots )
    {
      p->updateValue();
//      analogWrite( A0, 1200 );
    }
//    Pots[0]->updateValue();
//    analogWrite( A0, v );
//    analogWrite( A1, Pots[0]->get12BitValue() );
//    Serial.println( v );
}
