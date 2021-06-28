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

//tests a sorting algorithm, which is passed as a function pointer
//name is the name of the sorting algorithm, printed for debugging
void test_sort(void (*fptr)(int*, int), char* name);

int main()
{
	test_sort(bubble_sort, "bubble sort");
	test_sort(selection_sort, "selection sort");
	test_sort(insertion_sort, "insertion sort");
	test_sort(merge_sort, "merge sort");
	test_sort(quicksort, "quicksort");

	printf("All tests ran successfully!\n");

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

void test_sort(void (*sort_fptr)(int*, int), char* name)
{
	printf("Testing %s\n", name);

	int size = 100;
	int* arr = random_array(size);

	sort_fptr(arr, size);

	//Used for debugging
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d\n", arr[i]);
	// }

	assert(check_array(arr, size));
	
	free(arr);
}
