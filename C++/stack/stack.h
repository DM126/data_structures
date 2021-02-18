//templated stack

#ifndef STACK_H
#define STACK_H

#include <exception>
#include <iostream>

template <typename T>
class Stack
{
public:
	Stack<T>();
	Stack<T>(int initial_capacity);
	Stack<T>(const Stack<T>& other);
	~Stack<T>();
	const Stack<T>& operator=(const Stack<T>& rhs);

	//Adds an item to the stack.
	//If the stack is at capacity it will be expanded.
	//Returns true if the value was successfully added, false otherwise.
	bool push(const T& value);

	//Remove an item from the stack and returns its value.
	//Throws underflow_error if stack is empty.
	T pop();

	//Returns the value on top of the stack, without removing it.
	//Throws out_of_range if stack is empty.
	T peek() const;

	//Returns true if the stack has no items
	bool isEmpty() const;

	//Returns true if the stack's size is equal to its capacity
	bool isFull() const;

	//Returns the number of items in the stack
	int getSize() const;

	//Removes all items from the stack.
	void clear();

	//Expands the capacity of the stack.
	//Throws invalid_argument if new_capacity is <= to the old capacity //TODO TRUNCATE?
	bool expandCapacity(int new_capacity);

	//Print the stack's info, used for debugging
	void dump() const;

private:
	int size; //number of items in the stack, signifies next index to push to
	int capacity; //capacity of the array
	T* array; //Better to use vector here, but dynamic memory is fun!

	static const int DEFAULT_CAPACITY = 10; //starting capacity if none specified
};

template <typename T>
Stack<T>::Stack() : Stack(DEFAULT_CAPACITY) {}

template <typename T>
Stack<T>::Stack(int initial_capacity)
{
	size = 0;
	capacity = DEFAULT_CAPACITY;
	array = new T[capacity];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] array;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	array = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

//TODO TEST WITH COPY SWAP
template <typename T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] array;

		size = rhs.size;
		capacity = rhs.capacity;
		array = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			array[i] = rhs.array[i];
		}
	}

	return *this;
}

template <typename T>
bool Stack<T>::push(const T& value)
{
	if (isFull())
	{
		expandCapacity(capacity * 2);
	}

	array[size] = value;
	size++;

	return true;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw std::underflow_error();
	}

	size--;
	return array[size];
}

template <typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
	{
		throw std::out_of_range();
	}

	return array[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
bool Stack<T>::isFull() const
{
	return size == capacity;
}

template <typename T>
int Stack<T>::getSize() const
{
	return size;
}

template <typename T>
void Stack<T>::clear()
{
	size = 0;
}

template <typename T>
bool Stack<T>::expandCapacity(int new_capacity)
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
void Stack<T>::dump() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": " << array[i] << "\n";
	}
	std::cout << "size: " << size << "\n";
	std::cout << "capacity: " << capacity << std::endl;
}

#endif
