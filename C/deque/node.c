#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "../error.h"

Node* new_node(char* str)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		exit_with_error("new_node - Out of memory");
	}

	node->data = strdup(str);
	node->next = NULL;
	node->previous = NULL;

	return node;
}

void delete_node(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	delete_node(node->next);
	free(node->data);
	free(node);
}

Node* copy_node(const Node* other)
{
	char* new_string = strdup(other->data);
	Node* node = new_node(new_string);

	node->next = copy_node(other->next);
	node->previous = NULL;
	node->next->previous = node;

	return node;
}
