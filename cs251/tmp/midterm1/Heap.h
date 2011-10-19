class Heap {
	int *heap;
	int last;
	int max;
	
	int hleft(int i) { return 2*i + 1; }
	int hright(int i) { return 2*i + 2; }
	int hparent(int i) { return (i - 1)/2; }
	
	public:
		Heap(int maxSize);
		~Heap();
		
		void insert(int key);
		int removeMin();
};
