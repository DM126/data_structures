#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

//hash table to hold strings
struct HashTable_struct
{
	int size; //number of items in the hash table
	int capacity; //capacity of the array
	char** array; //array of strings
};
typedef struct HashTable_struct HashTable;

static const int DEFAULT_CAPACITY = 11; //starting capacity if none specified

//Create a new hash table with either the default capacity or a specified one.
//Will never return NULL, Exits if malloc fails.
HashTable* new_hashtable(void);
HashTable* new_hashtable_with_capacity(int initial_capacity);

//Frees the hash table and its array
void delete_hashtable(HashTable* table);

//Returns a deep copy of the hash table
HashTable* copy_hashtable(const HashTable* other);

#endif
