#include <iostream>
#include <string>
#include <vector>

//////////////////////////////////////
///// POINTERS, REFERENCES, NEW //////
//////////////////////////////////////

struct Person
{
    int age;
    Person( int a ) : age(a) { std::cout << "Hello\n"; }
    ~Person() {}

    void doSomething();
};

void Person::doSomething()
{
    std::cout << "Hello\n";
}

void func( Person *p )
{
    if( p != nullptr )
    {
        // safe to use the pointer
    }
}

//////////////////////////////////
// AVOIDING DANGLING REFERENCES //
//////////////////////////////////

struct Eggs; // forward declaration

struct Spam // similar to a "window" class
{
    Spam( Eggs &egg_ ) : egg(egg_) {}
    Eggs& egg;
};

struct Eggs // would be the "owner" of the "window" class
{
    Eggs() : spam( *this ) {}
    Spam spam; 
    // An instance of eggs now owns an instance of Spam,
    // and that instance of Spam knows about it's owner, Eggs.
    
    // This tightly couples the two structs, but they do no not
    // have dangling references. 
};

//////////////////////
// LISTENER PATTERN //
//////////////////////

// struct Button
// {
//     struct Listener
//     {
//         virtual ~Listener() {}
//         virtual void buttonClicked( Button* ) = 0; // = 0 sets override... I think.
//     };

//     std::vector< Listener* > listeners;

//     void addListener( Listener *listener )
//     {
//         this->listeners.push_back( listener );
//         // should check if not already in the vector of listeners 
//     }

//     void click()
//     {
//         for( int i = 0; i >= listeners.size(); ++i )
//         {
//             listeners[i]->buttonClicked( this );
//         }
//     }

// };

// struct MainWindow : public Button::Listener
// {   
//     MainWindow() 
//     {
//         button.addListener( this );
//     }

//     Button button;

//     void buttonClicked( Button *b ) override
//     {
//         if( b == &button ) 
//         { 
//             // something
//         }
//     }

// };

// struct OtherWindow : public Button::Listener
// {
//     OtherWindow( MainWindow *mw )
//     {
//         mw->button.addListener( this );
//     }

//     void buttonClicked( Button *b ) override
//     {
//         //stuff regardless of button clicked
//     }
// };

//////////////////
// HEAP PATTERN //
//////////////////

struct HeapComponent
{
    std::unique_ptr< Person > bob;

    HeapComponent()
    {
        bob.reset( new Person(1) );
    }

    ~HeapComponent()
    {
        bob.reset( nullptr );
    }
};

//////////////
// CHAINING //
//////////////

// Member functions that return a reference to the class type

// Imagine, Person p,

// p.run().jog().skip().walk().sleep();
// Person& Person::run() { return *this; }

// or

// p.run()->jog()->skip() ....
// Person* Person::run() { return this; }


//////////////
// #INCLUDE //
//////////////

///////////////////////////////////////////////

// no good cuz Tree needs to know everything

// #include <branch.h>
// #include <trunk.h>

// struct Tree
// {
//     Branch branch;
//     Trunk trunk;
// }

////////////////////////////////////////////////

// struct Tree
// {
//      // raw pointers
//     Branch* branch;
//     Trunk* trunk;
//      // or
//
//     std::unique_ptr<Branch> branch; <- doesn't need to know!!
//      or
//      Branch& branch;
// }

// you are "using" an object on when you are constructing, accessing member variables
// or using member functions. that's when you need to include. 
// if you are just declaring a pointer, then you don't need to include.
// But you must forward declare those classes of the pointers you're using!

// tree.h

struct Branch;
struct Trunk;

struct Tree
{
    Branch* branch = nullptr;
    Trunk& trunk; // this referenced object needs to live longer than the tree becuase it is a REFERENCE

    Tree( Branch& br, Trunk& tr );
};

// tree.cpp

// #include "Tree.h"
// #include "Branch.h"
// #include "Trunk.h"

Tree::Tree( Branch& br, Trunk& tr ) :
        branch( &br ),
        trunk( tr )
    {

    }

/////////////////////////
// CIRCULAR DEPENDENCY //
/////////////////////////

// Foo.h

// #include "MainComponent.h"
// struct Foo
// {
//     void doStuff ( MainComponent* mc );
// };

// Foo.cpp

// #include "Foo.h"

// void Foo::doStuff( MainComponent* mc )
// {
//     jassert( &(mc->foo) == this ); 
//     // checking that the address of mc's foo member variable is our instance
// }

// MainComponent.h

// #include "Foo.h"

// struct MainComponent
// {
//     MainComponent()
//     {
//         foo.doStuff( this );
//     }
//     Foo foo;
//     // need to include Foo.h because we specified a Foo, not Foo* or Foo& 
//     // so the compiler needs to know the exact size of a Foo object to make a MainComponent object
// };

// MainComponent.h and Foo.h keep on "including" eachother in an infinite loop
// Simply change on of these include statements to a forward declartion and use pointers or references in the Foo.h file
// when it comes to actually use those, include MainComponent.h in Foo.cpp

////////////////////////////////////////
// NOT ALL FORWARD DELCARATION WORKS! //
////////////////////////////////////////

/////////////////////////////////
// INHERITENCE AND COMPOSITION //
/////////////////////////////////

// a car IS A vehicle
// a car IS A modern invention
// a car IS A tool

// a car HAS A heater and air conditioner
// a car HAS A engine, and a battery
// actually, most vehicles have all of that!

struct TemperatureController
{
    int currentTemp;
};

struct PowerSupply
{
    PowerSupply( int po = 0) : powerOut( po ) {}
    int powerOut;
};

struct Engine : public PowerSupply
{
    Engine( int power = 5 ) : PowerSupply( power ) {}
};

struct Battery : public PowerSupply
{
    Battery( int power = 3 ) : PowerSupply( power ) {}
};

struct Heater
{

};

struct AirConditioner
{

};

struct Tool
{
    Tool( const std::string& purpose_ = "to perform work" ) : purpose(purpose_) {}
    std::string purpose;
};

struct Vehicle : public Tool
{
    // the order is important here!
    Vehicle ( 
             int enginePower,
             int batteryPower,
             const std::string& purpose_ = "to move objects" 
            ) : 
             engine(enginePower),
             battery(batteryPower),
             Tool(purpose_) 
    {
        // nothing yet
    }
    
    Heater heater;
    AirConditioner airConditioner;
    Battery battery;
    Engine engine;
};

struct ModernInvention
{
    int yearInvented = 1901;
};

struct Car : public Vehicle, public ModernInvention
{
    Car() : Vehicle(10, 2, "to move people")
    {
        yearInvented = 1808;
        this->ModernInvention::yearInvented = 1908;
    }
};

//////////////////////////////////////
//   MORE LISTENER PATTERN STUFF    //
// WITH INHERITENCE AND COMPOSITION //
//////////////////////////////////////

// button.addListener(this)

// How does this work?

struct Button
{
    struct Listener
    {
        // virtual means it can be overwritten
        virtual ~Listener() {}

        // this is a pure virtual function. signified by = 0
        // it holds no address (yet)
        // you muse provide an implementation with override later
        virtual void buttonClicked( Button* ) = 0; 
    };

    std::vector< Listener* > listeners;

    void addListener( Listener *listener )
    {
        this->listeners.push_back( listener );
        // should check if not already in the vector of listeners 
    }

    void removeListener( Listener *listener )
    {
        // for( std::vector< Listener >::iterator ptr = listeners.begin(); ptr < listeners.end(); ++ptr )
        // {
        //     if( ptr == listener )
        //     {

        //     }
        // }
    }

    void click()
    {
        for( int i = 0; i >= listeners.size(); ++i )
        {
            listeners[i]->buttonClicked( this );
        }
    }

};

struct Widget : public Button::Listener
{
    Button button;
    
    void buttonClicked(Button* b) override;

    Widget()
    {
        button.addListener( this );
    }

    ~Widget()
    {
        //button.removeListener( this );
    }
}; 

/////////////
// CASTING //
/////////////

// static cast:

void staticCastEx()
{
    int num = 3;
    void* n = &num;
    int* typeErasedInt = static_cast<int*>( n );
}

// dynamic cast

struct Character
{
    virtual ~Character();
};

struct Player : Character
{
    ~Player() {}

};

struct NPC : Character
{
    ~NPC() {}

};

struct GameState
{
    void addSprite( Character* ch )
    {
        if( ch ) // checking if ch is nullptr or not, true if not
        {
            // do stuff
        }

        if( NPC* npc = dynamic_cast<NPC*>( ch ) )
        {
            // evaluates if the character pointer can be converted
            // downwards to an NPC, if yes, continue
            // can replace NPC* npc with auto* npc
        }
    }
};

////////////////////////
// CASTING, OPERATORS //
////////////////////////

struct IntVal
{
    IntVal( int v ) : value(v) {}
    int value;
    operator int() { return value; } // conversion function
};

void func( int v )
{
    IntVal iv(3);
    int sum = v + iv;
}


// const_cast<>() converts to and from constant types to non-constant types
// there are others too, reinterpret_cast and C style casting (int)x or int(a)

///////// Ch.4 Pt.6 ////////////

////////////////////////////////
// PUBLIC, PROTECTED, PRIVATE //
////////////////////////////////

// when declaring a struct, everything is public by default,
// in a class, everything is private by default


int main()
{   
    Person a(1), b(2), c(3);
    HeapComponent steve;
    std::cout << steve.bob->age << "\n";

    Car car;
    std::cout << "A car with a engine power " << car.engine.powerOut << "\n";

    return 0;
}