struct LED
{
    bool onOrOff = false;
    int pin;

    LED( int pinNum )
    {
        pin = pinNum;
    }

    void flip()
    {
        this->onOrOff = !this->onOrOff;
        this->updatePin();
    }

    void onOff( int msg )
    {
        this->onOrOff = msg;
        this->updatePin();
    }
    
    void updatePin()
    {
        digitalWrite( this->pin, this->onOrOff );
    }
    
};
