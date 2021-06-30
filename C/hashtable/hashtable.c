#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "../error.h"

HashTable* new_hashtable(void)
{
	return new_hashtable_with_capacity(DEFAULT_CAPACITY);
}

HashTable* new_hashtable_with_capacity(int initial_capacity)
{
	if (initial_capacity <= 0)
	{
		exit_with_error("new_hashtable - Capacity must be greater than 0");
	}

	HashTable* table = malloc(sizeof(HashTable));
	if (table == NULL)
	{
		exit_with_error("new_hashtable - Out of memory");
	}

	table->array = malloc(initial_capacity * sizeof(char*));
	if (table->array == NULL)
	{
		exit_with_error("new_hashtable - Out of memory");
	}
	table->capacity = initial_capacity;
	table->size = 0;

	return table;
}

void delete_hashtable(HashTable* table)
{
	if (table != NULL)
	{
		for (int i = 0; i < table->capacity; i++)
		{
			free(table->array[i]);
		}
		free(table->array);
		free(table);
	}
}

HashTable* copy_hashtable(const HashTable* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	HashTable* table = new_hashtable_with_capacity(other->capacity);

	table->size = other->size;
	for (int i = 0; i < other->capacity; i++)
	{
		if (other->array[i] == NULL)
		{
			table->array[i] = NULL;
		}
		else
		{
			table->array[i] = malloc(strlen(other->array[i])*sizeof(char));
			strcpy(table->array[i], other->array[i]);
		}
	}

	return table;
}
