//Node used for linked lists

#ifndef NODE_H
#define NODE_H

typedef struct Node_struct Node;

struct Node_struct
{
	char* data;
	Node* next;
	Node* previous;
};

//Creates a new node with the given value as its data
Node* new_node(char* str);

//Frees a node and all its subsequent nodes
void delete_node(Node* node);

//Performs a deep copy of single node
Node* copy_node(const Node* other);

#endif
