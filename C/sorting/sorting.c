#include <stdbool.h>

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
