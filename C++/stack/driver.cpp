#include <assert.h>
#include <iostream>

#include "stack.h"

int main()
{
	Stack<int> stack;

	//test constructor
	assert(stack.isEmpty());
	assert(!stack.isFull());

	printf("All tests ran successfully!\n");
	return 0;
}
