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
	std::vector<T> inorder() const;
	std::vector<T> preorder() const;
	std::vector<T> postorder() const;

	//Print the tree's info, used for debugging
	void dump() const;

private:
	Node<T>* root;
	int size;
};

template <typename T>
Tree<T>::Tree()
{
	size = 0;
	root = nullptr;
}

template <typename T>
Tree<T>::~Tree()
{
	delete root;
}

template <typename T>
Tree<T>::Tree(const Tree& other)
{
	size = other.size;
	root = nullptr;

	if (!other.isEmpty())
	{
		root = new Node<T>(*other.root);
	}
}

template <typename T>
Tree<T>& Tree<T>::operator=(Tree<T> rhs)
{
	size = rhs.size;
	std::swap(root, rhs.root);

	return *this;
}

template <typename T>
bool Tree<T>::insert(const T& value)
{
	bool inserted = false;
	if (isEmpty())
	{
		root = new Node<T>(value);
		inserted = true;
	}
	else
	{
		inserted = root->insert(value);
	}

	if (inserted)
	{
		size++;
	}

	return inserted;
}

template <typename T>
bool Tree<T>::find(const T& value) const
{
	if (isEmpty())
	{
		return false;
	}

	return root->find(value);
}

template <typename T>
bool Tree<T>::remove(const T& value)
{
	if (isEmpty())
	{
		return false;
	}

	bool removed; //set to true if the node is found and removed
	if (root->data == value) //at the root
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{
			Node<T>* temp = root;
			root = root->right;
			temp->right = nullptr;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			Node<T>* temp = root;
			root = root->left;
			temp->left = nullptr;
			delete temp;
		}
		else //2 children
		{
			root->right->swap_minimum(root);
		}

		removed = true;
	}
	else //search for the node
	{
		removed = root->remove(nullptr, value);
	}

	if (removed)
	{
		size--;
	}

	return removed;
}

template <typename T>
T Tree<T>::peek() const
{
	if (isEmpty())
	{
		throw std::underflow_error("Tree::peek(): tree is empty");
	}

	return root->data;
}

template <typename T>
bool Tree<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
int Tree<T>::getSize() const
{
	return size;
}

template <typename T>
void Tree<T>::clear()
{
	delete root;
	root = nullptr;
	size = 0;
}

template <typename T>
std::vector<T> Tree<T>::inorder() const
{
	std::vector<T> items;

	if (!isEmpty())
	{
		root->inorder(items);
	}

	return items;
}

template <typename T>
std::vector<T> Tree<T>::preorder() const
{
	std::vector<T> items;

	if (!isEmpty())
	{
		root->preorder(items);
	}
	
	return items;
}

template <typename T>
std::vector<T> Tree<T>::postorder() const
{
	std::vector<T> items;

	if (!isEmpty())
	{
		root->postorder(items);
	}
	
	return items;
}

template <typename T>
void Tree<T>::dump() const
{
	if (isEmpty())
	{
		printf("tree is empty.\n");
	}
	else
	{
		root->dump();
		printf("\nsize: %d\n", size);
	}
}

#endif
