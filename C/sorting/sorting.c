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
		for (int i = 0; i < end; i++)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr, i, i+1);
			}
		}
	}
}
