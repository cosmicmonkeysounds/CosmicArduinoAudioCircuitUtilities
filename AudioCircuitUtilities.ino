#include "button_lib.h"
#include "led_lib.h"
#include "potentiometer_lib.h"
#include "linked_list.h"

// Setup and stuff for various constants used in the calculations of switch timing
//////////////////////////////////////////////////////////////////////////////////
#define DEBOUNCE_DELAY 50

// Giving "numbers" to the physical pins 
////////////////////////////////////////
#define LED1 11
#define LED2 A0
#define BTN1 A4
#define BTN2 A5
#define POT1 A2
#define PWM1 6

// This runs when the board boots and gets everything else ready
////////////////////////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);
  LinkedList< int > l;
  l.add(1);
  l.add(4);
  l.add(10);
  for( int i = 0; i < 3; ++i)
  {
    Serial.println(l[i]);
  }
  
}

void loop() 
{
}
