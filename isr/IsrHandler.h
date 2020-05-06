#pragma once

#include <vector>
#include <functional>

class IsrObject;

class IsrHandler
{
public:

    static IsrHandler& getInstance()
    {
        static IsrHandler instance;
        return instance;
    }

    int count = 0;
    std::vector<IsrObject*> objects;

    // void addHandler( std::function<void()> callback );
    void addHandler( std::function<void()> , IsrObject& );
    static void wrapper();

private:
    IsrHandler(){}
    IsrHandler( IsrHandler const& copy );
    IsrHandler& operator= ( IsrHandler const& copy );
};