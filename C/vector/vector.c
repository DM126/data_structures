#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "../error.h"

//Generic functions to do adding and removing logic.
//Will not check for null/empty vectors or index bounds,
//must be done before calling.
//Returns true if added successfully:
static bool add_item(Vector* vector, int index, int value);
//Returns value removed:
static int remove_item(Vector* vector, int index);

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

Vector* copy_vector(const Vector* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Vector* vector = new_vector_with_capacity(other->capacity);

	vector->size = other->size;
	for (int i = 0; i < vector->size; i++)
	{
		vector->array[i] = other->array[i];
	}

	return vector;
}


bool add_index(Vector* vector, int index, int value)
{
	if (vector == NULL)
	{
		exit_with_error("add_index - vector is null");
	}
	else if (index < 0 || index > vector->size)
	{
		exit_with_error("add_index - Index out of bounds");
	}

	return add_item(vector, index, value);
}

bool add_back(Vector* vector, int value)
{
	if (vector == NULL)
	{
		exit_with_error("add_index - vector is null");
	}

	return add_item(vector, vector->size, value);
}

bool add_front(Vector* vector, int value)
{
	if (vector == NULL)
	{
		exit_with_error("add_index - vector is null");
	}

	return add_item(vector, 0, value);
}

static bool add_item(Vector* vector, int index, int value)
{
	//double the capacity if full
	if (isFull(vector))
	{
		expand_capacity(vector, vector->capacity * 2);
	}

	//push everything back
	for (int i = vector->size; i > index; i--)
	{
		vector->array[i] = vector->array[i-1];
	}
	vector->array[index] = value;
	vector->size++;

	return true;
}

int remove_index(Vector* vector, int index)
{
	if (vector == NULL)
	{
		exit_with_error("remove_index - vector is null");
	}
	else if (isEmpty(vector))
	{
		exit_with_error("remove_index - vector is empty");
	}
	else if (index < 0 || index >= vector->size)
	{
		exit_with_error("remove_index - index out of bounds");
	}

	return remove_item(vector, index);
}

int remove_back(Vector* vector)
{
	if (vector == NULL)
	{
		exit_with_error("remove_back - vector is null");
	}
	else if (isEmpty(vector))
	{
		exit_with_error("remove_back - vector is empty");
	}

	return remove_item(vector, vector->size - 1);
}

int remove_front(Vector* vector)
{
	if (vector == NULL)
	{
		exit_with_error("remove_front - vector is null");
	}
	else if (isEmpty(vector))
	{
		exit_with_error("remove_back - vector is empty");
	}

	return remove_item(vector, 0);
}

static int remove_item(Vector* vector, int index)
{
	int value = vector->array[index];

	//move everything forward
	for (int i = index; i < vector->size - 1; i++)
	{
		vector->array[i] = vector->array[i+1];
	}

	vector->size--;

	return value;
}

int get_index(const Vector* vector, int index)
{
	if (vector == NULL)
	{
		exit_with_error("get_index - vector is null");
	}
	else if (index < 0 || index >= vector->size)
	{
		exit_with_error("get_index - index out of bounds");
	}

	return vector->array[index];
}

int get_back(const Vector* vector)
{
	return get_index(vector, vector->size - 1);
}

int get_front(const Vector* vector)
{
	return get_index(vector, 0);
}

bool isEmpty(const Vector* vector)
{
	return vector == NULL || vector->size == 0;
}

bool isFull(const Vector* vector)
{
	return vector != NULL && vector->size == vector->capacity;
}

void clear(Vector* vector)
{
	if (vector == NULL)
	{
		exit_with_error("clear - vector is null");
	}

	vector->size = 0;
}

bool expand_capacity(Vector* vector, int new_capacity)
{
	//TODO TRUNCATE IF NEW CAPACITY IS SMALLER?
	//TODO WHAT IF SIZE IS TOO LARGE?

	if (vector == NULL)
	{
		exit_with_error("expand_capacity - vector is null");
	}

	if (new_capacity <= vector->capacity)
	{
		return false;
	}

	//make the new array
	int* new_array = malloc(sizeof(int) * new_capacity);
	if (new_array == NULL)
	{
		delete_vector(vector);
		exit_with_error("expand_capacity - Out of memory");
	}

	//copy the values over
	for (int i = 0; i < vector->size; i++)
	{
		new_array[i] = vector->array[i];
	}

	//replace the old array
	free(vector->array);
	vector->array = new_array;
	vector->capacity = new_capacity;

	return true;
}

void dump(const Vector* vector)
{
	if (vector == NULL)
	{
		printf("Stack is null.\n");
		return;
	}

	for (int i = 0; i < vector->size; i++)
	{
		printf("%d: %d\n", i, vector->array[i]);
	}
	printf("size: %d\n", vector->size);
	printf("capacity: %d\n", vector->capacity);
}
