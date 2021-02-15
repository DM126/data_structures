#include <stddef.h>

#include "stack.h"

Stack* new_stack(void)
{
	return new_stack_with_capacity(DEFAULT_CAPACITY);
}

Stack* new_stack_with_capacity(int initial_capacity)
{
	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL)
	{
		return NULL;
	}

	stack->size = 0;
	stack->capacity = initial_capacity;

	stack->array = malloc(sizeof(int) * stack->capacity);
	if (stack->array == NULL)
	{
		free(stack);
		return NULL;
	}
}

void destroy_stack(Stack* stack)
{
	free(stack->array);
	free(stack);
}

Stack* copy_stack(Stack* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Stack* stack = new_stack_with_capacity(other->capacity);
	if (stack != NULL)
	{
		stack->size = other->size;
		for (int i = 0; i < stack->size; i++)
		{
			stack->array[i] = other->array[i];
		}
	}
	
}


bool push(Stack* stack, int value)
{

}

int pop(Stack* stack)
{

}

int peek(Stack* stack)
{

}

bool isEmpty(Stack* stack)
{

}

void clear(Stack* stack)
{

}

bool expand_capacity(Stack* stack, int new_capacity)
{
	
}
