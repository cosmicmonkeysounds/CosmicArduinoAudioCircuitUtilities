#pragma once
#include "CosmicList.h"

template< typename T >
struct CosmicMap
{
    CosmicList< CosmicList<T> > buckets;
    int numOfKeys;

    CosmicMap() : CosmicMap(17) {}

    CosmicMap( int n ) : numOfKeys(n) 
    {
        for( int i = 0; i <= n; ++i )
            buckets.append( new CosmicList<T> );
    }
 
    void insert( T* data )
    {
        buckets[hashFunc(data->label)]->data->append(data);
        Serial.println(data->label);
    }

    T* returnNode( char* s )
    {
        Node<T>* bucketNode = buckets[hashFunc(s)]->data->head;

        while( bucketNode )
        {
            if( bucketNode->data->label == s )
                return bucketNode->data;

            bucketNode = bucketNode->next;
        }

        return nullptr;
    }

    unsigned int hashFunc( char* s )
    {
        unsigned int hash = 5381;

        for( char* c = s; *c != '\0'; ++c )
            hash = (hash * 33) ^ *c;
            
        return hash % numOfKeys;
    }

    void printAll()
    {
        for( int i = 0; i < numOfKeys; ++i )
            buckets[i]->data->printAll();
    }
};
