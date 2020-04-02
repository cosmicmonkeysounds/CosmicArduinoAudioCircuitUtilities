#include <ArduinoSTL.h>
#include <vector>

// Setup and stuff for various constants used in the calculations of switch timing
//////////////////////////////////////////////////////////////////////////////////
#define DEBOUNCE_DELAY 40

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
  Serial.begin(57600);
}

// A custom type that holds the buttons state, and a suite of features to make it work
//////////////////////////////////////////////////////////////////////////////////////
struct Button
{
  int pin; // physical pin number
  bool reading = false, state = false, lastState = false, onOrOff = false; // stores the state of the button
  unsigned long lastDebounceTime = 0; // important for debounce timing

  void check();

  Button ( int pinNum )
  {
    pin = pinNum;
  }
};

void Button::check()
{
  this->reading = digitalRead(this->pin);
  if ( this->reading != this->lastState )
  {
    lastDebounceTime = millis();
  }

  if ( (millis() - this->lastDebounceTime) > DEBOUNCE_DELAY )
  {
    if ( this->reading != this->state )
    {
      this->state = this->reading;

      if ( this->state == HIGH )
      {
        this->onOrOff = !this->onOrOff;
      }
    }
  }
}

struct State
{
  bool firstState = false, secondState = false;
  unsigned int numButtons;
  std::vector<Button> buttons;
  int btnPins[2] = {BTN1, BTN2};
  int ledPins[2] = {LED1, LED2};
  
  void scan();
  
  State()
  {
    numButtons = sizeof(btnPins) / sizeof(int);
    for ( int i = 0; i < numButtons; ++i )
    {
      buttons.push_back(Button(btnPins[i]));
    }
  }
} state;

void State::scan()
{
  for ( int i = 0; i < this->numButtons; ++i )
    {
      this->buttons.at(i).check();
      digitalWrite( ledPins[i], this->buttons.at(i).onOrOff );
      this->buttons.at(i).lastState = this->buttons.at(i).reading;
    }
}

void loop() 
{
  state.scan();
}
