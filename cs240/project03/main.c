#include <stdio.h>
#include <assert.h>

#include "webstore.h"

/* Test for addProduct */
void test1() {
	struct Categories *head = NULL;
	char *names[] = {"Electronics", "Books", "Computers", "Grocery"};

	addCategory("Computers",&head);
	// add to existing category
	addProduct(&head, 1, "DELL Laptop", 799.00, "Dell", 1, names+2); // add to computers

	// add to a category that does not exist yet (create this category first)
	addProduct(&head, 2, "Programming in C", 60.00, "ABC-Bookstore", 1, names+1); // add to books
	addProduct(&head, 3, "IPOD Shuffle", 49.00, "Apple", 1, names); // add to electronics
	addProduct(&head, 4, "Canon SD1300 IS", 229.00, "Amazon", 1, names); // add to electronics

	// add to multiple categories
	addProduct(&head, 5, "Amazon Kindle", 139.00, "Amazon", 2, names); //add to electronics, books

	printStore(head);
}

/* Test for search category */
void test2() {
	printf("\nsearch(\"ABC\",150,NULL):\n");
	search("ABC",150, NULL); // Category not found

	struct Categories *head = NULL;
	char *names[] = {"Electronics", "Books", "Computers", "Grocery"};
	
	addCategory("Electronics",&head);
	addCategory("Books",&head);
	addCategory("Computers",&head);

	printf("\nsearch(\"XYZ\",22,head):\n");
	search("XYZ", 22, head); // Category not found

	printf("\nsearch(\"Books\", 50, head):\n");
	search("Books", 50, head); // Product not found

	addProduct(&head, 2, "Programming in C", 60.00, "ABC-Bookstore", 1, names+1);
	addProduct(&head, 3, "IPOD Shuffle", 49.00, "Apple", 1, names);
	addProduct(&head, 4, "Amazon Kindle", 139.00, "Amazon", 2, names);

	printf("\nsearch(\"Books\", 40, head):\n");
	search("Books", 40, head); // Product not found
	printf("\nsearch(\"Books\", 100, head):\n");
	search("Books", 100, head); // Programming in C
	printf("\nsearch(\"Books\", 200, head):\n");	
	search("Books", 200, head); // Programming in C and Amazon kindle
}

/* Test for BuyProduct */
void test3() {
	struct Categories *head = NULL;
	char *names[] = {"Electronics", "Books", "Computers"};

	buyProduct(3,&head); // ERROR: Product 3 not found	
	addProduct(&head, 1, "Canon SD1300 IS", 229.00, "Amazon", 1, names); // add to electronics
	addProduct(&head, 2, "Programming in C", 60.00, "ABC-Bookstore", 1, names+1); // add to books
	addProduct(&head, 3, "IPOD Shuffle", 49.00, "Apple", 1, names); // add to electronics
	addProduct(&head, 4, "Amazon Kindle", 139.00, "Amazon", 2, names); //add to electronics, books

	buyProduct(8,&head); // ERROR: Product 8 not found
	buyProduct(3,&head); // Removes 'IPOD Shuffle' from electronics
	printStore(head);
	buyProduct(4, &head); // REmoves 'Kindle' from electronics and books
	printStore(head);

}

/* Test for error cases */
void test4() {
	struct Categories *head = NULL;
	char *names[] = {"Electronics", "Books", "Computers", "Grocery"};

	addProduct(&head, 1, "Canon SD1300 IS", 229.00, "Amazon", 1, names);
	addCategory("Electronics",&head);
	addCategory("Books",&head);
	addCategory("Computers",&head);

	addProduct(&head, 2, "Programming in C", 60.00, "ABC-Bookstore", 1, names+1);
	addProduct(&head, 3, "IPOD Shuffle", 49.00, "Apple", 1, names);
	addProduct(&head, 4, "Amazon Kindle", 139.00, "Amazon", 2, names);
	addProduct(&head, 5, "Apples", 3.49, "Walmart", 1, names+3);
	printStore(head);

	printf("\nSearch before buying product 1\n");
	search("Electronics", 300.00, head);
	buyProduct(1,&head);
	printf("\nSearch after buying product 1\n");
	search("Electronics", 300.00, head);
	buyProduct(1,&head);
	
	removeCategory("Electronics", &head);
	buyProduct(1,&head);

	printStore(head);
}

int main(int argc, char **argv) {
	assert(argc==2);
	char *ch = argv[1];
	int choice = atoi(ch);

	printf("Executing test case %d\n", choice);
	switch(choice) {
	case 1: test1();
		break;
	case 2: test2();
		break;
	case 3: test3();
		break;
	case 4: test4();
		break;
	default: printf("Testcase not defined\n");
	}
	
	return 0;
}


