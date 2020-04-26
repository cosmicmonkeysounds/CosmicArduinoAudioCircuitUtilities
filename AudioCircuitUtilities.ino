//TCCR0B = TCCR0B & B11111000 | B00000001;    // set timer 0 divisor to 1 for PWM frequency of 62500.00 Hz on Pins 5 & 6 (Atmega 328)

#include "State.h"


int ledPins[2]    = { 12, 11 };
int buttonPins[2] = { 10, 9 };
int potPins[1]    = { A2 };

State* State::instance = nullptr;
State* state = State::getInstance( ledPins, buttonPins, potPins );

void setup() 
{
  for( int p : ledPins )    { pinMode( p, OUTPUT ); }
  for( int p : buttonPins ) { pinMode( p, INPUT );  }
  Serial.begin(9600);
}

void loop() { state->scanUI(); }
