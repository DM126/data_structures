#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "../error.h"

Vector* new_vector(void)
{
	return new_vector_with_capacity(DEFAULT_CAPACITY);
}

Vector* new_vector_with_capacity(int initial_capacity)
{
	Vector* vector = malloc(sizeof(vector));
	if (vector == NULL)
	{
		exit_with_error("new_vector - Out of memory");
	}

	vector->size = 0;
	vector->capacity = initial_capacity;

	vector->array = malloc(sizeof(int) * vector->capacity);
	if (vector->array == NULL)
	{
		free(vector);
		exit_with_error("new_vector - Out of memory");
	}

	return vector;
}

void delete_vector(Vector* vector)
{
	if (vector != NULL)
	{
		free(vector->array);
		free(vector);
	}
}

Vector* copy_vector(Vector* other)
{
	
}


bool add_index(Vector* vector, int index, int value)
{

}

bool add_back(Vector* vector, int value)
{

}

bool add_front(Vector* vector, int value)
{

}

int remove_index(Vector* vector, int index)
{

}

int remove_back(Vector* vector)
{

}

int remove_front(Vector* vector)
{

}

int get_index(Vector* vector, int index)
{

}

bool isEmpty(Vector* vector)
{

}

bool isFull(Vector* vector)
{

}

void clear(Vector* vector)
{

}

bool expand_capacity(Vector* vector, int new_capacity)
{

}

void dump(Vector* vector)
{

}
