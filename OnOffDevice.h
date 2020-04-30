#pragma once

// this class is stupid pay no mind it will die soon

class OnOffDevice{
public: 
    bool onOrOff = false;

    void changeState( bool io ){
        onOrOff = io;
    }

    void changeState(){
        changeState( !onOrOff );
    }
};