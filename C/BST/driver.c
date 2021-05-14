#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

//Used for debugging
//Prints the contents of an array and frees the array
void print_traversal_array(int* array, int size);

//Calls dump as well as print_traversal_array for each traversal
void full_dump(Tree* tree);

int main()
{
	Tree* tree = new_tree();
	assert(isEmpty(tree));

	// insert(tree, 10);
	// insert(tree, 20);
	// delete(tree, 10);
	// full_dump(tree);
	// insert(tree, 50);
	// full_dump(tree);
	// exit(0);

	// insert(tree, 3);
	// insert(tree, 5);
	// insert(tree, 6);
	// insert(tree, 4);
	// insert(tree, 1);
	// insert(tree, 2);
	// insert(tree, 0);
	// delete(tree, 6);
	// delete(tree, 5);
	// delete(tree, 1);
	// full_dump(tree);
	// exit(0);

	//test insert
	insert(tree, 0);
	assert(!isEmpty(tree));
	assert(peek(tree) == 0);
	insert(tree, 1);
	assert(peek(tree) == 0);
	assert(tree->size == 2);

	//add to the tree in order
	for (int i = 2; i < 6; i++)
	{
		insert(tree, i);
	}
	assert(peek(tree) == 0);
	assert(tree->size == 6);
	// dump(tree);

	//test inorder
	int* inorder_array = inorder(tree);
	for (int i = 0; i < 6; i++)
	{
		assert(inorder_array[i] == i);
	}
	free(inorder_array);

	//remove middle item and re-insert
	delete(tree, 2);
	insert(tree, 2);
	assert(find(tree, 2));

	inorder_array = inorder(tree);
	for (int i = 0; i < 6; i++)
	{
		assert(inorder_array[i] == i);
	}
	free(inorder_array);

	delete(tree, 0);
	delete(tree, 1);
	assert(peek(tree) == 3);
	inorder_array = inorder(tree);
	for (int i = 2; i < 6; i++)
	{
		assert(inorder_array[i-2] == i);
	}
	free(inorder_array);

	assert(!find(tree, 1));
	assert(!delete(tree,0));

	//test clear and re-inserting
	clear(tree);
	assert(isEmpty(tree));

	for (int i = 0; i < 6; i++)
	{
		insert(tree, i);
	}
	assert(peek(tree) == 0);
	assert(tree->size == 6);
	inorder_array = inorder(tree);
	for (int i = 0; i < 6; i++)
	{
		assert(inorder_array[i] == i);
	}
	free(inorder_array);

	//test copy
	Tree* copytree = copy_tree(tree);
	assert(peek(tree) == peek(copytree));
	assert(tree->size == copytree->size);
	delete(copytree, 0);
	assert(peek(tree) == 0);
	delete_tree(copytree);
	insert(tree, 10);
	assert(peek(tree) != 10);

	//test other traversals
	//tree will look like this:
	//      3
	//  1       5
	//0   2   4   6
	int pre[] = {3, 1, 0, 2, 5, 4, 6};
	int post[] = {0, 2, 1, 4, 6, 5, 3};
	clear(tree);
	insert(tree, 3);
	insert(tree, 5);
	insert(tree, 6);
	insert(tree, 4);
	insert(tree, 1);
	insert(tree, 2);
	insert(tree, 0);

	int* preorder_array = preorder(tree);
	int* postorder_array = postorder(tree);

	assert(!memcmp(preorder_array, pre, 7*sizeof(int)));
	assert(!memcmp(postorder_array, post, 7*sizeof(int)));

	free(preorder_array);
	free(postorder_array);

	//TODO MORE TESTS

	delete_tree(tree);

	printf("All tests ran successfully!\n");
	return 0;
}

void print_traversal_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("i=%d: %d\n", i, array[i]);
	}
	printf("\n");
	free(array);
}

void full_dump(Tree* tree)
{
	dump(tree);

	printf("inorder:\n");
	print_traversal_array(inorder(tree), tree->size);

	printf("preorder:\n");
	print_traversal_array(preorder(tree), tree->size);

	printf("postorder:\n");
	print_traversal_array(postorder(tree), tree->size);
}
