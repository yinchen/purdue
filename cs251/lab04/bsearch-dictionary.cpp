
// Implementation of a dictionary using an array and binary search
// It will inherit from the ArrayDictionary

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bsearch-dictionary.h"

// Constructor
BinarySearchDictionary::BinarySearchDictionary()
{
	sorted = false;
}

bool
BinarySearchDictionary::addRecord(KeyType key, DataType record)
{
	sorted = false;
	return ArrayDictionary::addRecord(key, record);
}

// Find a key in the dictionary and return corresponding record or NULL
DataType
BinarySearchDictionary::findRecord(KeyType key)
{
	if (!sorted)
	{
		sort();
		sorted = true;
	}
	
	int min, max;
	min = 0;
	max = currentNumber - 1;
	
	while (max >= min)
	{
		int mid = (min + max) / 2;
		int result = strcmp(key, array[mid].key);
		
		if (result == 0)
		{
			return (DataType)array[mid].data;
		}
		else if (result < 0)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}

	return NULL;
}


// Sort array using heap sort
void
BinarySearchDictionary::sort()
{
	int i;
	
	ArrayDictionaryNode temp;
	
	for (i = currentNumber / 2; i >= 0; i--)
	{
		siftDown(i, currentNumber - 1);
	}
	
	for (i = currentNumber - 1; i >= 1; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		siftDown(0, i - 1);
	}
}

void
BinarySearchDictionary::siftDown(int root, int bottom)
{
	int complete;
	
	int max;
	
	ArrayDictionaryNode temp;
	
	complete = 0;
	while ((root * 2) <= bottom && complete == 0)
	{
		if ((root * 2) == bottom)
		{
			max = (root * 2);
		}
		else if (strcmp(array[(root * 2)].key, array[(root * 2) + 1].key) > 0)
		{
			max = (root * 2);
		}
		else
		{
			max = (root * 2) + 1;
		}
		
		if (strcmp(array[root].key, array[max].key) < 0)
		{
			temp = array[root];
			array[root] = array[max];
			array[max] = temp;
			root = max;
		}
		else
		{
			complete = 1;
		}
	}
}
