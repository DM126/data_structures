#include <assert.h>
#include <stdio.h>

#include "stack.h"

int main()
{
	Stack* stack = new_stack();
	Stack* stack2 = new_stack_with_capacity(50);

	//test constructors
	assert(stack->capacity == DEFAULT_CAPACITY);
	assert(stack->size == 0);
	assert(stack2->capacity == 50);

	//fill the stack
	for (int i = 0; i < stack->capacity; i++)
	{
		push(stack, i);
		assert(peek(stack) == i);
		assert(stack->size == i+1);
	}
	assert(stack->size == stack->capacity);
	for (int i = 0; i < stack->capacity; i++)
	{
		assert(stack->array[i] == i);
	}

	//add one more to expand capacity
	push(stack, stack->size);
	assert(stack->size == DEFAULT_CAPACITY + 1);
	assert(stack->capacity == DEFAULT_CAPACITY * 2);
	for (int i = 0; i < stack->size; i++)
	{
		assert(stack->array[i] == i);
	}

	delete_stack(stack);
	delete_stack(stack2);

	printf("All tests ran successfully!\n");
	return 0;
}
