typedef struct HashTableE {
	const char *key;
	void *data;
	HashTableE *next;
} HashTableE;

class HashTable {
	HashTableE **buckets;
	int size;
	int currSize;
	
	int hash(const char *key);	
	void rehash();
	
	public:
		HashTable();
		~HashTable();
		
		bool insert(const char *key, void *data);
		bool remove(const char *key);
		bool lookup(const char *key, void *data);
};
