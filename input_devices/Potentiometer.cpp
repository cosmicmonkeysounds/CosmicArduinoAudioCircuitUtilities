#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer( int p ) : InputDevice(p) {}
Potentiometer::~Potentiometer() {}

void Potentiometer::update(){   
    if( millis() - lastTimeRead > 10 ){
        readings[readIndex] = analogRead(pin);
        ++readIndex;
        if( readIndex >= numReadings ) readIndex = 0;
        int avg = 0;
        for( int i = 0; i < numReadings; ++i ){ avg += readings[i]; }
        currentValue = avg / numReadings;
        lastTimeRead = millis();
    }        
}