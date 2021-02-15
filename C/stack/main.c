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

	//Test copy
	for(int i = 0; i < 5; i++)
	{
		push(stack, i);
	}
	Stack* stack3 = copy_stack(stack);
	assert(stack->size == stack3->size);
	assert(stack->capacity == stack3->capacity);
	for(int i = 0; i < 5; i++)
	{
		assert(stack->array[i] == stack3->array[i]);
	}
	assert(stack->array != stack3->array); //make sure deep copy is done
	pop(stack);
	assert(peek(stack3) == 4);
	assert(peek(stack) != peek(stack3));
	assert(stack->size != stack3->size);
	push(stack3, 5);
	assert(peek(stack) != 5);
	assert(peek(stack) != peek(stack3));

	delete_stack(stack);
	delete_stack(stack2);
	delete_stack(stack3);

	printf("All tests ran successfully!\n");
	return 0;
}
