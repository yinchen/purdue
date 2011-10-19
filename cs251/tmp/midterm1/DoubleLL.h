typedef struct DoubleLLE {
	int data;
	struct DoubleLLE *next;
	struct DoubleLLE *prev;
} DoubleLLE;

class DoubleLL {
	DoubleLLE *head;
	
	public:
		DoubleLL();
		~DoubleLL();
		
		void insertFront(int data);
		void insertEnd(int data);
		int removeFront();
		int removeEnd();
		bool isEmpty();
};
