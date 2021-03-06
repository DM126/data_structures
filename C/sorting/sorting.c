#include <stdbool.h>
#include <stdlib.h>
#include "sorting.h"

void swap(int* arr, int i1, int i2)
{
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

void bubble_sort(int* arr, int size)
{
	for (int end = size - 1; end > 0; end--)
	{
		bool swapped = false;
		for (int i = 0; i < end; i++)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr, i, i+1);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

void selection_sort(int* arr, int size)
{
	for (int begin = 0; begin < size - 1; begin++)
	{
		int min_index = begin;
		for (int i = begin + 1; i < size; i++)
		{
			if (arr[i] < arr[min_index])
			{
				min_index = i;
			}
		}

		if (begin != min_index)
		{
			swap(arr, begin, min_index);
		}
	}
}

void insertion_sort(int* arr, int size)
{
	for (int key = 1; key < size; key++)
	{
		int i = key;
		while (i > 0 && arr[i] < arr[i-1])
		{
			swap(arr, i, i-1);
			i--;
		}
	}
}


//merge sort functions:
static void merge(int* arr, int left, int mid, int right)
{
	int temp[right - left + 1];

	int li = left; //left index
	int ri = mid + 1; //right index
	int ti = 0; //temp array index
	while (li <= mid && ri <= right)
	{
		if (arr[li] <= arr[ri])
		{
			temp[ti] = arr[li];
			li++;
		}
		else
		{
			temp[ti] = arr[ri];
			ri++;
		}

		ti++;
	}

	while (li <= mid)
	{
		temp[ti] = arr[li];
		ti++;
		li++;
	}

	while (ri <= right)
	{
		temp[ti] = arr[ri];
		ti++;
		ri++;
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i - left];
	}
}

static void merge_half(int* arr, int left, int right)
{
	if (right > left)
	{
		int mid = left + (right - left) / 2;
		merge_half(arr, left, mid);
		merge_half(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge_sort(int* arr, int size)
{
	merge_half(arr, 0, size-1);
}


//quicksort functions:
//returns pivot index
//adapted from CLRS book
static int partition(int* arr, int start, int end)
{
	//select last index as pivot
	int pivot = arr[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr, i, j);
		}
	}

	swap(arr, i+1, end);

	return i + 1;
}

//Called by quicksort(), not by user.
//User should only need to provide the array, not the start/end bounds.
static void quicksort_recursive(int* arr, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(arr, start, end);

		quicksort_recursive(arr, start, pivot - 1);
		quicksort_recursive(arr, pivot + 1, end);
	}
}

void quicksort(int* arr, int size)
{
	quicksort_recursive(arr, 0, size-1);
}


//heapsort functions:
//i is the index to bubble down to the correct position
static void heapify(int* arr, int size, int i)
{
	int left = 2 * i + 1;
	if (left < size)
	{
		int right = 2 * i + 2;
		int largest;
		if (right < size)
		{
			largest = (arr[left] > arr[right]) ? left : right;
		}
		else
		{
			largest = left;
		}

		if (arr[i] < arr[largest])
		{
			swap(arr, i, largest);
			heapify(arr, size, largest);
		}
	}
}

static void build_max_heap(int* arr, int size)
{
	for (int i = size/2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}
}

void heapsort(int* arr, int size)
{
	build_max_heap(arr, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr, 0, i);
		heapify(arr, i, 0);
	}
}


void counting_sort(int* arr, int size)
{
	//initialize counts to 0
	int *counts = malloc(size*sizeof(int));
	for (int i = 0; i < size; i++)
	{
		counts[i] = 0;
	}

	//count instances of each value
	for (int i = 0; i < size; i++)
	{
		counts[arr[i]]++;
	}

	//determine indices in output
	for (int i = 1; i < size; i++)
	{
		counts[i] += counts[i-1];
	}

	//place the values in order
	for (int i = size - 1; i >= 0; i--)
	{
		while (counts[i] > counts[i-1] || (i == 0 && counts[0] > 0))
		{
			counts[i]--;
			arr[counts[i]] = i;
		}
	}

	free(counts);
}
