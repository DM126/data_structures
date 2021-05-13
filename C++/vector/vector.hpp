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
	int remove(int index);
	int remove_back();
	int remove_front();

	//Returns a value at a specific index, without removing it.
	//Exits program if vector is empty, or if index is invalid.
	int get(int index) const;
	int get_back() const;
	int get_front() const;

	//TODO add/get/remove a range within the array

	//Returns true if the vector has no items
	bool isEmpty() const;

	//Returns true if the vector's size is equal to its capacity
	bool isFull() const;

	//Removes all items from the vector.
	void clear();

	//Expands the capacity of the vector.
	//Returns false if new_capacity is <= to the old capacity. //TODO TRUNCATE?
	bool expand_capacity(int new_capacity);

	//Print the vector's info, used for debugging
	void dump() const;
};

template <typename T>
Vector<T>::Vector()
{

}

template <typename T>
Vector<T>::Vector(int initial_capacity)
{

}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{

}

template <typename T>
Vector<T>::~Vector()
{

}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> rhs)
{

}


template <typename T>
bool Vector<T>::add(int index, const T& value)
{

}

template <typename T>
bool Vector<T>::add_back(const T& value)
{

}

template <typename T>
bool Vector<T>::add_front(const T& value)
{

}


template <typename T>
int Vector<T>::remove(int index)
{

}

template <typename T>
int Vector<T>::remove_back()
{

}

template <typename T>
int Vector<T>::remove_front()
{

}


template <typename T>
int Vector<T>::get(int index) const
{

}

template <typename T>
int Vector<T>::get_back() const
{

}

template <typename T>
int Vector<T>::get_front() const
{

}


template <typename T>
bool Vector<T>::isEmpty() const
{

}

template <typename T>
bool Vector<T>::isFull() const
{

}

template <typename T>
void Vector<T>::clear()
{

}

template <typename T>
bool Vector<T>::expand_capacity(int new_capacity)
{

}

template <typename T>
void Vector<T>::dump() const
{

}

#endif
