/**
 *  The root of it all! Pretty barren. 
*/

// all these #defines spill over to State, which is handy.

#define btn1pin  13
#define btn2pin  10
#define led1pin  11
#define led2pin  12
#define pot1pin  A2
#define pot2pin  A3
#define opto1pin A0
#define opto2pin A1



#include "./State.h"

int inPins[2]  = {btn1pin, btn2pin};
int outPins[2] = {led1pin, led2pin};

State& state = State::getInstance();

void setup()
{
  for( int p : inPins )  { pinMode( p, INPUT );  }
  for( int p : outPins ) { pinMode( p, OUTPUT ); }
  Serial.begin(9600);
}

void loop(){ state.mainLoop(); }
