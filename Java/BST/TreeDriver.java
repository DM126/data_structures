package BST;

import java.util.ArrayList;
import java.util.Arrays;

public class TreeDriver
{
	public static void main(String[] args)
	{
		Tree<Integer> tree = new Tree<Integer>();
		assert(tree.isEmpty());

		//don't remove/find from an empty tree
		assert(!tree.find(10));
		assert(!tree.remove(10));

		// tree.insert(10);
		// tree.insert(20);
		// tree.remove(10);
		// fullDump(tree);
		// tree.insert(50);
		// fullDump(tree);

		// tree.insert(3);
		// tree.insert(5);
		// tree.insert(6);
		// tree.insert(4);
		// tree.insert(1);
		// tree.insert(2);
		// tree.insert(0);
		// tree.remove(6);
		// tree.remove(5);
		// tree.remove(1);
		// fullDump(tree);

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
		ArrayList<Integer> inorderList = tree.inorder();
		for (int i = 0; i < 6; i++)
		{
			assert(inorderList.get(i) == i);
		}

		//remove middle item and re-insert
		tree.remove(2);
		tree.insert(2);
		assert(tree.find(2));

		inorderList = tree.inorder();
		for (int i = 0; i < 6; i++)
		{
			assert(inorderList.get(i) == i);
		}

		tree.remove(0);
		tree.remove(1);
		assert(tree.peek() == 3);
		inorderList = tree.inorder();
		for (int i = 2; i < 6; i++)
		{
			assert(inorderList.get(i-2) == i);
		}

		assert(!tree.find(1));
		assert(!tree.remove(0));

		//test clear and re-inserting
		tree.clear();
		assert(tree.isEmpty());

		for (int i = 0; i < 6; i++)
		{
			tree.insert(i);
		}
		assert(tree.peek() == 0);
		assert(tree.getSize() == 6);
		inorderList = tree.inorder();
		for (int i = 0; i < 6; i++)
		{
			assert(inorderList.get(i) == i);
		}

		//test copy
		Tree<Integer> copytree = tree;
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
		Integer pre_array[] = {3, 1, 0, 2, 5, 4, 6};
		Integer post_array[] = {0, 2, 1, 4, 6, 5, 3};
		ArrayList<Integer> pre = new ArrayList<Integer>(Arrays.asList(pre_array));
		ArrayList<Integer> post = new ArrayList<Integer>(Arrays.asList(post_array));
		tree.clear();
		tree.insert(3);
		tree.insert(5);
		tree.insert(6);
		tree.insert(4);
		tree.insert(1);
		tree.insert(2);
		tree.insert(0);

		ArrayList<Integer> preorderList = tree.preorder();
		ArrayList<Integer> postorderList = tree.postorder();

		assert(pre == preorderList);
		assert(post == postorderList);

		System.out.println("All tests ran successfully!");
	}

	static void printTraversalList(ArrayList<Integer> list)
	{
		for (int i = 0; i < list.size(); i++)
		{
			System.out.println("i=" + i + ": " + list.get(i));
		}
		System.out.println();
	}

	static void fullDump(Tree<Integer> tree)
	{
		System.out.println(tree);

		System.out.println("inorder:\n");
		printTraversalList(tree.inorder());

		System.out.println("preorder:\n");
		printTraversalList(tree.preorder());

		System.out.println("postorder:\n");
		printTraversalList(tree.postorder());
	}
}
