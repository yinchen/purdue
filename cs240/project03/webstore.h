/* webstore.h
 */

/* This struct stores the information relevant to a product */
struct Product {
	int id;		/* product identifier */
	char name[100];	/* Product name */
	double price;	/* Price of product */
	char vendor[25];/* Vendor name */
	int numCategory;/* Number of categories this product in registered in */
};

/* ProductList is a linked list of products.
 * Here, data stored in each node is of type struct Pointer*,
 * and 'next' is a pointer to next node in the list 
 * */
struct ProductList {
	struct Product *product;
	struct ProductList *next;
};

/* This is a linked list of categories. 
 * Note that a product may belong to more than one category */
struct Categories {
	char name[15];	/* Name of the category */
	struct ProductList *products; /* Pointer to the linked list of products belonging to this category */
	struct Categories *next;
};


/* Remove the product from inventory since it is sold now.
 * Input:
 *   - product_id: product identifier
 *   - clist: linked list of categories
 * Return value: 1 on success, 0 on failure
 * Error messages:
 * -   ERROR: Product <product-id> not found
 **/
int buyProduct(int product_id, struct Categories **clist);

/* Add a product to the inventory 
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
int addProduct(struct Categories **clist, int id, char *name, double price, char *vendor, int numCategory, char **nameCategories);

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
void search(char *categoryName, double max_price, struct Categories *clist);


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
int addCategory(char *name, struct Categories **clist);

/* Removes a category, and all products belonging to that category 
 * if they do not belong to any other category
 * Input: 
 *   - name: name of the category to be removed
 *   - clist: existing linked list of categories
 * Return value: number of products removed
 * Error messages:
 * -  ERROR: Category does not exist
 * */
int removeCategory(char *name, struct Categories **clist);

/* Print utility */
void printStore(struct Categories *c);
