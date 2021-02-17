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

	//todo test add_front and add_index

	delete_vector(vector);
	delete_vector(vector2);

	printf("All tests ran successfully!\n");
	return 0;
}
