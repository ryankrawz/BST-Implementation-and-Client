// Binary Search Tree Implementation
// Ryan Krawczyk (CSCI227103)

#include "bst.h"
#include <stdlib.h>

// Dynamically allocates memory for BSTnode structure
BSTnode *createNode(void *item) {
	BSTnode *node = (BSTnode *) malloc(sizeof(BSTnode));
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Recursively walks through tree based on comparator to locate key
BSTnode *find(BSTnode *n, void *item, int compare(void *, void *)) {
	int cmp = compare(item, n->item);
	if (cmp < 0) {
		if (n->left != NULL) return find(n->left, item, compare);
	} else if (cmp > 0) {
		if (n->right != NULL) return find(n->right, item, compare);
	}
	return n;
}

// Recursively walks through tree based on comparator to insert new node
void insert(BSTnode *n, void *item, int compare(void *, void *)) {
	int cmp = compare(item, n->item);
	if (cmp < 0) {
		if (n->left == NULL)	n->left = createNode(item);
		else 					insert(n->left, item, compare);
	} else if (cmp > 0) {
		if (n->right == NULL) 	n->right = createNode(item);
		else 					insert(n->right, item, compare);
	}
	return;
}

