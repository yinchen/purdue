
//
// CS251 Data Structures
// Hash Table
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Each hash entry stores a key, object pair
template <typename Data>
struct HashTableTemplateEntry {
  const char * _key;
  Data _data;
  HashTableTemplateEntry * _next;
};

// This is a Hash table that maps string keys to objects of type Data
template <typename Data>
class HashTableTemplate {
 public:
  // Number of buckets
  enum { TableSize = 2039};
  
  // Array of the hash buckets.
  HashTableTemplateEntry<Data> **_buckets;
  
  // Obtain the hash code of a key
  int hash(const char * key);
  
 public:
  HashTableTemplate();
  
  // Add a record to the hash table. Returns true if key already exists.
  // Substitute content if key already exists.
  bool insertItem( const char * key, Data data);

  // Find a key in the dictionary and place in "data" the corresponding record
  // Returns false if key is does not exist
  bool find( const char * key, Data * data);

  // Removes an element in the hash table. Return false if key does not exist.
  bool removeElement(const char * key);

  // Returns the data that corresponds to this index.
  // Data is initialized to 0s if the entry does not exist
  Data operator[] (const char * &key);
};

template <typename Data>
int HashTableTemplate<Data>::hash(const char * key)
{
    int h = 0;
    const char * p = key;
    while (*p) {
        h += *p;
        p++;
    }
    return h % TableSize;
}

template <typename Data>
HashTableTemplate<Data>::HashTableTemplate()
{
    _buckets = new HashTableTemplateEntry<Data>*[2039];
    
    int i;
    for (i = 0; i < 2039; i++)
    {
        _buckets[i] = NULL;
    }
}

template <typename Data>
bool HashTableTemplate<Data>::insertItem( const char * key, Data data)
{
    int h = hash(key);

    HashTableTemplateEntry<Data> *curr;
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
    
    HashTableTemplateEntry<Data> *newEntry = new HashTableTemplateEntry<Data>();
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

template <typename Data>
bool HashTableTemplate<Data>::find( const char * key, Data * data)
{
    int h = hash(key);
    
    HashTableTemplateEntry<Data> *curr;
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

template <typename Data>
Data HashTableTemplate<Data>::operator[] (const char * &key)
{
    Data d;
    
    if (find(key, &d) == true)
    {
        return d;
    }
    else
    {
        return NULL;
    }
}

template <typename Data>
bool HashTableTemplate<Data>::removeElement(const char * key)
{
    int h = hash(key);
    
    HashTableTemplateEntry<Data> *curr;
    curr = _buckets[h];
    
    HashTableTemplateEntry<Data> *last;
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

template <typename Data>
class HashTableTemplateIterator {
  int _currentBucket;
  HashTableTemplateEntry<Data> *_currentEntry;
  HashTableTemplate<Data> * _hashTable;
 public:
  HashTableTemplateIterator(HashTableTemplate<Data> * hashTable);
  bool next(const char * & key, Data & data);
};

template <typename Data>
HashTableTemplateIterator<Data>::HashTableTemplateIterator(HashTableTemplate<Data> * hashTable)
{
    _hashTable = hashTable;
    _currentBucket = 0;
    _currentEntry = NULL;
}

template <typename Data>
bool HashTableTemplateIterator<Data>::next(const char * & key, Data & data)
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
