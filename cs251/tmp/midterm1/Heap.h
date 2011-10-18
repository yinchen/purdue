typedef struct HeapE {
	const char *key;
	int data;
} HeapE;

class Heap {
	HeapE *heap;
	int last;
	int max;
	
	int left(int i) { return 2*i + 1; }
	int right(int i) { return 2*i + 2; }
	int parent(int i) { return (i - 1)/2; }
	
	public:
		Heap();
		~Heap();
		
		void insert(const char *key, int data);
		int removeMin();
		int size() { return last; }
};
