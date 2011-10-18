typedef struct HashTableE {
	const char *key;
	char **data;
	HashTableE *next;
} HashTableE;

class HashTable {
	HashTableE **buckets;
	int hash(const char *key);
	
	public:
		HashTable();
		~HashTable();
		
		bool insert(const char *key, char **data);
		bool remove(const char *key);
		bool lookup(const char *key, char **data);
};
