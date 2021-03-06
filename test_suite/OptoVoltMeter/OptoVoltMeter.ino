/**
 *  A dumb lil' sketch that sends a DAC signal to an OptoFET and then reads 
 *  an input from a voltage divider with the OptoFET as R2 and prints it Serial
 *  to be picked up a processed by SerialToCSV.py 
 * 
 *  When you run the sketch, it will wait for you to press a button to get started. Run SerialToCSV.py before starting the loop.
 *  After every DAC value and voltage has been read, it'll pause so you can replace R1. This is done to decrease reading error. 
 *  As R1 gets much smaller or bigger compared than R2 (the OptoFET), the resistance read error will increase.
 *
 *  After your done after R1 value, simply hit reset on the MCU to terminate the Serial printing, 
 *  which will in turn stop the Python script. You now have a .csv file to run statistics with. 
 *  Run CSVToGraph.py to view your results with MatPlotLib. 
*/

int dacPin = A0,
    outPin = 7,
    inPin  = A5;

class PushButton
{
public:

    PushButton( int p ) : pin(p) {}

    int pin;
    bool onOrOff = false, pinReading = false, state = false, lastState = false;
    unsigned long lastDebounceTime = 0;

    void scan()
    {
        pinReading = digitalRead( pin );
        if( pinReading != lastState ) lastDebounceTime = millis();

        if( millis() - lastDebounceTime > 50 )
        {
            if( pinReading != state )
            {
                state = pinReading;
                if( state ) onOrOff = true;
            }
        }

        lastState = pinReading;
    }

    
};

float r1[] = { 470.f, 1000.f, 5100.f, 10000.f, 39000.f, 67000.f, 100000.f, 270000.f, 560000.f, 750000.f, 1000000.f, 2000000.f };

float vIn = 3.3f;

float avgValues[4][4096];


void setup() 
{
    pinMode( 9, INPUT );
    pinMode( outPin, OUTPUT );
    digitalWrite( outPin, HIGH );
    pinMode( 11, OUTPUT );
    PushButton btn(9);
    Serial.begin( 9600 );
    for( int i = 0; i < 4; ++i )
    {
        digitalWrite( 11, btn.onOrOff );
        while( !btn.onOrOff ) { btn.scan(); }
        digitalWrite( 11, btn.onOrOff );
        Serial.print( r1[i] ); Serial.println( ", ");
        for( int val = 0; val < 4096; ++val )
        {   
            Serial.print( val ); Serial.println(", ");
            analogWrite( dacPin, val );
            float sum = 0.f;
            for( int x = 0; x < 20; ++x )
            {
                delay(1);
                float vOut = ( analogRead(inPin) * vIn ) / 1024.f;
                float r2   = r1[i] / ( (vIn/vOut) - 1 );
                sum += r2;
            }
            
            avgValues[i][val] = sum / 20.f;
            Serial.print( avgValues[i][val] ); Serial.println(", ");
        }

        btn.onOrOff = false;
    }
}

void loop() 
{

}
