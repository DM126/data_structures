//Templated implementation of a basic (unbalanced) binary search tree

#ifndef TREE_HPP
#define TREE_HPP

#include "treenode.hpp"

template <typename T>
class Tree
{
public:
	Tree();
	Tree(const Tree<T>& other);
	~Tree();
	Tree<T>& operator=(Tree<T> rhs); //uses copy-swap
};

#endif