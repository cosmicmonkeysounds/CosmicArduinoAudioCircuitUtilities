/**
 *  The root of it all! Pretty barren. 
 *  Didn't want this file to send any info to any of the modules, hence the seperate pin declarations.
 *  Don't want to D.R.Y. because then State would need an even longer constructor and I'm not about it.
*/

#include "State.h"

int inPins[]  = {9,  10};
int outPins[] = {11, 12};

State* State::instance = nullptr;     // Not sure why I have to use this line??? 
                                      // Even if I declare instance = nullptr in-class, it doesn't work. 
                                      // Needs to be done in this file it seems. Hmm...

State* state = State::getInstance();  // I should just be able to declare this.

void setup(){
  for( int p : inPins )  { pinMode( p, INPUT );  }
  for( int p : outPins ) { pinMode( p, OUTPUT ); }
  Serial.begin(9600);
}

void loop() { state->mainLoop(); }
