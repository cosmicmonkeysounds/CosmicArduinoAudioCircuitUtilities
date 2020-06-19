#pragma once

struct UI_Element
{
    char label[15];
    
    UI_Element( const char* _name ) 
    {
      strcpy( label, _name );
    }
//    void update() = 0;
};
