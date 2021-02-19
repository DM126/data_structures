//Node used for linked lists

#ifndef NODE_HPP
#define NODE_HPP

#include <utility>

template <typename T>
class Node
{
public:
	Node(T value);
	Node(const Node<T>& other);
	~Node();
	Node<T>& operator=(Node<T> rhs); //uses copy swap idiom

	T data;
	Node<T>* next;
};

template <typename T>
Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
}

template <typename T>
Node<T>::Node(const Node& other)
{
	data = other.value;
	
	if (other.next == nullptr)
	{
		next = nullptr;
	}
	else
	{
		next = new Node(other->next);
	}
}

template <typename T>
Node<T>::~Node()
{
	delete next;
}

template <typename T>
Node<T>& Node<T>::operator=(Node<T> rhs)
{
	data = rhs.data;
	std::swap(next, rhs.next);
}

#endif