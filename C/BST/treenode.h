//Node used for binary trees

#ifndef TREENODE_H
#define TREENODE_H

#include <stdbool.h>

typedef struct Node_struct Node;

struct Node_struct
{
	int data;
	Node* left;
	Node* right;
};

//Creates a new node with no children and with the given value as its data
Node* new_node(int value);

//Frees a node and all of its children
void delete_node(Node* node);

//Performs a deep copy of a node and all of its children
Node* copy_node(const Node* node);

//Inserts a value into one of the nodes children
bool insert_node(Node* node, int value);

//Searches for a node with the given value
bool find_node(const Node* node, int value);

//Searches for and removes the node with the given value.
//Moves the right child node up into its place.
//Parent is the parent of the current node being looked at.
bool remove_node(Node* node, Node* parent, int value);

//Finds the minimum value in a subtree, returns its value and removes its node
//Node starts as the right child of the found node, 
//but is used to keep track of current location
int swap_minimum(Node* node, Node* parent);

//does an recursive inorder traversal of the subtree, adding items to the array as it goes
//Current is the number of items currently in the array
//Returns the new current value after adding from subtree
int inorder_node(const Node* node, int* array, int current);
int preorder_node(const Node* node, int* array, int current);
int postorder_node(const Node* node, int* array, int current);

#endif
