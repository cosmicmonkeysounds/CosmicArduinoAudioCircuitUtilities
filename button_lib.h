struct Button
{
    int pin; // physical pin number

    // store the states of the button
    bool reading = false, 
    state = false, 
    lastState = false, 
    onOrOff = false; 

    unsigned long lastDebounceTime = 0; // important for debounce timing


    Button( int pinNum )
    {
        pin = pinNum;
    }

    void onOff( bool msg )
    {
        this->onOrOff = msg;
    }

    int scan()
    // Returns 1 if button is down, 0 if it's up
    {

        this->reading = digitalRead( this->pin );
        // maybe this is a bounce, maybe not
        if( this->reading != this->lastState ) 
        {
            // either way, update that time the reading changed
            lastDebounceTime = millis(); 
        }

        // is that new time outside debounce range?
        if( ( millis() - this->lastDebounceTime ) > 50 ) 
        {
            
            if( this->reading != this->state ) // button is up
            { 
                this->state = this->reading;
                if( this->state == HIGH ) // button is down
                { 
                    return 1;
                }
            } 
            
        }
        return 0;
    }
};
