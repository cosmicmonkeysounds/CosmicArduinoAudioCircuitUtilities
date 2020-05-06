#pragma once

/** 
 *  Base class for all pins that will need an ISR
*/

class IsrHandler;

class IsrObject
{
public:
    int pin;
    IsrObject( int p, IsrHandler& );
    virtual void callback();
    
private:
    std::function<void()> isr;
};
