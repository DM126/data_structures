//Vector from C++, or an ArrayList from Java

#ifndef VECTOR_H
#define VECTOR_H

#include "stdbool.h"

struct Vector_struct
{
	int size; //number of items in the vector, signifies next index to add to
	int capacity; //capacity of the array
	int* array;
};
typedef struct Vector_struct Vector;


static const int DEFAULT_CAPACITY = 10; //starting capacity if none specified

//Create a new vector with either the default capacity or a specified one.
//Will never return NULL, Exits if malloc fails.
Vector* new_vector(void);
Vector* new_vector_with_capacity(int initial_capacity);

//Frees the vector and its array
void delete_vector(Vector* vector);

//Returns a deep copy of the vector
Vector* copy_vector(Vector* other);


//Adds a value to the vector.
//If the vector is at capacity it will be expanded.
//Returns true if the value was successfully added, false otherwise.
bool add_index(Vector* vector, int index, int value); //adds to a specific index, pushes everything behind it back
bool add_back(Vector* vector, int value); //adds to the end of the vector
bool add_front(Vector* vector, int value); //Adds to the front of the vector, pushes everything back

//Remove an item from the vector and returns its value.
//Exits the program if vector is null or empty, or if index is invalid.
int remove_index(Vector* vector, int index);
int remove_back(Vector* vector);
int remove_front(Vector* vector);

//Returns a value at a specific index, without removing it.
//Exits program if vector is null or empty, or if index is invalid.
int get_index(Vector* vector, int index);
int get_back(Vector* vector);
int get_front(Vector* vector);

//Returns true if the vector is null or has no items TODO NULL?
bool isEmpty(Vector* vector);

//Returns true if the vector's size is equal to its capacity TODO NULL?
bool isFull(Vector* vector);

//Removes all items from the vector.
//Exits the program if the vector is null.
void clear(Vector* vector);

//Expands the capacity of the vector.
//Returns false if new_capacity is <= to the old capacity or if the vector is null.
//Exits program if malloc fails.
bool expand_capacity(Vector* vector, int new_capacity);

//Print the vector's info, used for debugging
void dump(Vector* vector);

#endif
