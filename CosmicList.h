#pragma once
#include "Arduino.h"

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
    int listLength = 0;

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

                if( listLength == 0 )
                    tail = head;
            }
            // inserting at the end 
            else if( index >= listLength )
            {
                if( listLength == 0 )
                {
                    tail = head = new Node<T>();
                    ++listLength;
                }

                index -= listLength;
                for( int i = 0; i < index; ++i )
                {
                    tail->next = new Node<T>();
                    tail = tail->next;
                    ++listLength;
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

            ++listLength;
        }
        
    }
    
    void append( T* data )
    {   
        insert( data, listLength );
    }    
        
    void printAll()
    { 
        for( int i = 0; i < listLength; ++i )
        {
            Serial.print("Index "); Serial.print(i); Serial.print(": ");
            Node<T>* node = getNode(i);
            if( node->data )
                Serial.println(node->data->label);
            else
                Serial.println("NULL");
        }
    }
};
