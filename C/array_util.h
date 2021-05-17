//Utility functions for int array operations

#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

//Creates a new array
int* create_array(int capacity);

//Creates a new array and copies the items
int* copy_array(const int* src, int size, int capacity);

//prints the size, capacity, and contents of an array
void print_array(const int* array, int size, int capacity);

//TODO function for pushing items back or inserting items?

#endif
