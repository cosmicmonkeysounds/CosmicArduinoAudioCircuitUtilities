#include <functional>
#include <utility>
#include "Arduino.h"

#include "IsrHandler.h"
#include "IsrObject.h"

void IsrHandler::wrapper()
{

}

void IsrHandler::addHandler( std::function<void()> callback, IsrObject& obj )
{
    Serial.println("\nAdding handler...");
    objects.push_back(&obj);

    attachInterrupt( digitalPinToInterrupt(obj.pin), 
                     std::move(callback),
                     CHANGE );

}
