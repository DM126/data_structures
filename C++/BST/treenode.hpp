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

	//Inserts a value into one of the nodes children
	bool insert_node(const T& value);

	//Searches for a node with the given value
	bool find_node(const T& value) const;

	//Searches for and removes the node with the given value.
	//Moves the right child node up into its place.
	//Parent is the parent of the current node being looked at.
	bool remove_node(Node* parent, const T& value);

	//Finds the minimum value in a subtree, returns its value and removes its node.
	T swap_minimum(Node* parent);

	//Does an recursive traversal of the subtree,
	//adding items to the vector as it goes
	void inorder_node(vector<T>& items) const;
	void preorder_node(vector<T>& items) const;
	void postorder_node(vector<T>& items) const;

private:
	T data;
	Node* left;
	Node* right;
};

#endif
