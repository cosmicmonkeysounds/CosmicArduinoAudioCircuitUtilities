#include "State.h"


int ledPins[2]    = {A0, 11};
int buttonPins[2] = {A4, A5};

class State;

State* State::instance = nullptr;
State* state = State::getInstance( ledPins, buttonPins );

void setup() 
{
  for( int p : ledPins )    { pinMode( p, OUTPUT ); }
  for( int p : buttonPins ) { pinMode( p, INPUT );  }
  Serial.begin(9600);
}


void loop() 
{
  state->scanUI();
}
