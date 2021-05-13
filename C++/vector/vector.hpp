//Templated array implementation of a vector

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../array_collection.hpp"

template <typename T>
class Vector : public ArrayCollection<T>
{
public:
	Vector<T>();
	Vector<T>(int initial_capacity);

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
};

template <typename T>
Vector<T>::Vector() : ArrayCollection<T>() {}

template <typename T>
Vector<T>::Vector(int initial_capacity) : ArrayCollection<T>(initial_capacity) {}


template <typename T>
bool Vector<T>::add(int index, const T& value)
{
	if (index < 0 || index > this->size)
	{
		throw std::out_of_range("Vector::add(): index out of bounds: " + std::to_string(index));
	}

	//double the capacity if full
	if (this->isFull())
	{
		this->expandCapacity(this->capacity * 2);
	}

	//push everything back
	for (int i = this->size; i > index; i--)
	{
		this->array[i] = this->array[i-1];
	}
	this->array[index] = value;
	this->size++;

	return true;
}

template <typename T>
bool Vector<T>::add_back(const T& value)
{
	return add(this->size, value);
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
	if (this->isEmpty())
	{
		throw std::underflow_error("Vector::remove(): Vector is empty");
	}
	else if (index < 0 || index >= this->size)
	{
		throw std::out_of_range("Vector::remove(): index out of bounds: " + std::to_string(index));
	}

	int value = this->array[index];

	//move everything forward
	for (int i = index; i < this->size - 1; i++)
	{
		this->array[i] = this->array[i+1];
	}

	this->size--;

	return value;
}

template <typename T>
T Vector<T>::remove_back()
{
	return remove(this->size - 1);
}

template <typename T>
T Vector<T>::remove_front()
{
	return remove(0);
}


template <typename T>
T Vector<T>::get(int index) const
{
	if (index < 0 || index >= this->size)
	{
		throw std::out_of_range("Vector::get(): index out of bounds: " + std::to_string(index));
	}

	return this->array[index];
}

template <typename T>
T Vector<T>::get_back() const
{
	return get(this->size - 1);
}

template <typename T>
T Vector<T>::get_front() const
{
	return get(0);
}

#endif
