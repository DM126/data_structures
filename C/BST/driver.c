#include <assert.h>
#include <stdio.h>

#include "tree.h"

int main()
{
	Tree* tree = new_tree();
	assert(isEmpty(tree));

	//test insert
	insert(tree, 0);
	assert(!isEmpty(tree));
	assert(peek(tree) == 0);
	insert(tree, 1);
	assert(peek(tree) == 0);
	assert(tree->size == 2);

	//add to the tree in order
	for (int i = 2; i < 10; i++)
	{
		insert(tree, i);
	}
	assert(peek(tree) == 0);
	assert(tree->size == 10);
	clear(tree);
	assert(isEmpty(tree));

	printf("All tests ran successfully!\n");
	return 0;
}
