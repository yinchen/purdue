struct BinarySearchDE {
	char *key;
	void *item;
};

class BinarySearchD {
	int size;
	int currSize;
	
	BinarySearchDE *table;
	bool sorted;
	
	public:
		BinarySearchD(int maxSize);
		~BinarySearchD;
		
		void insert(char *key, void *item);
		void *find(char *key);
}