#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "../array_util.h"
#include "../error.h"

Stack* new_stack(void)
{
	return new_stack_with_capacity(DEFAULT_CAPACITY);
}

Stack* new_stack_with_capacity(int initial_capacity)
{
	if (initial_capacity <= 0)
	{
		exit_with_error("new_stack - Capacity must be greater than 0");
	}

	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL)
	{
		exit_with_error("new_stack - Out of memory");
	}

	stack->size = 0;
	stack->capacity = initial_capacity;
	stack->array = create_array(stack->capacity);

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

Stack* copy_stack(const Stack* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Stack* stack = new_stack_with_capacity(other->capacity);

	stack->size = other->size;
	memcpy(stack->array, other->array, other->size * sizeof(int));

	return stack;
}


bool push(Stack* stack, int value)
{
	if (stack == NULL)
	{
		exit_with_error("push - stack is null");
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

int peek(const Stack* stack)
{
	if (stack == NULL)
	{
		exit_with_error("pop - stack is null");
	}
	else if (isEmpty(stack))
	{
		exit_with_error("peek - stack is empty");
	}

	return stack->array[stack->size - 1];
}

bool isEmpty(const Stack* stack)
{
	return stack == NULL || stack->size == 0;
}

bool isFull(const Stack* stack)
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

	int* new_array = copy_array(stack->array, stack->size, new_capacity);

	//replace the old array
	free(stack->array);
	stack->array = new_array;
	stack->capacity = new_capacity;

	return true;
}

void dump(const Stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack is null.\n");
		return;
	}

	print_array(stack->array, stack->size, stack->capacity);
}
