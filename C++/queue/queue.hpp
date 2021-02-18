//Templated linked list implementation of a queue

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "node.hpp"

template <typename T>
class Queue
{
public:
	Queue();
	Queue(const Queue<T>& other);
	~Queue();
	Queue<T>& operator=(Queue<T> rhs); //uses copy swap idiom

	//Adds an item to the tail of the queue
	void enqueue(const T& data);

	//Removes and returns the item at the head of the queue.
	//Throws underflow_error if queue is empty.
	T dequeue();

	//Returns the item at the head of the queue.
	//Throws out_of_range if the queue is empty.
	T peek() const;

	//Returns true if the queue contains no items
	bool isEmpty() const;

	//Removes all items from the queue.
	void clear();

	//Prints the queue's info, used for debugging
	void dump() const;

private:
	int size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	delete head;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	size = 0;
	head = nullptr;
	tail = nullptr;

	Node<T>* curr = other->head;
	while (curr != nullptr)
	{
		enqueue(curr->data);
		curr = curr->next;
	}
}

#endif
