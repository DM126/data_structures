#include <stdlib.h>

#include "node.h"
#include "../error.h"

Node* new_node(int value)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		exit_with_error("new_node - Out of memory");
	}

	node->data = value;
	node->next = NULL;

	return node;
}

void delete_node(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	delete_node(node->next);
	free(node);
}

Node* copy_node(Node* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Node* node = new_node(other->data);
	node->next = copy_node(other->next);

	return node;
}
