#include <ArduinoSTL.h>
#include <vector>

#include "button_lib.h"
#include "led_lib.h"
#include "potentiometer_lib.h"

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
#define PWM1 A4

// This runs when the board boots and gets everything else ready
////////////////////////////////////////////////////////////////
void setup() 
{
  pinMode( LED1, OUTPUT );
  pinMode( LED2, OUTPUT );
  pinMode( PWM1, OUTPUT );
  pinMode( BTN1, INPUT );
  pinMode( BTN2, INPUT );
  pinMode( POT1, INPUT );
  Serial.begin( 9600 );
}

struct State
{
  
  bool bypassState = false, 
  chaosBypassState = false;

  int chaosMode = 0;
  
  unsigned int numButtons, 
  numLEDs;
  
  int btnPins[2] = { BTN1, BTN2 }, 
  ledPins[2] = { LED1, LED2 };
  
  std::vector< Button > buttons;
  std::vector< LED > leds;

  Potentiometer pot{ POT1 };

  void updateLEDs(), 
  scan(), 
  buttonLogic( int index, Button* btn );
  
  State()
  {
    
    numButtons = sizeof( btnPins ) / sizeof( int );
    for( int i = 0; i < numButtons; ++i )
    {
      buttons.push_back( Button( btnPins[i] ) );
    }

    numLEDs = sizeof( ledPins ) / sizeof( int );
    for( int i = 0; i < numLEDs; ++i )
    {
      leds.push_back( LED( ledPins[i] ) );
    }
    
  }
  
};

void State::buttonLogic( int index, Button* btn )
{
    btn->onOrOff = !btn->onOrOff;
    
    this->leds[index].onOff( btn->onOrOff );
    
    if( index == 0 )
    {
      this->bypassState = btn->onOrOff;
    }

    if( index == 1 )
    {
      this->chaosBypassState = btn->onOrOff;
    }
    
}

void State::updateLEDs()
{
  for( int i = 0; i < this->numLEDs; ++i )
    {
      this->leds.at(i).updatePin();
    }
}

void State::scan()
{ 
  Button* btn;
  for( int i = 0; i < this->numButtons; ++i )
    {
      
      btn = &this->buttons.at(i);
      int pressed = btn->scan();
      btn->lastState = btn->reading;
      
      if( pressed == 1 )
      {
        std::printf( " button %d\n***\n\n", i );
        this->buttonLogic( i, btn );
      }
      
    }

   if( this->bypassState )
   {
    // nuttin
   }

   this->pot.updateVal();

   if( this->chaosBypassState )
   {
    if( this->chaosMode = 0 )
    {
      analogWrite( PWM1, this->pot.valToPWM() ); 
      // std::printf( "Exporting %d on pin %d", this->pot.val, this->pot.pin );
    }
   }
   else
   {
    
   }
   
}

State state;

void loop() 
{
  state.scan();
}
