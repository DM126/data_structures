//templated array implementation of a stack

#ifndef STACK_HPP
#define STACK_HPP

#include "../array_collection.hpp"

template <typename T>
class Stack: public ArrayCollection<T>
{
public:
	Stack<T>();
	Stack<T>(int initial_capacity);

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
};

template <typename T>
Stack<T>::Stack() : ArrayCollection<T>() {}

template <typename T>
Stack<T>::Stack(int initial_capacity) : ArrayCollection<T>(initial_capacity) {}

template <typename T>
bool Stack<T>::push(const T& value)
{
	if (this->isFull())
	{
		this->expandCapacity(this->capacity * 2);
	}

	this->array[this->size] = value;
	this->size++;

	return true;
}

template <typename T>
T Stack<T>::pop()
{
	if (this->isEmpty())
	{
		throw std::underflow_error("Stack::pop(): stack is empty");
	}

	this->size--;
	return this->array[this->size];
}

template <typename T>
T Stack<T>::peek() const
{
	if (this->isEmpty())
	{
		throw std::out_of_range("Stack::peek(): stack is empty");
	}

	return this->array[this->size - 1];
}

#endif
