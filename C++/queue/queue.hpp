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

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> rhs)
{
	size = rhs.size;
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);

	return *this;
}

template <typename T>
void Queue<T>::enqueue(const T& data)
{
	Node<T>* newnode(data);

	if (isEmpty())
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}

	size++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		throw std::underflow_error("Queue::dequeue(): queue is empty");
	}

	int value = head->data;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;

	if (head == nullptr)
	{
		tail = nullptr;
	}

	return value;
}

template <typename T>
T Queue<T>::peek() const
{
	if (isEmpty())
	{
		throw std::out_of_range("Queue::peek(): queue is empty");
	}

	return head->data;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
void Queue<T>::clear()
{
	delete head;
	size = 0;
	head = tail = nullptr;
}

template <typename T>
void Queue<T>::dump() const
{
	if (isEmpty())
	{
		std::cout << "Queue is empty." << std::endl;
	}
	else
	{
		Node<T>* curr = head;
		for (int i = 0; curr != nullptr; i++, curr = curr->next)
		{
			std::cout << i << ": " << curr->data << "\n";
		}

		std::cout << "size: " << size << std::endl;
	}
}

#endif
