#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(int p) : InputDevice( p ) {}
PushButton::~PushButton() {}

void PushButton::update(){
    if( pinReading != lastState ) lastDebounceTime = millis();
    if( millis() - lastDebounceTime > 50 ){
        if( pinReading != state ){
            state = pinReading;
            if( state ) changeState();
        }
    }
    lastState = pinReading;
}