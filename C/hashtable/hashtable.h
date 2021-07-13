#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

//hash table to hold strings
struct HashTable_struct
{
	int size; //number of items in the hash table
	int occupied_spaces; //number of non-null spaces (sum of items and tombstones)
	int capacity; //capacity of the array
	char** array; //array of strings
};
typedef struct HashTable_struct HashTable;

static const int DEFAULT_CAPACITY = 11; //starting capacity if none specified
static const double MAX_LOAD_FACTOR = 0.75; //max load factor before rehashing occurs

//Create a new hash table with either the default capacity or a specified one.
//Will never return NULL, Exits if malloc fails.
HashTable* new_hashtable(void);
HashTable* new_hashtable_with_capacity(int initial_capacity);

//Frees the hash table and everything in its array
void delete_hashtable(HashTable* table);

//Returns a deep copy of the hash table
HashTable* copy_hashtable(const HashTable* other);

//Adds a string to the hash table.
//If the hash table reaches loading factor it will be expanded.
//Returns true if the value was successfully added, false otherwise.
bool add(HashTable* table, char* str);

//Removes a string from the hash table.
//Returns true if the string was in the table.
//Exits the program if hash table is null.
bool remove(HashTable* table);

//Returns true if the hash table contains the string.
//Exits program if hash table is null.
bool contains(const HashTable* table, char* str);

//Returns true if the hash table is null or has no items TODO NULL?
bool isEmpty(const HashTable* table);

//Returns true if the hash table's size is equal to its capacity TODO NULL?
bool isFull(const HashTable* table);

//Returns the load factor (number of items and tombstones, divided by capacity)
double load_factor(const HashTable* table);

//Removes all items from the hash table.
//Exits the program if the hash table is null.
void clear(HashTable* table);

//Expands the capacity of the hash table and rehashes all items.
//Returns false if new_capacity is <= to the old capacity or if the hash table is null.
//Exits program if malloc fails.
bool expand_capacity(HashTable* table, int new_capacity);

//Print the hash table's info, used for debugging
void dump(const HashTable* table);

#endif
