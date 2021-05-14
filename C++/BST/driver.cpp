#include <cassert>

#include "tree.hpp"

//Used for debugging
//Prints the contents of an vector
void print_traversal_array(const std::vector<int>& vec);

//Calls dump as well as print_traversal_array for each traversal
void full_dump(const Tree<int>& tree);

int main()
{
	Tree<int> tree;
	assert(tree.isEmpty());

	// tree.insert(10);
	// tree.insert(20);
	// tree.delete(10);
	// full_dump(tree);
	// tree.insert(50);
	// full_dump(tree);
	// exit(0);

	// tree.insert(3);
	// tree.insert(5);
	// tree.insert(6);
	// tree.insert(4);
	// tree.insert(1);
	// tree.insert(2);
	// tree.insert(0);
	// tree.delete(6);
	// tree.delete(5);
	// tree.delete(1);
	// full_dump(tree);
	// exit(0);

	//test insert
	tree.insert(0);
	assert(!tree.isEmpty());
	assert(tree.peek() == 0);
	tree.insert(1);
	assert(tree.peek() == 0);
	assert(tree.getSize() == 2);

	//add to the tree in order
	for (int i = 2; i < 6; i++)
	{
		tree.insert(i);
	}
	assert(tree.peek() == 0);
	assert(tree.getSize() == 6);

	//test inorder
	std::vector<int> inorder_vec = tree.inorder();
	for (int i = 0; i < 6; i++)
	{
		assert(inorder_vec[i] == i);
	}

	//TODO

	//test copy
	Tree<int> copytree = tree;
	assert(tree.peek() == copytree.peek());
	assert(tree.getSize() == copytree.getSize());
	assert(tree.preorder() == copytree.preorder());
	copytree.remove(0);
	assert(tree.peek() == 0);
	copytree.clear();
	tree.insert(10);
	assert(tree.peek() != 10);

	//test other traversals
	//tree will look like this:
	//      3
	//  1       5
	//0   2   4   6
	std::vector<int> pre = {3, 1, 0, 2, 5, 4, 6};
	std::vector<int> post = {0, 2, 1, 4, 6, 5, 3};
	tree.clear();
	tree.insert(3);
	tree.insert(5);
	tree.insert(6);
	tree.insert(4);
	tree.insert(1);
	tree.insert(2);
	tree.insert(0);

	std::vector<int> preorder_array = tree.preorder();
	std::vector<int> postorder_array = tree.postorder();

	assert(pre == preorder_array);
	assert(post == postorder_array);

	std::cout << "All tests ran successfully!" << std::endl;
	return 0;
}

void print_traversal_array(const std::vector<int>& vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << "i=" << i << ": " << vec[i] << "\n";
	}
	std::cout << std::endl;
}

void full_dump(const Tree<int>& tree)
{
	tree.dump();

	std::cout << "inorder:\n";
	print_traversal_array(tree.inorder());

	std::cout << "preorder:\n";
	print_traversal_array(tree.preorder());

	std::cout << "postorder:\n";
	print_traversal_array(tree.postorder());
}
