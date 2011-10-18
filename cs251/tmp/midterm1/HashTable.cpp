#include <stdio.h>
#include <string.h>
#include "HashTable.h"

int
HashTable:hash(const char *key) {
	int n;
	n = 0;
	
	int l;
	l = strlen(key);	
	
	int i;
	for (i = 0; i < l; i++)
	{
		n += (i + 1) * key[i];
	}
	
	return n % size;
}

HashTable::HashTable() {
	size = 5000;
	currSize = 0;
	buckets = new HashTableE*[size];
	
	// default lists to null
	int i;
	for (i = 0; i < size; i++)
	{
		buckets[i] = NULL;
	}
}

HashTable::insert(const char *key, void *data) {
	int h = hash(key);
	
	HashTableE *curr;
	curr = buckets[h];
	
	// check if key already exists
	while (curr != NULL) {
		if (strcmp(curr->key, key) == 0)
		{
			curr->data = data;
			return true;
		}
		
		curr = curr->next;
	}
	
	curr = buckets[h];
	
	// check if the hash table is full
	if (currSize == size) {
		rehash();
	}
	
	// scroll to end of list
	while (curr != NULL) {
		curr = curr->next;
	}
	
	// insert new entry
	HashTableE *e = new HashTableE();
	e->key = key;
	e->data = data;
	e->next = NULL;
	currSize++;
	
	// check if this is first entry
	if (curr == NULL) {
		buckets[h] = e;
	}
	else {
		curr->next = e;
	}
	
	return false;
}

bool
HashTable::remove(const char *key) {
	int h = hash(key);
	
	HashTableE *curr;
	curr = buckets[h];
	
	HashTableE *last;
	last = NULL;
	
	// check if list is empty
	if (curr == NULL)
		return false;
	
	// check if this is first entry
	if (strcmpy(curr->key, key) == 0) {
		buckets[h] = curr->next;
		currSize--;
		return true;
	}
	
	// search for key in list
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0) {
			last->next = curr->next;
			currSize--;
			return true;
		}
		
		last = curr;
		curr = curr->next;
	}
	
	return false;
}

bool
HashTable::lookup(const char *key, void *data) {
	int h = hash(key);
	
	HashTableE *curr;
	curr = buckets[h];
	
	// search for key in list
	while (curr != NULL) {
		if (strcmp(curr->key, key) == 0) {
			*data = curr->data;
			return true;
		}
		
		curr = curr->next;
	}
	
	return false;
}

void HashTable::rehash() {
	int oldSize;
	oldSize = size;
	
	// reallocate hash table size
	size = 2 * size;	
	HashTableE **newBuckets = new HashTableE*[size];
	
	// default lists to null
	int i;
	for (i = 0; i < oldSize; i++) {
		buckets[i] = NULL;
	}
	
	// copy old elements into new table
	int j;
	for (j = 0; j < size; j++) {
		HashTableE *e;
		e = buckets[j];
		
		// loop through the current list
		while (e != NULL) {
			HashTableE *next = e->next;
			int h = hash(e->key);
			e->next = newBuckets[h];
			newBuckets[h] = e;
			e = next;
		}
	}
	
	// replace existing hash table with new hash table
	free(buckets);
	buckets = newBuckets;
}
