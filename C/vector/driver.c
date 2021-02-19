//driver to test vector
#include <assert.h>
#include <stdio.h>

#include "vector.h"

int main()
{
	Vector* vector = new_vector();
	Vector* vector2 = new_vector_with_capacity(50);

	//test constructors
	assert(vector->capacity == DEFAULT_CAPACITY);
	assert(vector2->capacity == 50);
	assert(isEmpty(vector));
	assert(!isFull(vector));

	//fill the vector
	for (int i = 0; i < vector->capacity; i++)
	{
		add_back(vector, i);
		assert(get_index(vector, i) == i);
		assert(vector->size == i+1);
	}
	assert(get_front(vector) == get_index(vector, 0));
	assert(get_back(vector) == get_index(vector, vector->size-1));
	assert(isFull(vector));
	assert(!isEmpty(vector));

	//add one more to expand capacity
	add_back(vector, vector->size);
	assert(!isFull(vector));
	assert(!isEmpty(vector));
	assert(vector->size == DEFAULT_CAPACITY + 1);
	assert(vector->capacity == DEFAULT_CAPACITY * 2);
	for (int i = 0; i < vector->size; i++)
	{
		assert(vector->array[i] == i);
	}

	//test clear
	clear(vector);
	assert(isEmpty(vector));
	add_back(vector, 10);
	assert(!isEmpty(vector));
	//test get and add functions
	assert(get_index(vector, 0) == 10);
	assert(get_front(vector) == 10);
	assert(get_back(vector) == 10);
	add_back(vector, 20);
	assert(get_front(vector) == 10);
	assert(get_back(vector) == 20);
	add_front(vector, 30);
	assert(get_front(vector) == 30);
	assert(get_index(vector, 1) == 10);
	assert(get_back(vector) == 20);

	//test remove functions
	clear(vector);
	for (int i = 0; i < 10; i++)
	{
		add_back(vector, i);
	}
	assert(remove_index(vector, 3) == 3);
	assert(remove_front(vector) == 0);
	assert(remove_back(vector) == 9);
	clear(vector);

	//test copy
	for(int i = 0; i < 5; i++)
	{
		add_back(vector, i);
	}
	Vector* vector3 = copy_vector(vector);
	assert(vector->size == vector3->size);
	assert(vector->capacity == vector3->capacity);
	for(int i = 0; i < 5; i++)
	{
		assert(vector->array[i] == vector3->array[i]);
	}
	assert(vector->array != vector3->array); //make sure deep copy is done
	remove_back(vector);
	assert(get_back(vector3) == 4);
	assert(get_back(vector) != get_back(vector3));
	assert(vector->size != vector3->size);
	add_front(vector3, 5);
	assert(get_front(vector) != 5);
	assert(get_front(vector3) == 5);

	delete_vector(vector);
	delete_vector(vector2);
	delete_vector(vector3);

	printf("All tests ran successfully!\n");
	return 0;
}
