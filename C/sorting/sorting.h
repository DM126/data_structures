//Sorting algorithms

#ifndef SORTING_H
#define SORTING_H

void bubble_sort(int* arr, int size);
void selection_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void merge_sort(int* arr, int size);
void quicksort(int* arr, int size);
void heapsort(int* arr, int size);
void counting_sort(int* arr, int size); //for simplicity, range will be [0-size]

//swap two elements within an array
//i1 and i2 are the two indices to swap
void swap(int* arr, int i1, int i2);

#endif
