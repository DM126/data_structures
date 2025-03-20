import java.util.*;

public class Tree<T extends Comparable<T>>
{
	private TreeNode<T> root;
	private int size;

	/**
	 * Creates a new empty tree
	 */
	public Tree()
	{
		root = null;
		size = 0;
	}

	/**
	 * Copies a tree
	 * 
	 * @param other the tree to copy
	 */
	public Tree(Tree<T> other)
	{
		root = new TreeNode<>(other.root);
		size = other.size;
	}

	/**
	 * Inserts an item into the tree. Ignores duplicates.
	 * 
	 * @param item the item to
	 * @return true if the item was added, false if it already exists
	 */
	public boolean insert(T item)
	{
		boolean inserted = false;
		if (isEmpty())
		{
			root = new TreeNode<T>(item);
			inserted = true;
		}
		else
		{
			inserted = root.insert(item);
		}

		if (inserted)
		{
			size++;
		}

		return inserted;
	}

	/**
	 * Searches for an item in the tree
	 * 
	 * @param item the item to find
	 * @return true if the item is in the tree
	 */
	public boolean find(T item)
	{
		if (isEmpty())
		{
			return false;
		}
	
		return root.find(item);
	}

	/**
	 * Finds and removes an item from the tree
	 * 
	 * @param item the item to remove
	 * @return true if the item was removed
	 */
	public boolean remove(T item)
	{
		if (isEmpty())
		{
			return false;
		}

		boolean removed; //set to true if the node is found and removed
		if (root.getData().equals(item)) //at the root
		{
			if (root.getLeft() == null && root.getRight() == null)
			{
				root = null;
			}
			else if (root.getLeft() == null)
			{
				root = root.getRight();
			}
			else if (root.getRight() == null)
			{
				root = root.getLeft();
			}
			else //2 children
			{
				root.getRight().swapMinimum(root);
			}

			removed = true;
		}
		else //search for the node
		{
			removed = root.remove(null, item);
		}

		if (removed)
		{
			size--;
		}

		return removed;
	}

	/**
	 * @return the item at the root of the tree
	 */
	public T peek()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("Tree is empty");
		}

		return root.getData();
	}

	/**
	 * @return true if there are no items in the tree
	 */
	public boolean isEmpty()
	{
		return size == 0;
	}

	/**
	 * @return the number of items in the tree
	 */
	public int getSize()
	{
		return size;
	}

	/**
	 * Removes all items from the tree
	 */
	public void clear()
	{
		root = null;
		size = 0;
	}

	/**
	 * Does an inorder traversal of the tree
	 * 
	 * @return a list of items in inorder
	 */
	public List<T> inorder()
	{
		List<T> items = new ArrayList<>(size);

		if (!isEmpty())
		{
			root.inorder(items);
		}

		return items;
	}

	/**
	 * Does a preorder traversal of the tree
	 * 
	 * @return a list of items in preorder
	 */
	public List<T> preorder()
	{
		ArrayList<T> items = new ArrayList<>(size);

		if (!isEmpty())
		{
			root.preorder(items);
		}

		return items;
	}

	/**
	 * Does a postorder traversal of the tree
	 * 
	 * @return a list of items in postorder
	 */
	public List<T> postorder()
	{
		List<T> items = new ArrayList<>(size);

		if (!isEmpty())
		{
			root.postorder(items);
		}

		return items;
	}

	@Override
	public String toString()
	{
		return root.toString();
	}

	@Override
	public boolean equals(Object other)
	{
		if (this == other)
		{
			return true;
		}

		if (other == null)
		{
			return false;
		}

		if (!(other instanceof TreeNode<?>))
		{
			return false;
		}

		if (size != ((Tree<?>)other).size)
		{
			return false;
		}

		if (!root.equals(((Tree<?>)other).root))
		{
			return false;
		}

		return true;
	}
}
