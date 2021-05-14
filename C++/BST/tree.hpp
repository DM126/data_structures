//Templated implementation of a basic (unbalanced) binary search tree

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include "treenode.hpp"

template <typename T>
class Tree
{
public:
	Tree();
	Tree(const Tree<T>& other);
	~Tree();
	Tree<T>& operator=(Tree<T> rhs); //uses copy-swap

	//Adds a value to the tree.
	//Returns false if the value already exists.
	bool insert(const T& value);

	//Returns true if the value exists in the tree
	bool find(const T& value) const;

	//Removes a specific value from the tree, returns false if the value is not present
	bool remove(const T& value);

	//Returns the value at the root of the tree without removing it.
	//Throws underflow_error if the tree is empty.
	T peek() const;

	//Returns true if the tree contains no items
	bool isEmpty() const;

	//Returns the number of items in the tree
	int getSize() const;

	//Removes all items from the tree.
	void clear();

	//Tree traversals, returns a vector determined by traversal order
	vector<T> inorder() const;
	vector<T> preorder() const;
	vector<T> postorder() const;

	//Print the tree's info, used for debugging
	void dump() const;

private:
	Node<T>* root;
	int size;
};

#endif
