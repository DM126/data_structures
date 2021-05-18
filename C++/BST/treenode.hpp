//Templated implementation of a binary tree node

#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <vector>

template <typename T>
class Node
{
public:
	Node(const T& value);
	Node(const Node<T>& other);
	~Node();
	Node<T>& operator=(Node<T> rhs); //uses copy-swap

	//Inserts a value into one of the nodes children
	bool insert(const T& value);

	//Searches for a node with the given value
	bool find(const T& value) const;

	//Searches for and removes the node with the given value.
	//Moves the right child node up into its place.
	//Parent is the parent of the current node being looked at.
	bool remove(Node<T>* parent, const T& value);

	//Finds the minimum value in a subtree, returns its value and removes its node.
	T swap_minimum(Node<T>* parent);

	//Does an recursive traversal of the subtree,
	//adding items to the vector as it goes
	void inorder(std::vector<T>& items) const;
	void preorder(std::vector<T>& items) const;
	void postorder(std::vector<T>& items) const;

	//Print the node's info, used for debugging
	void dump() const;

	T data;
	Node* left;
	Node* right;

private:
	Node<T>* copyNode(const Node<T>* other);
};

template <typename T>
Node<T>::Node(const T& value)
{
	data = value;
	left = nullptr;
	right = nullptr;
}

template <typename T>
Node<T>::Node(const Node<T>& other)
{
	data = other.data;
	left = nullptr;
	right = nullptr;
	
	if (other.left != nullptr)
	{
		left = new Node<T>(*other.left);
	}

	if (other.right != nullptr)
	{
		right = new Node<T>(*other.right);
	}
}

template <typename T>
Node<T>::~Node()
{
	delete left;
	delete right;
}

template <typename T>
Node<T>& Node<T>::operator=(Node<T> rhs)
{
	data = rhs.data;
	std::swap(left, rhs.left);
	std::swap(right, rhs.right);

	return *this;
}

template <typename T>
bool Node<T>::insert(const T& value)
{
	bool inserted = false;
	if (value < this->data)
	{
		if (left == nullptr)
		{
			left = new Node<T>(value);
			inserted = true;
		}
		else
		{
			inserted = left->insert(value);
		}
	}
	else if (value > this->data)
	{
		if (right == nullptr)
		{
			right = new Node<T>(value);
			inserted = true;
		}
		else
		{
			inserted = right->insert(value);
		}
	}

	return inserted;
}

template <typename T>
bool Node<T>::find(const T& value) const
{
	bool found = false;
	if (value < this->data)
	{
		if (left != nullptr)
		{
			found = left->find(value);
		}
	}
	else if (value > this->data)
	{
		if (right != nullptr)
		{
			found = right->find(value);
		}
	}
	else //value == this->data
	{
		found = true;
	}

	return found;
}

template <typename T>
bool Node<T>::remove(Node* parent, const T& value)
{
	bool removed = false;
	if (value < this->data)
	{
		if (left != nullptr)
		{
			removed = left->remove(this, value);
		}
	}
	else if (value > this->data)
	{
		if (right != nullptr)
		{
			removed = right->remove(this, value);
		}
	}
	else //value == this->data
	{
		Node* node_to_move_up;
		if (left == nullptr && right == nullptr)
		{
			node_to_move_up = nullptr;
		}
		else if (left == nullptr)
		{
			node_to_move_up = right;
		}
		else if (right == nullptr)
		{
			node_to_move_up = left;
		}
		else //2 children
		{
			data = right->swap_minimum(this);
			return true;
		}

		if (parent->left == this)
		{
			parent->left = node_to_move_up;
		}
		else
		{
			parent->right = node_to_move_up;
		}

		//delete the removed node
		left = nullptr;
		right = nullptr;
		delete this;

		removed = true;
	}

	return removed;
}

template <typename T>
T Node<T>::swap_minimum(Node* parent)
{
	if (left == nullptr)
	{
		int value = this->data;
		remove(parent, data);
		return value;
	}
	
	return left->swap_minimum(this);
}

template <typename T>
void Node<T>::inorder(std::vector<T>& items) const
{
	if (left != nullptr)
	{
		left->inorder(items);
	}
	items.push_back(data);
	if (right != nullptr)
	{
		right->inorder(items);
	}
}

template <typename T>
void Node<T>::preorder(std::vector<T>& items) const
{
	items.push_back(data);
	if (left != nullptr)
	{
		left->preorder(items);
	}
	if (right != nullptr)
	{
		right->preorder(items);
	}
}

template <typename T>
void Node<T>::postorder(std::vector<T>& items) const
{
	if (left != nullptr)
	{
		left->postorder(items);
	}
	if (right != nullptr)
	{
		right->postorder(items);
	}
	items.push_back(data);
}

template <typename T>
void Node<T>::dump() const
{
	std::cout << "(";

	if (left != nullptr)
	{
		left->dump();
	}

	std::cout << data;

	if (right != nullptr)
	{
		right->dump();
	}

	std::cout << ")";
}

#endif
