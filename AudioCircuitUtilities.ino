/**
 *  The root of it all! Pretty barren. 
*/

#define BYPASS_BTN  13
#define SECOND_BTN  12
#define LED_DATA    3
#define LED_CLOCK   4

#include "State.h"

int inPins[2]  = { BYPASS_BTN, SECOND_BTN };

void setup()
{

  for( int p : inPins ){ pinMode( p, INPUT ); }
  Serial.begin(9600);

}

void loop()
{ 

}
