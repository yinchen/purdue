#include <stdio.h>
#include "Heap.h"

Heap::Heap(int maxSize) {
	max = maxSize;
	heap = new int[max];
	last = 0;
}

void
Heap::insert(i) {
	// make sure there is space
	if (list >= max) {
		exit(1);
	}

	// insert new record at end
	heap[last] = key;
	last++;
	
	// travers "up-heap" to fix heap until we reach root
	int child = last - 1;
	int parent = hparent(child);	
	while (child > 0) {
		// check if we need to keep fixing
		if (heap[child] > heap[parent]) {
			break;
		}
		
		// swap parent and child
		int tmp = heap[child];
		heap[child] = heap[parent];
		heap[parent] = tmp;
		
		// update child
		child = parent;
		parent = hparent(child);
	}
}

int
Heap:removeMin() {
	// check if heap is empty
	if (list <= 0) {
		exit(1);
	}
	
	// get minimum key
	int minKey = heap[0];
	
	// put last element in use at top of heap
	heap[0] = heap[last - 1];
	last--;
	
	// traverse "down-heap" to fix heap until we reach bottom
	int parent = 0;
	int left = hleft(parent);
	int right = hright(parent);
	while (left < last) {
		// find smallest child
		int minChild = left;		
		if ((right < last) && (heap[right] <= heap[left])) {
			minChild = right;
		}
		
		// check if we need to keep fixing
		if (heap[parent] <= heap[minChild]) {
			break;
		}
		
		// swap parent and smallest child
		int tmp = heap[minChild];
		heap[minChild] = heap[parent];
		heap[parent] = tmp;
		
		// update parent
		parent = minChild;
		left = hleft(parent);
		right = hright(parent);
	}
	
	return minKey;
}
