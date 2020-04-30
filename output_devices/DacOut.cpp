#include "Arduino.h"
#include "DacOut.h"

DacOut::DacOut(int p, int bit) : OutputDevice(p, bit) {}
DacOut::~DacOut() {}

void DacOut::writePin(int val){
    analogWrite(pin, val);
}