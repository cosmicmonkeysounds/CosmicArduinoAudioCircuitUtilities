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
    {

        this->reading = digitalRead( this->pin );
        if( this->reading != this->lastState )
        {
            lastDebounceTime = millis();
        }

        // is it outside debounce range?
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
