#include <iostream>
#include <vector>

// struct Button
// {

//     struct Listener
//     {
//         virtual ~Listener() {}
//         virtual void buttonClicked( Button* b ) = 0;
//     };

//     std::vector<Listener*> listeners;
//     void addListener( Listener* listener ) { listeners.push_back( listener ); }

//     void click()
//     {
//         for( auto* listener : listeners ) 
//         { 
//             listener->buttonClicked( this ); 
//             if( Foo* foo = dynamic_cast<Foo*>( listener ) )
//             {
//                 foo->buttonClicked( this ); // error "not accessible" if it is a private member
//             }
//         }
//     }

// };

// struct Foo : private Button::Listener
// {

//     Foo() 
//     { 
//         button.addListener( this );
//         button.click(); 
//     }

//     void buttonClicked( Button* b ) override
//     {
//         std::cout << "button clicked\n";
//     }

// private:
//     Button button;

// };


///////////////
// SINGLETON //
///////////////

// used in message manager in JUCE 

struct Singleton
{
public:
    static Singleton& getInstance();
    static void deleteInstance();

private:
    static Singleton* instance;
    Singleton() {}
    ~Singleton() {}
};

Singleton* Singleton::instance = nullptr;

Singleton& Singleton::getInstance()
{
    if( instance == nullptr ) { instance = new Singleton(); }
    return *instance;
}

void Singleton::deleteInstance()
{
    delete instance; // calls ~Singleton()
    instance = nullptr;
}

int main()
{
    auto& s = Singleton::getInstance();
    Singleton::deleteInstance();
}