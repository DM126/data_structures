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

Node* copy_node(Node* node)
{

}
