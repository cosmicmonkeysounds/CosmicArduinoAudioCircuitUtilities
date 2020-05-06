#include <functional>
#include <utility>
#include "Arduino.h"

#include "IsrObject.h"
#include "IsrHandler.h"

IsrObject::IsrObject( int p, IsrHandler& h ) : pin(p)
{   
    isr = [](IsrObject& obj){ obj.callback(); }
    h.addHandler( [&](){ callback(); }, *this );
}

void IsrObject::callback()
{
    Serial.println("Sup bitch");
}