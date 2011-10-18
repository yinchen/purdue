#include <stdio.h>
#include <string.h>
#include <HashTable.h>

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
	
	return n % 5000;
}

HashTable::HashTable() {
	buckets = new HashTableE*[5000];
	
	// default lists to null
	int i;
	for (i = 0; i < 5000; i++)
	{
		buckets[i] = NULL;
	}
}

HashTable::insert(const char *key, char **data) {
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
	
	// scroll to end of list
	while (curr != NULL) {
		curr = curr->next;
	}
	
	// insert new entry
	HashTableE *e = new HashTableE();
	e->key = key;
	e->data = data;
	e->next = NULL;
	
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
		return true;
	}
	
	// search for key in list
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0) {
			last->next = curr->next;
			return true;
		}
		
		last = curr;
		curr = curr->next;
	}
	
	return false;
}

bool
HashTable::lookup(const char *key, char **data) {
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
