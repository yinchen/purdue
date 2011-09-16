//
// CS251
// Implementation of a HashTable that stores void *
//

#include <stdlib.h>
#include <string.h>
#include "HashTableVoid.h"

// Obtain the hash code of a key
int HashTableVoid::hash(const char * key)
{
    int n;
    n = 0;
    
    int l;
    l = strlen(key);
    
    int i;
    for (i = 0; i < l; i++)
    {
        n += (i + 1) * key[i];
    }
    
    return n % 2039;
}

// Constructor for hash table. Initializes hash table
HashTableVoid::HashTableVoid()
{
    _buckets = new HashTableVoidEntry*[2039];
    
    int i;
    for (i = 0; i < 2039; i++)
    {
        _buckets[i] = NULL;
    }
}

// Add a record to the hash table. Returns true if key already exists.
// Substitute content if key already exists.
bool HashTableVoid::insertItem( const char * key, void * data)
{
    int h = hash(key);

    HashTableVoidEntry *curr;
    curr = _buckets[h];
    
    while (curr != NULL)
    {
        if (strcmp(curr->_key, key) == 0)
        {
            curr->_data = data;
            return true;
        }
        
        curr = curr->_next;
    }
    
    curr = _buckets[h];
    
    while (curr != NULL)
    {
        curr = curr->_next;
    }
    
    HashTableVoidEntry *newEntry = new HashTableVoidEntry();
    newEntry->_key = key;
    newEntry->_data = data;
    newEntry->_next = NULL;
    
    if (curr == NULL)
    {
        _buckets[h] = newEntry;
    }
    else
    {
        curr->_next = newEntry;
    }
    
    return false;
}

// Find a key in the dictionary and place in "data" the corresponding record
// Returns false if key is does not exist
bool HashTableVoid::find( const char * key, void ** data)
{
    int h = hash(key);
    
    HashTableVoidEntry *curr;
    curr = _buckets[h];
    
    while (curr != NULL)
    {
        if (strcmp(curr->_key, key) == 0)
        {
            *data = curr->_data;
            return true;
        }
        
        curr = curr->_next;
    }
  
    return false;
}

// Removes an element in the hash table. Return false if key does not exist.
bool HashTableVoid::removeElement(const char * key)
{
    int h = hash(key);
    
    HashTableVoidEntry *curr;
    curr = _buckets[h];
    
    HashTableVoidEntry *last;
    last = NULL;
    
    if (curr == NULL)
        return false;
    
    if (strcmp(curr->_key, key) == 0)
    {
        _buckets[h] = curr->_next;
        return true;
    }
    
    while (curr != NULL)
    {
        if (strcmp(curr->_key, key) == 0)
        {
            last->_next = curr->_next;
            return true;
        }
        
        last = curr;
        curr = curr->_next;
    }
  
    return false;
}

// Creates an iterator object for this hash table
HashTableVoidIterator::HashTableVoidIterator(HashTableVoid * hashTable)
{
    _hashTable = hashTable;
    _currentBucket = 0;
    _currentEntry = NULL;
}

// Returns true if there is a next element. Stores data value in data.
bool HashTableVoidIterator::next(const char * & key, void * & data)
{
    if (_currentEntry != NULL) // first run
    {
        if (_currentEntry->_next != NULL)
        {
            key = _currentEntry->_next->_key;
            data = _currentEntry->_next->_data;
            
            _currentEntry = _currentEntry->_next;
            
            return true;
        }
    }
    
    int i;
    i = _currentBucket + 1;
    
    while (i < 2039 &&
           _hashTable->_buckets[i] == NULL)
    {
        i++;
    }
    
    if (i < 2039 &&
        _hashTable->_buckets[i] != NULL)
    {
        key = _hashTable->_buckets[i]->_key;
        data = _hashTable->_buckets[i]->_data;
    
        _currentBucket = i;
        _currentEntry = _hashTable->_buckets[i];
    
        return true;
    }
    
    return false;
}

