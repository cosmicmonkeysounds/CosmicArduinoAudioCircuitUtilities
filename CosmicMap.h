#include <iostream>
#include <string>

struct Something 
{
    const std::string& name;
    Something( const std::string& n ) : name(n) {}
    int value = 2;

    friend std::ostream& operator<< (std::ostream& out, const Something* s)
    {
        return out << s->name;
    }
};

template< typename T >
struct Node
{
    T* data;
    Node* next = nullptr;

    Node()           : data(nullptr) {}
    Node( T* _data ) : data(_data)   {}

    ~Node() 
    { 
        if( next ) delete next;
    } 
};

template< typename T >
struct CosmicList
{   
    Node<T> *head, *tail;
    int length = 0;

    CosmicList() : head(nullptr), tail(nullptr) {}
    
    CosmicList( T* data )
    {
        insert( data, 0 );
    }

    ~CosmicList()
    {
        if( head ) delete head;
        if( tail ) delete tail;
    }
    
    Node<T>* getNode( int index )
    {
        Node<T>* currentNode = head;
    
        for( int i = 0; i < index; ++i )
            currentNode = currentNode->next;
            
        return currentNode;
    }
    
    Node<T>* operator[] ( int index ) 
    {
        return getNode(index);
    }
    
    void insert( T* data, int index )
    {
        // make sure the shit is in bounds
        if( index >= 0 )
        {       
            Node<T>* newNode = new Node<T>(data);
            
            if( index == 0 )
            {
                newNode->next = head;
                head = newNode;

                if( length == 0 )
                    tail = head;
            }
            // inserting at the end 
            else if( index >= length )
            {
                if( length == 0 )
                {
                    tail = head = new Node<T>();
                    ++length;
                    --index;
                }

                else
                {
                    index -= length;
                }


                for( int i = 0; i < index; ++i )
                {
                    tail->next = new Node<T>();
                    tail = tail->next;
                    ++length;
                }

                tail->next = newNode;
                tail = tail->next;
            }

            else
            {
                Node<T>* nodeBeforeInsertPoint = getNode(index-1);
                newNode->next = nodeBeforeInsertPoint->next;
                nodeBeforeInsertPoint->next = newNode;
            }

            ++length;
        }
        
    }
    
    void append( T* data )
    {   
        insert( data, length );
    }    
        
    void printAll()
    {
        std::cout << "List length is: " << length << "\n";

        for( int i = 0; i < length; ++i )
        {
            std::cout << "\nIndex " << i << ": ";
            Node<T>* node = getNode(i);
            if( node->data )
                std::cout << node->data;
            else
                std::cout << "NULL";
        }

        std::cout << "\n\nHead: " << head << "\n";
        std::cout << "Tail: " << tail << "\n";
    }
};

template< typename T >
struct CosmicMap
{
    CosmicList< CosmicList<T> > buckets;
    int length;

    CosmicMap() 
    {
        length = 17;
        for( int i = 0; i <= length; ++i )
            buckets.append( new CosmicList<T> );
    }

    CosmicMap( int size ) : length(size) 
    {
        for( int i = 0; i <= size; ++i )
            buckets.append( new CosmicList<T> );
    }

    void insert( T* data )
    {
        buckets[hashFunc(data->name)]->data->append(data);
    }

    T* returnNode( const std::string& s )
    {
        Node<T>* bucketNode = buckets[hashFunc(s)]->data->head;

        while( bucketNode )
        {
            if( bucketNode->data->name == s )
                return bucketNode->data;

            bucketNode = bucketNode->next;
        }

        return nullptr;
    }

    unsigned int hashFunc( const std::string& s )
    {
        unsigned int hash = 5381;

        for( const char& c : s )
            hash = (hash * 33) ^ c;
            
        return hash % length;
    }

    void printAll()
    {
        for( int i = 0; i < length; ++i )
            buckets[i]->data->printAll();
    }
};