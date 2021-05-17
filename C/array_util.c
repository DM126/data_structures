#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_util.h"
#include "error.h"

int* create_array(int capacity)
{
	int* array = malloc(sizeof(int) * capacity);
	if (array == NULL)
	{
		exit_with_error("create_array - Out of memory");
	}

	return array;
}

int* copy_array(const int* src, int size, int capacity)
{
	int* new_array = create_array(capacity);
	memcpy(new_array, src, size * sizeof(int));

	return new_array;
}

void print_array(const int* array, int size, int capacity)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d: %d\n", i, array[i]);
	}
	printf("size: %d\n", size);
	printf("capacity: %d\n", capacity);
}
