#include <iostream>
#include <string>

struct Something 
{
    const std::string& name;
    Something( const std::string& n ) : name(n) {}
    int value = 2;
    operator Something() const { return name; }
    //operator Something&() { return name; }
    
    // std::ostream& operator<< ( std::ostream& os, const something& ) 
    // {
    //     os << something;
    //     return os;
    // }
};

template< typename T >
struct CosmicList
{
    struct Node
    {
        T& data;
        Node( T _data ) : data(_data) {}
        Node* next = nullptr;
    };
    
    Node& head = nullptr;
    Node& tail = nullptr;
    int length = 0;
    
    CosmicList() {}
    
    CosmicList( T& data )
    {
        head = Node(data);
        head.next = tail;
        ++length;
    }
    
    void insert( T data )
    {
        Node& currentNode = head;
        
        for( int i = 0; i <= length; ++i )
        {
            if( currentNode == nullptr )
            {
                 
            
    }    
    
};

// template< const std::string&, typename T >
// struct CosmicHash
// {
//     T* bucket[10] = {nullptr};
// };

int main(void)
{
    std::cout << "All good govner!\n";
    Something stupid{"shitty"};
    return 0;
}