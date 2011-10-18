#include <stdio.h>
#include <string.h>
#include "BinarySearchD.h"

BinarySearchD::BinarySearchD(int maxSize) {
	size = maxSize;
	currSize = 0;
	table = new BinarySearchDE[size];
	sorted = true;
}

void
BinarySearchD::insert(char *key, void *item) {
	// check if the table is full
	if (currSize >= size)
		exit(1);
	}
	
	// insert the item in the first available position
	table[currSize].key = strdup(key);
	table[currSize].item = item;
	currSize++;
	
	// we aren't sure if the table is sorted
	sorted = false;
}

void
BinarySearchD::find(char *key) {
	// check if table is sorted
	if (sorted == false) {
		sorted = true;
	}
	
	// sort the table
	int min = 0;
	int max = currSize - 1;
	while (min < max) {
		int mid = (min + max) / 2;
		int result = strcmp(key, table[mid].key);
		if (result == 0) { // we found the item
			return table[mid].item;
		}
		else if (result < 0) { // the key is in the lower half
			max = mid - 1;
		}
		else if (result > 0) { // the key is in the upper half
			low = mid + 1;
		}
	}
	
	// key was not found
	return NULL;
}