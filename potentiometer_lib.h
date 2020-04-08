struct Potentiometer
{
    int val, pin;

    Potentiometer( int pinNum )
    {
        pin = pinNum;
        updateVal();
    }

    void updateVal()
    {
        val = analogRead( pin );
    }

    int valToPWM()
    {
        return map( val, 0, 1023, 0, 255 );
    }
};