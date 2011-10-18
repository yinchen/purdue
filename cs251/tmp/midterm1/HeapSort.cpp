#include "Heap.h"

void heapSort(int a[], int n) {
	Heap heap(n);
	
	// insert elements into the heap
	int i;
	for (i = 0; i < n; i++) {
		heap.insert(a[i]);
	}
	
	// remove elements from the heap
	for (i = 0; i < n; i++) {
		a[i] = heap.removeMin();
	}
}