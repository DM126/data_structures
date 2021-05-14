#include <stdlib.h>

#include "treenode.h"
#include "../error.h"

Node* new_node(int value)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		exit_with_error("new_node - Out of memory");
	}

	node->data = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void delete_node(Node* node)
{
	if (node == NULL)
	{
		return;
	}

	delete_node(node->left);
	delete_node(node->right);
	free(node);
}

Node* copy_node(const Node* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Node* node = new_node(other->data);
	node->left = copy_node(other->left);
	node->right = copy_node(other->right);

	return node;
}


bool insert_node(Node* node, int value)
{
	if (node == NULL)
	{
		exit_with_error("insert_node - node is null");
	}

	bool inserted = false;
	if (value < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new_node(value);
			inserted = true;
		}
		else
		{
			inserted = insert_node(node->left, value);
		}
	}
	else if (value > node->data)
	{
		if (node->right == NULL)
		{
			node->right = new_node(value);
			inserted = true;
		}
		else
		{
			inserted = insert_node(node->right, value);
		}
	}

	return inserted;
}

bool find_node(const Node* node, int value)
{
	bool found;
	if (node == NULL)
	{
		found = false;
	}
	else if (value < node->data)
	{
		found = find_node(node->left, value);
	}
	else if (value > node->data)
	{
		found = find_node(node->right, value);
	}
	else //value == node->data
	{
		found = true;
	}

	return found;
}

bool remove_node(Node* node, Node* parent, int value)
{
	bool removed;
	if (node == NULL)
	{
		removed = false;
	}
	else if (value < node->data)
	{
		removed = remove_node(node->left, node, value);
	}
	else if (value > node->data)
	{
		removed = remove_node(node->right, node, value);
	}
	else //value == node->data
	{
		Node* node_to_move_up;
		if (node->left == NULL && node->right == NULL)
		{
			node_to_move_up = NULL;
		}
		else if (node->left == NULL)
		{
			node_to_move_up = node->right;
		}
		else if (node->right == NULL)
		{
			node_to_move_up = node->left;
		}
		else //2 children
		{
			node->data = swap_minimum(node->right, node);
			return true;
		}

		if (parent->left == node)
		{
			parent->left = node_to_move_up;
		}
		else
		{
			parent->right = node_to_move_up;
		}

		//delete the removed node
		node->left = NULL;
		node->right = NULL;
		free(node);

		removed = true;
	}

	return removed;
}

int swap_minimum(Node* node, Node* parent)
{
	if (node->left == NULL)
	{
		int value = node->data;
		remove_node(node, parent, node->data);
		return value;
	}
	
	return swap_minimum(node->left, node);
}

int inorder_node(const Node* node, int* array, int current)
{
	if (node == NULL)
	{
		return current;
	}

	current = inorder_node(node->left, array, current);
	array[current] = node->data;
	current++;
	current = inorder_node(node->right, array, current);

	return current;
}

int preorder_node(const Node* node, int* array, int current)
{
	if (node == NULL)
	{
		return current;
	}

	array[current] = node->data;
	current++;
	current = preorder_node(node->left, array, current);
	current = preorder_node(node->right, array, current);

	return current;
}

int postorder_node(const Node* node, int* array, int current)
{
	if (node == NULL)
	{
		return current;
	}

	current = postorder_node(node->left, array, current);
	current = postorder_node(node->right, array, current);
	array[current] = node->data;
	current++;

	return current;
}
