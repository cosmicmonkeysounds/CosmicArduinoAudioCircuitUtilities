template< class Type >
struct Node
{

    Type data;
    Node< Type > *next = nullptr, *prev = nullptr;

    Node( Type stuff ) : data( stuff ) {}

};

template< class Type >
struct LinkedList
{

    int length = 0;
    Node< Type > *head = nullptr, *tail = nullptr;

    void add( Type data )
    {
        if( this->head == nullptr ) 
        // if there is nothing in the list
        {
            this->head = new Node< Type >{ data };
            this->tail  = this->head;
        }
        else
        {

            if( this->head == this->tail ) 
            // if there is only one thing in the list
            {
                this->tail = new Node< Type >{ data };
                this->head->next = this->tail;
                this->tail->prev  = this->head;
            }
            else 
            // if there is more than one thing in the list
            {
                Node< Type > * newNode = new Node< Type >{ data };
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
            }

        }
        ++this->length; // increment the length after all that hubba-balloo
    }

    Type get( const int index )
    {
        if( index == 0 ) return this->head->data;
        else if( index >= this->length - 1 ) return this->tail->data;
        else
        {
            Node< Type > * curr = this->head->next;
            for ( int i = 1; i < index; ++i )
            {
                curr = curr->next;
            }
            return curr->data;
        }
    }

    Type operator[]( const int index ){ return this->get( index ); }

};
