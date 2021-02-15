#include <assert.h>
#include <stdio.h>

#include "stack.h"

int main()
{
	Stack* stack = new_stack();
	Stack* stack2 = new_stack_with_capacity(50);

	//test constructors
	assert(stack->capacity == DEFAULT_CAPACITY);
	assert(stack2->capacity == 50);
	assert(isEmpty(stack));
	assert(!isFull(stack));

	//fill the stack
	for (int i = 0; i < stack->capacity; i++)
	{
		push(stack, i);
		assert(peek(stack) == i);
		assert(stack->size == i+1);
	}
	assert(isFull(stack));
	assert(!isEmpty(stack));
	for (int i = 0; i < stack->capacity; i++)
	{
		assert(stack->array[i] == i);
	}

	//add one more to expand capacity
	push(stack, stack->size);
	assert(!isFull(stack));
	assert(!isEmpty(stack));
	assert(stack->size == DEFAULT_CAPACITY + 1);
	assert(stack->capacity == DEFAULT_CAPACITY * 2);
	for (int i = 0; i < stack->size; i++)
	{
		assert(stack->array[i] == i);
	}

	//test clear
	clear(stack);
	assert(isEmpty(stack));
	push(stack, 10);
	assert(!isEmpty(stack));
	assert(peek(stack) == 10);

	//test pop, and pushing after popping
	pop(stack);
	assert(isEmpty(stack));
	push(stack, 100);
	push(stack, 200);
	pop(stack);
	assert(!isEmpty(stack));
	assert(peek(stack) == 100);
	pop(stack);

	delete_stack(stack);
	delete_stack(stack2);

	printf("All tests ran successfully!\n");
	return 0;
}
