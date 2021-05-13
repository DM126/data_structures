//Contains a generic implementation of a templated array-based collection

#ifndef ARRAYCOLLECTION_HPP
#define ARRAYCOLLECTION_HPP

#include <iostream>

template <typename T>
class ArrayCollection
{
public:
	ArrayCollection<T>();
	ArrayCollection<T>(int initial_capacity);
	ArrayCollection<T>(const ArrayCollection<T>& other);
	~ArrayCollection<T>();
	ArrayCollection<T>& operator=(ArrayCollection<T> rhs); //uses copy-swap

	//Returns true if the collection has no items
	bool isEmpty() const;

	//Returns true if the collection's size is equal to its capacity
	bool isFull() const;

	//Returns the number of items in the collection
	int getSize() const;

	//Returns the capacity of the array
	int getCapacity() const;

	//Removes all items from the collection.
	void clear();

	//Expands the capacity of the collection.
	//Returns false if new_capacity is <= to the old capacity. //TODO TRUNCATE?
	bool expandCapacity(int new_capacity);

	//Print the collection's info, used for debugging
	void dump() const;

	//starting capacity if none specified
	static const int DEFAULT_CAPACITY = 10;

protected:
	//Adds an item to the collection at the specified index,
	//pushes everything behind it back
	bool add(int index, const T& value);
	
	//Removes an item from the collection and returns its value,
	//pushes everything behind it forward
	//Throws underflow_error if empty, or out_of_range if index is out of bounds
	T remove(int index);

	//Returns the item at teh specified index, without removing it.
	//Throws out_of_range if index is out of bounds
	T get(int index) const;

	int size; //number of items in the collection, signifies next index to add to
	int capacity; //capacity of the array
	T* array;
};

template <typename T>
ArrayCollection<T>::ArrayCollection() : ArrayCollection(DEFAULT_CAPACITY) {}

template <typename T>
ArrayCollection<T>::ArrayCollection(int initial_capacity)
{
	size = 0;
	capacity = initial_capacity;
	array = new T[capacity];
}

template <typename T>
ArrayCollection<T>::~ArrayCollection()
{
	delete[] array;
}

template <typename T>
ArrayCollection<T>::ArrayCollection(const ArrayCollection<T>& other)
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
ArrayCollection<T>& ArrayCollection<T>::operator=(ArrayCollection<T> rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	std::swap(array, rhs.array);

	return *this;
}

template <typename T>
bool ArrayCollection<T>::add(int index, const T& value)
{
	if (index < 0 || index > size)
	{
		throw std::out_of_range("ArrayCollection::add(): index out of bounds: " + std::to_string(index));
	}

	//double the capacity if full
	if (isFull())
	{
		expandCapacity(capacity * 2);
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
T ArrayCollection<T>::remove(int index)
{
	if (isEmpty())
	{
		throw std::underflow_error("ArrayCollection::remove(): collection is empty");
	}
	else if (index < 0 || index >= size)
	{
		throw std::out_of_range("ArrayCollection::remove(): index out of bounds: " + std::to_string(index));
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
T ArrayCollection<T>::get(int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("ArrayCollection::get(): index out of bounds: " + std::to_string(index));
	}

	return array[index];
}

template <typename T>
bool ArrayCollection<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
bool ArrayCollection<T>::isFull() const
{
	return size == capacity;
}

template <typename T>
int ArrayCollection<T>::getSize() const
{
	return size;
}

template <typename T>
int ArrayCollection<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
void ArrayCollection<T>::clear()
{
	size = 0;
}

template <typename T>
bool ArrayCollection<T>::expandCapacity(int new_capacity)
{
	//TODO TRUNCATE IF NEW CAPACITY IS SMALLER?

	if (new_capacity <= capacity)
	{
		return false;
	}

	//make the new array
	int* new_array = new int[new_capacity];

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
void ArrayCollection<T>::dump() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": " << array[i] << "\n";
	}
	std::cout << "size: " << size << "\n";
	std::cout << "capacity: " << capacity << std::endl;
}

#endif
