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
	return ArrayCollection<T>::add(index, value);
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


template <typename T>
T Vector<T>::remove(int index)
{
	return ArrayCollection<T>::remove(index);
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
	return ArrayCollection<T>::get(index);
}

template <typename T>
T Vector<T>::get_back() const
{
	return this->get(this->size - 1);
}

template <typename T>
T Vector<T>::get_front() const
{
	return this->get(0);
}

#endif
