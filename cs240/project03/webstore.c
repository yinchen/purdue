/* webstore.c */

#include <stdio.h>
#include <string.h>
#include "webstore.h"

// internal helper functions
void printProductInfo(struct Product *p);
void printProducts(struct ProductList *p);
struct Categories* searchCategory(char *name, struct Categories **head);



/* Remove the product from inventory since it is sold now.
 * Input:
 *   - product_id: product identifier
 *   - clist: linked list of categories
 * Return value: 1 on success, 0 on failure
 * Error messages:
 * -   ERROR: Product <product_id> not found
 **/
int buyProduct(int product_id, struct Categories **clist) {
	/* TODO: Implement this */
	return 1;
}


/* Add a product to the inventory.
 * If the category does not exist, add the category first and then the product. 
 * Input:
 *   - clist: linked list of categories
 *   - id: product id
 *   - name: name of the product
 *   - price: price of the product
 *   - vendor: name of the vendor
 *   - numCategory: number of categories this product belongs to
 *   - nameCategories: name of categories this product belongs to.
 * Return value: 1 on success, 0 on failure
 * Error Message:
 * -   ERROR: malloc failed
 * */
int addProduct(struct Categories **clist, int id, char *name, double price, char *vendor, 
		int numCategory, char **nameCategories) {
	/* TODO: Implement this */
	return 1;
}

/* Search for products in a category with max price and print the result
 * Input:
 * -  categoryName: name of the category in which product is to be searched
 * -  max_price: maximum price for the product to be searched
 * -  clist: head of the linked list of categories
 * Output:
 *    Print the found products using printProductInfo() method
 * Error Messages:
 * -  ERROR: Category <category-name> not found
 * -  ERROR: No product found 
 * */
void search(char *categoryName, double max_price, struct Categories *clist) {
	/* TODO: Implement this */
}

/* Print information about a product
 * (USE THIS TO PRINT SEARCH RESULTS)
 * */

void printProductInfo(struct Product *p) {
	printf("%s, id: %d, Price: %0.2lf, Vendor: %s\n",p->name, p->id, p->price, p->vendor);
}

/* Print utility */
void printStore(struct Categories *c) {
	printf("Printing store ...\n");
	while (c != NULL) {
		printf("\nCATEGORY - %s:\n", c->name);
		printf("--------------------------\n");
		printProducts(c->products);
		c = c->next;
	}
	printf("\n");
}

void printProducts(struct ProductList *p) {
	while (p != NULL) {
		if (p->product != NULL) {
			printf("%s (id:%d)\n",p->product->name, p->product->id);
		}
		p = p->next;
	}
}

/* Adds a new category to the head of the list.
 * Input: 
 *   - name: name of the category
 *   - clist: existing linked list of categories
 * Return value: 1, if successfully added;
 *               0 otherwise.
 * Possible Error messages:
 * -  ERROR: Category already exists
 * -  ERROR: malloc failed
 * */
int addCategory(char *name, struct Categories **clist) {
	// check if the category already exists
	if(searchCategory(name, clist) != NULL) {
		printf("ERROR: Category already exists\n");
		return 0;
	}

	// create a new node for Categories
	struct Categories *newNode;
	newNode = (struct Categories*)malloc(sizeof(struct Categories));
	if (newNode == NULL) {
		printf("ERROR: malloc failed\n");
		return 0;
	}
	strcpy(newNode->name, name);
	newNode->products = NULL;
	newNode->next = *clist;
	*clist = newNode;
	return 1;
}


/* Removes a category, and all products belonging to that category 
 * if they do not belong to any other category
 * Input: 
 *   - name: name of the category to be removed
 *   - clist: existing linked list of categories
 * Return value: number of products removed
 * Error messages:
 * -  ERROR: Category does not exist
 * */
int removeCategory(char *name, struct Categories **clist) {
	int count = 0;
	// check if the category exists
	struct Categories *c = searchCategory(name, clist);
	if (c == NULL) {
		printf("ERROR: Category does not exist\n");
		return 0;
	}

	struct ProductList *p = c->products;
	struct ProductList *temp;
	while (p != NULL) {
		if (p->product->numCategory == 1) {// free the product if it is not in any other category
			free(p->product);
			count++;
		} else
			--(p->product->numCategory);
		temp = p;
		p = p->next;
		free(temp); // free the ProductList node
	}
	c->products = NULL;

	// remove c from the list
	struct Categories *temp1 = *clist;
	if (temp1 == c) { //removing the head node
		*clist = temp1->next;
	} else {
		while (temp1->next != c) temp1 = temp1->next;
		temp1->next = temp1->next->next;
	}
	free(c);
	return count;
}

/* Return the category with the given name, NULL if not found */
struct Categories* searchCategory(char *name, struct Categories **head) {
	struct Categories *temp = *head;
	while (temp != NULL) {
		if (strcmp(name, temp->name) == 0) return temp;
		temp = temp->next;
	}
	return NULL;
}

