#include <ArduinoSTL.h>
#include <vector>

// Setup and stuff for various constants used in the calculations of switch timing
//////////////////////////////////////////////////////////////////////////////////
#define CHECK_MSEC      2 // Read hardware every 5 msec
#define PRESS_MSEC     10 // Stable time before registering pressed
#define RELEASE_MSEC  100 // Stable time before registering released
#define PRESS_DELAY    10
#define RELEASE_DELAY 200

#define DEBOUNCE_DELAY 50

// Giving "numbers" to the physical pins 
////////////////////////////////////////
#define LED1 11
#define LED2 A0
#define BTN1 A2
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
  bool pressed = false, changed = false, debounced = false, onOrOff = false; // stores the state of the button
  unsigned long lastDebounceTime = millis(); // important for debounce timing
  
  void push(); 
  void debounceSwitch();

  Button ( int pinNum )
  {
    pin = pinNum;
  }
};

void Button::debounceSwitch()
{
  static long dly = RELEASE_MSEC;
  byte RawState;
  
  this->changed = false;
  this->pressed = this->debounced;
  
  RawState = !digitalRead(this->pin);
  if ( RawState == this->debounced )
  {
    if ( this->debounced ) {
      dly = RELEASE_DELAY;
    } else {
      dly = PRESS_DELAY;
    }
  }
  else
  {
    if( (millis() - this->lastDebounceTime) > dly ) 
    {
      this->debounced = RawState;
      this->changed = true;
      this->pressed = this->debounced;

      if ( this->debounced )
      {
        dly = RELEASE_DELAY;
      } 
      else 
      {
        dly = PRESS_DELAY;
      }
      
    } 
  }
}

void Button::push()
{
  this->debounceSwitch();
  if ( this->changed ) 
  {
    if ( this->pressed ) {
      Serial.println("Key up");
    } else {
      Serial.println("Key down");
      this->onOrOff = !this->onOrOff;
      digitalWrite(LED2, this->onOrOff);
    }
  }
}

struct State
{
  bool firstState = false, secondState = false;
  unsigned int numButtons;
  std::vector<Button> buttons;
  int btnPins[2] = {A4, A5};
  int ledPins[2] = {A0, 11};
  
  void buttonPressed(int buttonNum);
  
  State()
  {
    numButtons = sizeof(btnPins) / sizeof(int);
    for ( int i = 0; i < numButtons; ++i )
    {
      buttons.push_back(Button(btnPins[i]));
    }
  }
} state;

void State::buttonPressed(int buttonNum)
{

}

void loop() 
{
  for ( int i = 0; i < state.numButtons; ++i )
  {
    state.buttons.at(i).push();
  }
}
