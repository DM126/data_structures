//Templated implementation of a binary tree node

#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>

template <typename T>
class Node
{
public:
	Node();
	Node(const Node<T>& other);
	~Node();
	Node<T>& operator=(Node<T> rhs); //uses copy-swap
};

#endif