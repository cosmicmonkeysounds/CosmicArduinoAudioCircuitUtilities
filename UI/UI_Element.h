#pragma once

struct UI_Element
{
    UI_Element();
    UI_Element( UI_Element& );
    UI_Element( UI_Element&& );

    ~UI_Element();

    UI_Element& operator= ( UI_Element& );
    UI_Element& operator= ( UI_Element&& );

    virtual uint16_t getValue() = 0; 
};

#include "SPST.h"

struct PushButton : public UI_Element
{
    SPST sw;
    bool currentState = false;

    PushButton( uint16_t p ) : sw(p) {}

    uint16_t getValue() override
    {

    }

};
