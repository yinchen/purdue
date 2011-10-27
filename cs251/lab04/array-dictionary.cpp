
// Implementation of a dictionary using an array and sequential search
// The array will be dynamically resized if necessary

#include <stdlib.h>
#include <string.h>

#include "array-dictionary.h"

// Constructor
ArrayDictionary::ArrayDictionary()
{
	maxNumber = 100;
	currentNumber = 0;
	
	array = new ArrayDictionaryNode[maxNumber];	
}

// Add a record to the dictionary. Returns false if key already exists
bool
ArrayDictionary::addRecord( KeyType key, DataType record)
{
    if (findRecord(key) != NULL)
	{
		return false;
	}
	
	if (currentNumber == maxNumber)
	{
		int currSize = maxNumber;
		maxNumber = maxNumber * 2;
		
		ArrayDictionaryNode *tmp = new ArrayDictionaryNode[maxNumber];
		
		int i;
		for (i = 0; i < currSize; i++)
		{
			tmp[i].key = (char*)malloc(sizeof(char)*25);
			strcpy(tmp[i].key, array[i].key);
			tmp[i].data = new DataType;
			tmp[i].data = (DataType*)array[i].data;
		}
		
		delete [] array;
		
		array = tmp;
	}
	
	array[currentNumber].key = (char*)malloc(sizeof(char)*25);
	strcpy(array[currentNumber].key, key);
	array[currentNumber].data = new DataType;
	array[currentNumber].data = (DataType*)record;
	currentNumber++;
	
	return true;
}

// Find a key in the dictionary and return corresponding record or NULL
DataType
ArrayDictionary::findRecord(KeyType key)
{
	int i;
	for (i = 0; i < currentNumber; i++)
	{
		if (strcmp(array[i].key, key) == 0)
		{
			return (DataType*)array[i].data;
		}
		
		i++;
	}
	
	return NULL;
}

// Removes one element from the table
bool
ArrayDictionary::removeElement(KeyType key)
{
    // add your code here
	
	return true;
	
}

// Returns all the elements in the table as an array of strings.
// *n is the size of the table and it is returned by reference
KeyType *
ArrayDictionary::keys(int * n)
{
    KeyType* data = new KeyType[currentNumber];
	
	int i;
	for (i = 0; i < currentNumber; i++)
	{
		data[i] = (char*)malloc(sizeof(char)*20);
		strcpy((char*)data[i], array[i].key);
	}
	
	*n = currentNumber;
	
	return data;
}
