#include <stdio.h>
#include <Heap.h>

Heap::Heap() {
	max = 5000;
	heap = new HeapE[max];
	last = 0;
}

void
Heap::insert(const char *key, int data) {
	// insert new record at end
	HeapE e;
	e.key = key;
	e.data = data;
	heap[last] = e;
	last++;
	
	// travers "up-heap" to fix heap until we reach root
	int child = last - 1;
	int parent = hparent(child);	
	while (child > 0) {
		// check if we need to keep fixing
		if (heap[child].key > heap[parent].key) {
			break;
		}
		
		// swap parent and child
		HeapE tmp = heap[child];
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
	
	// get minimum key and data
	const char *key minKey = heap[0].key;
	int minData = heap[0].data;
	
	// put last element in use at top of heap
	heap[0] = heap[last - 1];
	last--;
	
	// traverse "down-heap" to fix heap until we reach bottom
	while (left < last) {
		// find smallest child
		int minChild = left;		
		if ((right < last) && (heap[right].key <= heap[left].key)) {
			minChild = right;
		}
		
		// check if we need to keep fixing
		if (heap[parent].key <= heap[minChild].key) {
			break;
		}
		
		// swap parent and smallest child
		HeapE tmp = heap[minChild];
		heap[minChild] = heap[parent];
		heap[parent] = tmp;
		
		// update parent
		parent = minChild;
		left = hleft(parent);
		right = hright(parent);
	}
	
	return minData;
}
