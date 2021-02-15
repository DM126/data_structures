#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "../error.h"

Stack* new_stack(void)
{
	return new_stack_with_capacity(DEFAULT_CAPACITY);
}

Stack* new_stack_with_capacity(int initial_capacity)
{
	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL)
	{
		exit_with_error("new_stack - Out of memory");
	}

	stack->size = 0;
	stack->capacity = initial_capacity;

	stack->array = malloc(sizeof(int) * stack->capacity);
	if (stack->array == NULL)
	{
		free(stack);
		exit_with_error("new_stack - Out of memory");
	}

	return stack;
}

void delete_stack(Stack* stack)
{
	if (stack != NULL)
	{
		free(stack->array);
		free(stack);
	}
}

Stack* copy_stack(Stack* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Stack* stack = new_stack_with_capacity(other->capacity);

	stack->size = other->size;
	for (int i = 0; i < stack->size; i++)
	{
		stack->array[i] = other->array[i];
	}

	return stack;
}


bool push(Stack* stack, int value)
{
	if (stack == NULL)
	{
		exit_with_error("push - pushing to a null stack");
	}

	//double the capacity if full
	if (isFull(stack))
	{
		expand_capacity(stack, stack->capacity * 2);
	}

	stack->array[stack->size] = value;
	stack->size++;

	return true;
}

int pop(Stack* stack)
{
	if (stack == NULL)
	{
		exit_with_error("pop - stack is null");
	}
	else if (isEmpty(stack))
	{
		exit_with_error("pop - stack is empty");
	}

	stack->size--;
	return stack->array[stack->size];
}

int peek(Stack* stack)
{
	if (isEmpty(stack))
	{
		exit_with_error("peek - peeking at an empty stack");
	}

	return stack->array[stack->size - 1];
}

bool isEmpty(Stack* stack)
{
	return stack == NULL || stack->size == 0;
}

bool isFull(Stack* stack)
{
	return stack != NULL && stack->size == stack->capacity;
}

void clear(Stack* stack)
{
	if (stack == NULL)
	{
		exit_with_error("clear - stack is null");
	}

	stack->size = 0;
}

bool expand_capacity(Stack* stack, int new_capacity)
{
	//TODO TRUNCATE IF NEW CAPACITY IS SMALLER?
	//TODO WHAT IF SIZE IS TOO LARGE?

	if (stack == NULL)
	{
		exit_with_error("expand_capacity - stack is null");
	}

	if (new_capacity <= stack->capacity)
	{
		return false;
	}

	//make the new array
	int* new_array = malloc(sizeof(int) * new_capacity);
	if (new_array == NULL)
	{
		delete_stack(stack);
		exit_with_error("expand_capacity - Out of memory");
	}

	//copy the values over
	for (int i = 0; i < stack->size; i++)
	{
		new_array[i] = stack->array[i];
	}

	//replace the old array
	free(stack->array);
	stack->array = new_array;
	stack->capacity = new_capacity;

	return true;
}

void dump(Stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack is null.\n");
		return;
	}

	for (int i = 0; i < stack->size; i++)
	{
		printf("%d: %d\n", i, stack->array[i]);
	}
	printf("size: %d\n", stack->size);
	printf("capacity: %d\n", stack->capacity);
}
