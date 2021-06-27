#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

//creates a randomized array
int* random_array(int size);

//checks to see if the array is sorted
bool check_array(int* arr, int size);

int main()
{
	int size = 100;
	int* arr = random_array(size);

	bubble_sort(arr, size);

	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d\n", arr[i]);
	// }

	assert(check_array(arr, size));

	printf("All tests ran successfully!\n");

	free(arr);

	return 0;
}

int* random_array(int size)
{
	int *arr = malloc(size*sizeof(int));

	//initialize rng
	time_t t;
	srand((unsigned) time(&t));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}

	return arr;
}

bool check_array(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return false;
		}
	}

	return true;
}
