#include <stdbool.h>
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

//picks first element as pivot
void quicksort(int* arr, int size)
{
	quicksort_recursive(arr, 0, size-1);
}
