//Node used for linked lists

#ifndef NODE_H
#define NODE_H

typedef struct Node_struct Node;

struct Node_struct
{
	int data;
	Node* next;
};

//Creates a new node with the given value as its data
Node* new_node(int value);

//Frees a node and all its subsequent nodes
void delete_node(Node* node);

//Performs a deep copy of a node
Node* copy_node(Node* node);

#endif
