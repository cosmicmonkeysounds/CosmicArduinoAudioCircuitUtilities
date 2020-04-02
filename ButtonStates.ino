#include <ArduinoSTL.h>
#include <vector>

// Setup and stuff for various constants used in the calculations of switch timing
//////////////////////////////////////////////////////////////////////////////////
#define DEBOUNCE_DELAY 50

// Giving "numbers" to the physical pins 
////////////////////////////////////////
#define LED1 11
#define LED2 A0
#define BTN1 A4
#define BTN2 A5

// This runs when the board boots and gets everything else ready
////////////////////////////////////////////////////////////////
void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  Serial.begin(9600);
}

// A custom type that holds the buttons state, and a suite of features to make it work
//////////////////////////////////////////////////////////////////////////////////////
struct Button
{
  
  int pin; // physical pin number
  bool reading = false, state = false, lastState = false, onOrOff = false; // stores the state of the button
  unsigned long lastDebounceTime = 0; // important for debounce timing

  int scan();
  void onOff(int msg);

  Button ( int pinNum )
  {
    pin = pinNum;
  }
  
};

void Button::onOff(int msg)
{
  if ( msg == 1 )
  {
    this->onOrOff = true;
  }
  else
  {
    this->onOrOff = false;
  }
}

int Button::scan()
{
  
  this->reading = digitalRead(this->pin);
  if ( this->reading != this->lastState )
  {
    lastDebounceTime = millis();
  }

  if ( (millis() - this->lastDebounceTime) > DEBOUNCE_DELAY ) // is it within debounce range?
  {
    
    // button is up
    if ( this->reading != this->state ) 
    {
      std::printf("Up");
      this->state = this->reading;

      // button is down
      if ( this->state == HIGH ) 
      {
        std::printf("Down");
        return 1;
      }
    } 
  }
  return 0;
}

struct State
{
  
  bool firstState = false, secondState = false;
  unsigned int numButtons;
  std::vector<Button> buttons;
  int btnPins[2] = {BTN1, BTN2}, ledPins[2] = {LED1, LED2};

  void updateLEDs(), scanButtons(), logic(int index, Button* btn);
  
  State()
  {
    numButtons = sizeof(btnPins) / sizeof(int);
    for ( int i = 0; i < numButtons; ++i )
    {
      buttons.push_back(Button(btnPins[i]));
    }
  }
  
} state;

void State::logic(int index, Button* btn)
{
    int pressed = btn->scan();
    btn->lastState = btn->reading;
    
    if ( pressed == 1 )
    {
      std::printf(" button %d\n***\n\n", index) ;
 
    }
    
}

void State::updateLEDs()
{
  for ( int i = 0; i < this->numButtons; ++i )
    {
      digitalWrite( ledPins[i], this->buttons.at(i).onOrOff );
    }
}

void State::scanButtons()
{
  for ( int i = 0; i < this->numButtons; ++i )
    {
      this->logic( i, &this->buttons.at(i) );
    }
}

void loop() 
{
  state.scanButtons();
}
