#pragma once

template< class Type >
struct Node
{
    Type data; 
    Node( Type stuff );
    Node<Type> *next = nullptr, *prev = nullptr;
};

template< class Type >
struct LinkedList
{
    
    int length;
    Node<Type> *head = nullptr, *tail = nullptr;

    LinkedList() : length(0) {}
    LinkedList( Type data ) : LinkedList() { add( data ); }

    ~LinkedList()
    {
        for( Node<Type> *c = head; c->next != nullptr; )
        {
            c = c->next;
            delete c->prev;
        }
        delete tail;
    }

    void add( Type data )
    {

        if( head == nullptr ) // if there is nothing in the list
        {
            head = new Node<Type>{ data };
            tail  = head;
        }
        else
        {
            if( head == tail ) // if there is only one thing in the list
            {
                tail = new Node<Type>{ data };
                head->next = tail;
                tail->prev  = head;
            }
            else // if there is more than one thing in the list
            {
                Node<Type> *newNode = new Node<Type>{ data };
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    
        ++length; // increment the length after all that hubba-balloo
    }

    Type get( const int index )
    {
        if( index == 0 ) return head->data;
        else if( index >= length - 1 ) return tail->data;
        else
        {
            Node<Type> *curr = head;
            for( int i = 1; i < index; ++i ) { curr = curr->next; }
            return curr->data;
        }
    }

    Type operator[]( const int index ){ return get( index ); }

};
