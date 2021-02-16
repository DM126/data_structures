//driver to test vector
#include "vector.h"

int main()
{
	Vector* vector = new_vector();

	delete_vector(vector);

	return 0;
}
