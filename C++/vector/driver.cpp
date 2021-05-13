//Test of vector

#include <cassert>

#include "vector.hpp"

//Test deep copy for copy constructor and assignment operator.
//Vectors should be initialized by pushing 0 through 4 onto them.
bool deepCopyTest(Vector<int>& vec, Vector<int>& copyvec);

int main()
{
	Vector<int> vec;
	Vector<int> vec2(50);

	//test constructors
	assert(vec.isEmpty());
	assert(!vec.isFull());
	assert(vec.getCapacity() == vec.DEFAULT_CAPACITY);
	assert(vec2.isEmpty());
	assert(!vec2.isFull());
	assert(vec2.getCapacity() == 50);

	//fill the vector
	for (int i = 0; !vec.isFull(); i++)
	{
		vec.add_back(i);
		assert(vec.get(i) == i);
		assert(vec.getSize() == i+1);
	}
	assert(vec.getSize() == vec.getCapacity());
	assert(vec.get_front() == vec.get(0));
	assert(vec.get_back() == vec.get(vec.getSize()-1));
	assert(vec.isFull());
	assert(!vec.isEmpty());

	//add one more to expand capacity
	vec.add_back(vec.getSize());
	assert(!vec.isFull());
	assert(!vec.isEmpty());
	assert(vec.getSize() == vec.DEFAULT_CAPACITY + 1);
	assert(vec.getCapacity() == vec.DEFAULT_CAPACITY * 2);
	for (int i = 0; i < vec.getSize(); i++)
	{
		assert(vec.get(i) == i);
	}

	//test clear
	vec.clear();
	assert(vec.isEmpty());
	vec.add_back(10);
	assert(!vec.isEmpty());
	//test get and add functions
	assert(vec.get(0) == 10);
	assert(vec.get_front() == 10);
	assert(vec.get_back() == 10);
	vec.add_back(20);
	assert(vec.get_front() == 10);
	assert(vec.get_back() == 20);
	vec.add_front(30);
	assert(vec.get_front() == 30);
	assert(vec.get(1) == 10);
	assert(vec.get_back() == 20);

	//test remove functions
	vec.clear();
	for (int i = 0; i < 10; i++)
	{
		vec.add_back(i);
	}
	assert(vec.remove(3) == 3);
	assert(vec.remove_front() == 0);
	assert(vec.remove_back() == 9);
	vec.clear();

	//test copy and assignment
	for(int i = 0; i < 5; i++)
	{
		vec.add_back(i);
	}
	Vector<int> copyvec = vec; //copy constructor
	assert(deepCopyTest(vec, copyvec));

	vec.clear();
	for(int i = 0; i < 5; i++)
	{
		vec.add_back(i);
	}
	Vector<int> assignvec;
	assignvec = vec; //assignment operator
	deepCopyTest(vec, assignvec);

	//Test deletion after copy (should not throw exception)
	Vector<int>* vec3 = new Vector<int>(vec);
	delete vec3;
	vec.add_back(10);
	vec.remove_back();

	std::cout << "All tests ran successfully!" << std::endl;
	return 0;
}

bool deepCopyTest(Vector<int>& vec, Vector<int>& copyvec)
{
	assert(vec.getSize() == copyvec.getSize());
	for (int i = 0; i < vec.getSize(); i++)
	{
		assert(vec.get(i) == copyvec.get(i));
	}
	vec.remove_back();
	assert(vec.get_back() != copyvec.get_back());
	assert(vec.getSize() != copyvec.getSize());
	copyvec.add_front(5);
	assert(vec.get_front() != 5);
	assert(copyvec.get_front() == 5);
	
	return true;
}
