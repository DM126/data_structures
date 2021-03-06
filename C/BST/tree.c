#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "../error.h"

Tree* new_tree(void)
{
	Tree* tree = malloc(sizeof(Tree));
	if (tree == NULL)
	{
		exit_with_error("new_tree - Out of memory");
	}

	tree->size = 0;
	tree->root = NULL;

	return tree;
}

void delete_tree(Tree* tree)
{
	if (tree != NULL)
	{
		delete_node(tree->root);
		free(tree);
	}
}

Tree* copy_tree(Tree* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Tree* tree = new_tree();
	tree->root = copy_node(other->root);
	tree->size = other->size;

	return tree;
}


bool insert(Tree* tree, int value)
{
	if (tree == NULL)
	{
		exit_with_error("insert - tree is null");
	}

	bool inserted = false;
	if (isEmpty(tree))
	{
		tree->root = new_node(value);
		inserted = true;
	}
	else
	{
		inserted = insert_node(tree->root, value);
	}

	if (inserted)
	{
		tree->size++;
	}
	return inserted;
}

bool find(const Tree* tree, int value)
{
	if (tree == NULL)
	{
		exit_with_error("find - tree is null");
	}

	if (isEmpty(tree))
	{
		return false;
	}

	return find_node(tree->root, value);
}

bool delete(Tree* tree, int value)
{
	if (tree == NULL)
	{
		exit_with_error("remove - tree is null");
	}

	if (isEmpty(tree))
	{
		return false;
	}

	bool removed; //set to true if the node is found and removed
	if (tree->root->data == value) //at the root
	{
		if (tree->root->left == NULL && tree->root->right == NULL)
		{
			free(tree->root);
			tree->root = NULL;
		}
		else if (tree->root->left == NULL)
		{
			Node* temp = tree->root;
			tree->root = tree->root->right;
			temp->right = NULL;
			free(temp);
		}
		else if (tree->root->right == NULL)
		{
			Node* temp = tree->root;
			tree->root = tree->root->left;
			temp->left = NULL;
			free(temp);
		}
		else //2 children
		{
			swap_minimum(tree->root->right, tree->root);
		}

		removed = true;
	}
	else //search for the node
	{
		removed = remove_node(tree->root, NULL, value);
	}

	if (removed)
	{
		tree->size--;
	}

	return removed;
}

int peek(const Tree* tree)
{
	if (tree == NULL)
	{
		exit_with_error("peek - tree is null");
	}
	else if (isEmpty(tree))
	{
		exit_with_error("peek - tree is empty");
	}

	return tree->root->data;
}

bool isEmpty(const Tree* tree)
{
	return tree == NULL || tree->size == 0;
}

void clear(Tree* tree)
{
	if (tree == NULL)
	{
		exit_with_error("clear - tree is null");
	}

	delete_node(tree->root);
	tree->size = 0;
	tree->root = NULL;
}


int* inorder(const Tree* tree)
{
	if (tree == NULL || isEmpty(tree))
	{
		return NULL;
	}

	int* array = malloc(tree->size * sizeof(int));
	if (array == NULL)
	{
		exit_with_error("inorder - out of memory");
	}

	inorder_node(tree->root, array, 0);
	return array;
}

int* preorder(const Tree* tree)
{
	if (tree == NULL || isEmpty(tree))
	{
		return NULL;
	}

	int* array = malloc(tree->size * sizeof(int));
	if (array == NULL)
	{
		exit_with_error("preorder - out of memory");
	}

	preorder_node(tree->root, array, 0);
	return array;
}

int* postorder(const Tree* tree)
{
	if (tree == NULL || isEmpty(tree))
	{
		return NULL;
	}

	int* array = malloc(tree->size * sizeof(int));
	if (array == NULL)
	{
		exit_with_error("postorder - out of memory");
	}

	postorder_node(tree->root, array, 0);
	return array;
}

//helper function for dump()
static void inorder_dump(const Node* node)
{
	if (node != NULL)
	{
		printf("(");
		inorder_dump(node->left);
		printf("%d", node->data);
		inorder_dump(node->right);
		printf(")");
	}
}

void dump(const Tree* tree)
{
	if (tree == NULL)
	{
		printf("tree is null.\n");
	}
	else if (isEmpty(tree))
	{
		printf("tree is empty.\n");
	}
	else
	{
		inorder_dump(tree->root);
		printf("\nsize: %d\n", tree->size);
	}
}
