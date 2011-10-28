
// Implementation of a dictionary using an AVL tree
// AVL Trees are balanced binary trees 

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "avl-dictionary.h"

bool debug = false;

// Constructor
AVLDictionary::AVLDictionary()
{
	root = NULL;
	nElements = 0;
}

// Add a record to the dictionary. Returns false if key already exists
bool
AVLDictionary::addRecord( KeyType key, DataType record)
{
	if (debug)
	{
		printf("------------------------------------\n");
		printf("addRecord(\"%s\",%d)\n",  key, record);
		printf("---------- Before -----------------\n");
		printNode("", root, 0);
	}
	
	AVLNode *n;
	n = new AVLNode();
	
    n->key = key;
    n->data = record;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    if(root == NULL)
	{
        root = n;
		nElements++;
		
        return true;
    }

    AVLNode *curr;
	curr = root;
	
    AVLNode *prev;
	prev = NULL;
	
    while(curr != NULL)
	{
        prev = curr;
        if (strcmp(key, curr->key) < 0)
		{
            curr = curr->left;
        }
        else if (strcmp(key, curr->key) > 0)
		{
            curr = curr->right;
        }
        else
		{
            curr->data = record;
            return false;
        }
    }

    if (strcmp(key, prev->key) < 0)
	{
        prev->left = n;
    }
    else
	{
        prev->right = n;
    }

    n->parent = prev;

    AVLNode *m;
	m = n->parent;
	
    while(m != NULL)
	{
        int maxheight = 0;
        if(m->left != NULL)
            maxheight = m->left->height;
        if(m->right != NULL && maxheight < m->right->height)
            maxheight = m->right->height;
        m->height = 1+maxheight;
        m = m->parent;
    }

	if (debug)
	{
		printf("---------- Before Restructure -----------------\n");
		printNode("", root, 0);
	}
	
	restructure(n);

	if (debug)
	{
		checkRecursive(root);
		
		printf("---------- After Restructure -----------------\n");
		printNode("", root, 0);
	}
	
	nElements++;
		
	return true;
}

void
AVLDictionary::restructure(AVLNode * n)
{
	AVLNode *z;
	z = n->parent;
	
    while(z != NULL)
	{
        int heightleft = 0;
        if(z->left != NULL)
		{
            heightleft = z->left->height;
        }
		
        int heightright = 0;
        if(z->right != NULL)
		{
            heightright = z->right->height;
        }

        int heightdiff = heightleft - heightright;
        if(heightdiff < 0)
            heightdiff = -heightdiff;

        if(heightleft > heightright)
            z->height = 1+heightleft;
        else
            z->height = 1+heightright;

        if(heightdiff <= 1)
		{
            z = z->parent;
            continue;
        }

        AVLNode *y = NULL;
        int maxheight = 0;
        if(z->left != NULL)
		{
            y = z->left;
            maxheight = y->height;
        }
        if(z->right != NULL && z->right->height > maxheight)
		{
            y = z->right;
            maxheight = y->height;
        }

        AVLNode *x = NULL;
        maxheight = 0;
        if(y->left != NULL)
		{
            x = y->left;
            maxheight = x->height;
        }
        if(y->right != NULL && y->right->height > maxheight)
		{
            x = y->right;
            maxheight = x->height;
        }
        assert(x != NULL);

        AVLNode * a, * b, * c, * t0, * t1, * t2, * t3;
        if(z->right == y)
		{
            if(y->right == x)
			{
                a = z;
                b = y;
                c = x;
                t0 = z->left;
                t1 = y->left;
                t2 = x->left;
                t3 = x->right;
            }
            else
			{
                a = z;
                b = x;
                c = y;
                t0 = z->left;
                t1 = x->left;
                t2 = y->left;
                t3 = y->right;
            }
        }
        else 
		{
            if(y->left == x)
			{
                a = x;
                b = y;
                c = z;
                t0 = x->left;
                t1 = x->right;
                t2 = y->right;
                t3 = z->right;
            }
            else
			{
                a = y;
                b = x;
                c = z;
                t0 = y->left;
                t1 = x->left;
                t2 = x->right;
                t3 = z->right;
            }
        }

        AVLNode *p;
		p = z->parent;
        if(p == NULL)
		{
            root = b;
        }
        else
		{
            if(b->left == z)
                p->left = b;
            else
                p->right = b;
        }
		
        b->parent = p;
        b->left = a;
        b->right = c;
        a->parent = b;
        a->left = t0;
        a->right = t1;
        c->parent = b;
        c->left = t2;
        c->right = t3;

        if(t0 != NULL)
            t0->parent = a;
        if(t1 != NULL)
            t1->parent = a;
        if(t2 != NULL)
            t2->parent = c;
        if(t3 != NULL)
            t3->parent = c;

        maxheight = 0;
        if(a->left != NULL)
            maxheight = a->left->height;
        if(a->right != NULL && a->right->height > maxheight)
            maxheight = a->right->height;
        a->height = 1+maxheight;

        maxheight = 0;
        if(c->left != NULL)
            maxheight = c->left->height;
        if(c->right != NULL && c->right->height > maxheight)
            maxheight = c->right->height;
        c->height = 1+maxheight;

        maxheight = 0;
        if(b->left != NULL)
            maxheight = b->left->height;
        if(b->right != NULL && b->right->height > maxheight)
            maxheight = b->right->height;
        b->height = 1+maxheight;

        z = p;
    }
}

// Find a key in the dictionary and return corresponding record or NULL
DataType
AVLDictionary::findRecord( KeyType key)
{
    AVLNode *curr;
	curr = root;
	
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			return (DataType)curr->data;
		}
		else if (strcmp(curr->key, key) > 0)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}

	return NULL;
}

AVLNode*
AVLDictionary::findNode(KeyType key)
{
	AVLNode *n = root;
	while(n != NULL)
	{
		if (strcmp(n->key, key) == 0)
		{
			return n;
		}
		else if (strcmp(n->key, key) > 0)
		{
			n = n->left;
		}
		else 
		{
			n = n->right;
		}
	}
	
	return NULL;   
}

// Removes one element from the dictionary
bool
AVLDictionary::removeElement(KeyType key)
{
	if (debug)
	{
		printf("------------------------------------\n");
		printf("removeElement(\"%s\")\n",  key);
		printf("---------- Before -----------------\n");
		printNode("", root, 0);
	}

	AVLNode *node;
	node = findNode(key);
	
	if (node == NULL)
	{
     	return false;
    }
   
	if (node->left == NULL && node->right == NULL)
	{
		if ( node == node->parent->left)
		{
			node->parent->left = NULL;
		}
		else
		{
			node->parent->right = NULL;
		}

		AVLNode *m;
		m = node->parent;
		
		while(m != NULL)
		{
			int maxheight = 0;
			if(m->left != NULL)
			{
				maxheight = m->left->height;
			}
			if (m->right != NULL && maxheight < m->right->height)
			{
				maxheight = m->right->height;
			}
			m->height = maxheight +1;
			m = m->parent;
		}

		restructure(node->parent);

		delete node;
    }
	else if (node->left == NULL)
	{
	    AVLNode temp;
   	
     	temp.height = node->height;
     	strcpy((char*)temp.key, node->key);
     	temp.data = node->data;
      
     	node->height = node->right->height;
     	strcpy((char*)node->key, node->right->key);
     	node->data = node->right->data;
 
     	node->right->height = temp.height;
     	strcpy((char*)node->right->key, temp.key);
     	node->right->data = temp.data;
   
     	delete node->right;
   
     	node->right = NULL;   
   
     	AVLNode *m = node->parent;
     	while(m != NULL)
		{
     		int maxheight = 0;
     		if(m->left != NULL)
			{
     			maxheight = m->left->height;
     		}
     		if (m->right != NULL && maxheight < m->right->height)
			{
     			maxheight = m->right->height;
     		}
     		m->height = maxheight +1;
     		m = m->parent;
   
     	}
   
     	restructure(node);
    }
	else if (node->right == NULL)
	{
     	AVLNode temp;
   
     	temp.height = node->height;
     	strcpy((char*)temp.key, node->key);
     	temp.data = node->data;
 
     	node->height = node->left->height;
     	strcpy((char*)node->key, node->left->key);
     	node->data = node->left->data;
   
     	node->left->height = temp.height;
     	strcpy((char*)node->left->key, temp.key);
     	node->left->data = temp.data;
   
     	delete node->left;
   
     	node->left = NULL;   	
   
     	AVLNode *m;
		m = node->parent;
		
     	while(m != NULL)
		{
     		int maxheight = 0;
     		if( m->left != NULL)
			{
     			maxheight = m->left->height;
     		}
     		if (m->right != NULL && maxheight < m->right->height)
			{
     			maxheight = m->right->height;
     		}
     		m->height = maxheight +1;
     		m = m->parent;
   
     	}
   
     	restructure(node);
    }
	else
	{
		AVLNode *replacement;   
		replacement = node->left;
		
     	if (replacement->right == NULL)
		{
     		replacement = node->right;
     		while(replacement->left != NULL)
			{
     			replacement = replacement->left;
     		}
     	}
		else
		{
			while (replacement->right != NULL)
			{
     			replacement = replacement->right;
     		}
   
     	}
		
		AVLNode temp;
       
		temp.height = node->height;
     	strcpy((char*)temp.key, node->key);
     	temp.data = node->data;
   
     	node->height = replacement->height;
     	strcpy((char*)node->key, replacement->key);
     	node->data = replacement->data;
 	
     	replacement->height = temp.height;
     	strcpy((char*)replacement->key, temp.key);
     	replacement->data = temp.data;
   	
     	AVLNode *n;
		n = replacement->parent;
		
     	if (n != NULL)
		{
			if (replacement == n->left)
			{
     			n->left = NULL;   
     			delete replacement;
     		}
			else
			{
     			n->right = NULL;
     			delete replacement;
     		}
   
			AVLNode *m = n;
			while(m != NULL)
			{
				int maxheight = 0;
				if(m->left != NULL)
				{
					maxheight = m->left->height;
				}
				if (m->right != NULL && maxheight < m->right->height)
				{
					maxheight = m->right->height;
				}
				m->height = maxheight +1;
				m = m->parent;   
			}
	   
			restructure(n);
		}
	}
	
	nElements--;
	
	if (debug)
	{
		printf("---------- After -----------------\n");
		printNode("", root, 0);

		checkRecursive(root);
	}
	
	return true;
}

// Returns all the elements in the table as an array of strings.
// *n is the size of the table and it is returned by reference
KeyType *
AVLDictionary::keys(int * n)
{
	KeyType * a = (KeyType *) malloc(nElements * sizeof(KeyType));
	*n = 0;
	addKeysRecursive(root, a, n);

	return a;
}

// Add keys recursively
void
AVLDictionary::addKeysRecursive(AVLNode * node, KeyType * a, int * n)
{
	if (node==NULL)
	{
		return;
	}
	
	a[*n] = node->key;
	(*n)++;
	addKeysRecursive(node->left, a, n);
	addKeysRecursive(node->right, a, n);
}
