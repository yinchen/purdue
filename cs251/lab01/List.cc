//
// Implement the List class
//

#include <stdio.h>
#include "List.h"
#include <cstdlib>

//
// Inserts a new element with value "val" in
// ascending order.
//
void
List::insertSorted( int val )
{
  // Complete procedure 
}

//
// Inserts a new element with value "val" at
// the end of the list.
//
void
List::append( int val )
{
    ListNode *curr;
    curr = _head;
    
    while (curr->_next != NULL)
    {
        curr = curr->_next;
    }
    
    ListNode n;
    n._value = val;
    n._next = NULL;
    
    curr->_next = &n;
}

//
// Inserts a new element with value "val" at
// the beginning of the list.
//
void
List::prepend( int val )
{
    ListNode n;
    n._value = val;
    n._next = _head;
    
    _head = &n;
}

// Removes an element with value "val" from List
// Returns 0 if succeeds or -1 if it fails
int 
List::remove( int val )
{
    return 0;
}

// Prints The elements in the list. 
void
List::print()
{
    ListNode *curr;
    curr = _head;
    
    while (curr != NULL)
    {
        printf("%d\n", curr->_value);
    }
}

//
// Returns 0 if "value" is in the list or -1 otherwise.
//
int
List::lookup(int val)
{
    ListNode *curr;
    curr = _head;
    
    while (curr != NULL)
    {
        if (curr->_value == val)
        {
            return 0;
        }
        
        curr = curr->_next;
    }
    
    return -1;
}

//
// List constructor
//
List::List()
{
    ListNode curr;
    curr = (ListNode*)std::malloc(sizeof(ListNode));
    
    _head = curr;
}

//
// List destructor: delete all list elements, if any.
//
List::~List()
{
    ListNode* curr;
    curr = _head;
    
    while (curr != NULL)
    {
        ListNode* next;
        next = curr->_next;
        
        std::free(curr);
        
        curr = next;
    }
    
    _head = NULL;
}

