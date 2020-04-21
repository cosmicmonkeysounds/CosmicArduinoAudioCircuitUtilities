#include "State.h"

int ledPins[2]    = {A0, 11};
int buttonPins[2] = {A4, A5};

State& state = State::getInstance();

void setup() 
{

  for( int p : ledPins )    { pinMode( p, OUTPUT ); }
  for( int p : buttonPins ) { pinMode( p, INPUT );  }

  state.setupSequence( ledPins, buttonPins );

  Serial.begin(9600);
}



void loop() 
{
  state.scanUI();
}
