//Implementation of a basic (unbalanced) binary search tree.
//Duplicate values are not allowed.

#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include "treenode.h"

struct Tree_struct
{
	int size; //number of items in the tree
	Node* root;
};
typedef struct Tree_struct Tree;

//Create a new tree
//Will never return NULL, Exits if malloc fails.
Tree* new_tree(void);

//Frees the tree and all of its nodes
void delete_tree(Tree* tree);

//Returns a deep copy of the tree
Tree* copy_tree(Tree* other);


//Adds a value to the tree
bool insert(Tree* tree, int value);

//Returns true if the value exists in the tree
bool find(Tree* tree, int value);

//Removes a specific value from the tree, returns false if the value is not present
bool delete(Tree* tree, int value);

//Returns the value at the head of the tree without removing it.
//Exits program if tree is null or empty.
int peek(Tree* tree);

//Returns true if the tree is null or has no items TODO NULL?
bool isEmpty(Tree* tree);

//Removes all items from the tree.
//Exits the program if the tree is null.
void clear(Tree* tree);

//Tree traversals, returns an array of ints determined by traversal order
//return NULL if tree is NULL or empty
int* inorder(Tree* tree);
int* preorder(Tree* tree);
int* postorder(Tree* tree);

//Print the tree's info, used for debugging
void dump(Tree* tree);

#endif
