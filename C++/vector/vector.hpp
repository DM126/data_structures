//Templated array implementation of a vector

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
public:
	Vector<T>();
	Vector<T>(int initial_capacity);
	Vector<T>(const Vector<T>& other);
	~Vector<T>();
	Vector<T>& operator=(Vector<T> rhs); //uses copy-swap


	//Adds a value to the vector.
	//If the vector is at capacity it will be expanded.
	//Returns true if the value was successfully added, false otherwise.
	bool add(int index, const T& value); //adds to a specific index, pushes everything behind it back
	bool add_back(const T& value); //adds to the end of the vector
	bool add_front(const T& value); //Adds to the front of the vector, pushes everything back

	//Remove an item from the vector and returns its value.
	//Exits the program if vector is empty, or if index is invalid.
	T remove(int index);
	T remove_back();
	T remove_front();

	//Returns a value at a specific index, without removing it.
	//Exits program if vector is empty, or if index is invalid.
	T get(int index) const;
	T get_back() const;
	T get_front() const;

	//TODO add/get/remove a range within the array

	//Returns true if the vector has no items
	bool isEmpty() const;

	//Returns true if the vector's size is equal to its capacity
	bool isFull() const;

	//Returns the number of items in the vector
	int getSize() const;

	//Returns the capacity of the array
	int getCapacity() const;

	//Removes all items from the vector.
	void clear();

	//Expands the capacity of the vector.
	//Returns false if new_capacity is <= to the old capacity. //TODO TRUNCATE?
	bool expand_capacity(int new_capacity);

	//Print the vector's info, used for debugging
	void dump() const;

	//starting capacity if none specified
	static const int DEFAULT_CAPACITY = 10;

private:
	int size; //number of items in the vector, signifies next index to add to
	int capacity; //capacity of the array
	T* array;
};

//TODO duplicated code with stack - make a parent class?
template <typename T>
Vector<T>::Vector() : Vector(DEFAULT_CAPACITY) {}

template <typename T>
Vector<T>::Vector(int initial_capacity)
{
	size = 0;
	capacity = initial_capacity;
	array = new T[capacity];
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] array;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	array = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	std::swap(array, rhs.array);

	return *this;
}


template <typename T>
bool Vector<T>::add(int index, const T& value)
{
	if (index < 0 || index > size)
	{
		throw std::out_of_range("Vector::add(): index out of bounds: " + std::to_string(index));
	}

	//double the capacity if full
	if (isFull())
	{
		expand_capacity(capacity * 2);
	}

	//push everything back
	for (int i = size; i > index; i--)
	{
		array[i] = array[i-1];
	}
	array[index] = value;
	size++;

	return true;
}

template <typename T>
bool Vector<T>::add_back(const T& value)
{
	return add(size, value);
}

template <typename T>
bool Vector<T>::add_front(const T& value)
{
	return add(0, value);
}

//TODO use helper function like in C vector?
template <typename T>
T Vector<T>::remove(int index)
{
	if (isEmpty())
	{
		throw std::underflow_error("Vector::remove(): Vector is empty");
	}
	else if (index < 0 || index >= size)
	{
		throw std::out_of_range("Vector::remove(): index out of bounds: " + std::to_string(index));
	}

	int value = array[index];

	//move everything forward
	for (int i = index; i < size - 1; i++)
	{
		array[i] = array[i+1];
	}

	size--;

	return value;
}

template <typename T>
T Vector<T>::remove_back()
{
	return remove(size - 1);
}

template <typename T>
T Vector<T>::remove_front()
{
	return remove(0);
}


template <typename T>
T Vector<T>::get(int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Vector::get(): index out of bounds: " + std::to_string(index));
	}

	return array[index];
}

template <typename T>
T Vector<T>::get_back() const
{
	return get(size - 1);
}

template <typename T>
T Vector<T>::get_front() const
{
	return get(0);
}


template <typename T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
bool Vector<T>::isFull() const
{
	return size == capacity;
}

template <typename T>
int Vector<T>::getSize() const
{
	return size;
}

template <typename T>
int Vector<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
void Vector<T>::clear()
{
	size = 0;
}

template <typename T>
bool Vector<T>::expand_capacity(int new_capacity)
{
	//TODO TRUNCATE IF NEW CAPACITY IS SMALLER?
	if (new_capacity <= capacity)
	{
		return false;
	}

	T* new_array = new T[new_capacity];

	//copy the values over
	for (int i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}

	//replace the old array
	delete[] array;
	array = new_array;
	capacity = new_capacity;

	return true;
}

template <typename T>
void Vector<T>::dump() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": " << array[i] << "\n";
	}
	std::cout << "size: " << size << "\n";
	std::cout << "capacity: " << capacity << std::endl;
}

#endif
