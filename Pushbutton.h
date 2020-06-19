#pragma once
#include "Arduino.h"

#define BUTTON_DOWN_INTERVAL 10
#define DBL_CLICK_INTERVAL   600
#define HOLD_ACKNOWLEDGE     1000

struct PushButton
{
    uint8_t pin;
    PushButton( uint8_t p ) 
    {
        pin = p;
        pinMode(pin, INPUT);
    }

    enum ButtonState
    {
        Open = 0,
        Clicked,
        SingleHold,
        DoubleClicked,
        DoubleHold,
        Released
    } state;
    
    uint8_t keyDownTicks = 0, doubleClickTicks = 0, previousState;
    unsigned long lastDebounceTime = 0, lastTimeClicked = 0;

    void update()
    {

        if( state == Released || state == DoubleClicked )
        {
            state = Open;
            return;
        }

        if( millis() - lastDebounceTime > BUTTON_DOWN_INTERVAL ) // check if debounce timing is exceeded
        {
          
            bool pinReading = digitalRead(pin);
            lastDebounceTime = millis();
            
            if( pinReading == true )
            {
              //Serial.println("Passed debounce while pressed");
              ++keyDownTicks;
              if( keyDownTicks > (HOLD_ACKNOWLEDGE / BUTTON_DOWN_INTERVAL) )
              {
                  if( millis() - lastTimeClicked < DBL_CLICK_INTERVAL )
                      state = DoubleHold;
                  else
                      state = SingleHold; 
              }
                  
            }
    
            if( pinReading == false ) 
            {
              
                if( keyDownTicks > 0 )
                {
                    
                    if( state == SingleHold || state == DoubleHold )
                    {
                        state = Released;
                        doubleClickTicks = 0;
                    }

                    else
                    {
                        if( millis() - lastTimeClicked < DBL_CLICK_INTERVAL )
                        {
                            if( doubleClickTicks < (DBL_CLICK_INTERVAL / BUTTON_DOWN_INTERVAL) )
                            {
                                state = DoubleClicked;
                                doubleClickTicks = 0;
                            }
                        }
                        else
                        {
                            doubleClickTicks = DBL_CLICK_INTERVAL / BUTTON_DOWN_INTERVAL;
                        }
                    }
                    
                }
                
                keyDownTicks = 0;
            } // end of switch up reading block 
            
        } // end of debounce block

        if( state == Clicked )
        {
            state = Open;
            return;
        }

        if( doubleClickTicks > 0 )
        {
            --doubleClickTicks;
            if( --doubleClickTicks == 0 )
            {
                state = Clicked;
                lastTimeClicked = millis();
            }
        }
        
    } // end of update()
    
};
