struct LFO
{
    int val = 128,
    waveform = 0;

    unsigned long freq = 1.,
    lastTime = millis();

    void applySlope();
    unsigned long freqToMilli();
};

void LFO::applySlope()
{
    if( this->waveform == 0 )
    {

    }
}
