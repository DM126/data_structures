package BST;

import java.util.ArrayList;

public class TreeNode<T extends Comparable<T>>
{
	private T data;
	private TreeNode<T> left;
	private TreeNode<T> right;

	/**
	 * Creates a new node
	 * 
	 * @param item the data for this node
	 */
	public TreeNode(T item)
	{
		data = item;
		left = null;
		right = null;
	}

	/**
	 * Copies a node
	 * 
	 * @param other the node to copy
	 */
	public TreeNode(TreeNode<T> other)
	{
		data = other.data;
		left = null;
		right = null;

		if (other.left != null)
		{
			left = new TreeNode<T>(other.left);
		}

		if (other.right != null)
		{
			left = new TreeNode<T>(other.right);
		}
	}

	/**
	 * Inserts an item into the tree
	 * 
	 * @param item the item to insert
	 * @return true if the item was inserted, false if it already exists
	 */
	public boolean insert(T item)
	{
		boolean inserted = false;
		if (item.compareTo(this.data) < 0)
		{
			if (left == null)
			{
				left = new TreeNode<T>(item);
				inserted = true;
			}
			else
			{
				inserted = left.insert(item);
			}
		}
		else if (item.compareTo(this.data) > 0)
		{
			if (right == null)
			{
				right = new TreeNode<T>(item);
				inserted = true;
			}
			else
			{
				inserted = right.insert(item);
			}
		}

		return inserted;
	}

	/**
	 * Searches for an item
	 * 
	 * @param item the item to search for
	 * @return true if the item is in the tree
	 */
	public boolean find(T item)
	{
		boolean found = false;
		if (item.compareTo(this.data) < 0)
		{
			if (left != null)
			{
				found = left.find(item);
			}
		}
		else if (item.compareTo(this.data) > 0)
		{
			if (right != null)
			{
				found = right.find(item);
			}
		}
		else //item == this.data
		{
			found = true;
		}

		return found;
	}

	/**
	 * Searches for and removes a node with the given data
	 * 
	 * @param parent the parent of this node
	 * @param item the item of the node to remove
	 * @return true if the node was removed
	 */
	public boolean remove(TreeNode<T> parent, T item)
	{
		boolean removed = false;
		if (item.compareTo(this.data) < 0)
		{
			if (left != null)
			{
				removed = left.remove(this, item);
			}
		}
		else if (item.compareTo(this.data) > 0)
		{
			if (right != null)
			{
				removed = right.remove(this, item);
			}
		}
		else //item == this.data
		{
			TreeNode<T> node_to_move_up;
			if (left == null && right == null)
			{
				node_to_move_up = null;
			}
			else if (left == null)
			{
				node_to_move_up = right;
			}
			else if (right == null)
			{
				node_to_move_up = left;
			}
			else //2 children
			{
				data = right.swapMinimum(this);
				return true;
			}

			if (parent.left == this)
			{
				parent.left = node_to_move_up;
			}
			else
			{
				parent.right = node_to_move_up;
			}

			removed = true;
		}

		return removed;
	}

	/**
	 * Finds the smallest value in a subtree and swaps it with a node to be
	 * removed.
	 * 
	 * @param parent the parent of this node
	 * @return The smallest node in the subtree
	 */
	public T swapMinimum(TreeNode<T> parent)
	{
		if (left == null) //at the smallest value
		{
			T item = this.data;
			remove(parent, data);
			return item;
		}

		return left.swapMinimum(this); //keep going left
	}

	/**
	 * @return the item held by this node
	 */
	public T getData()
	{
		return data;
	}

	/**
	 * @return the left child node
	 */
	public TreeNode<T> getLeft()
	{
		return left;
	}

	/**
	 * @return the right child node
	 */
	public TreeNode<T> getRight()
	{
		return right;
	}

	/**
	 * Sets the data held by this node
	 * 
	 * @param newData the new data for this node
	 */
	public void setData(T newData)
	{
		data = newData;
	}

	/**
	 * Sets the left child node
	 * 
	 * @param newLeft the new left child
	 */
	public void setLeft(TreeNode<T> newLeft)
	{
		left = newLeft;
	}

	/**
	 * Sets the right child node
	 * 
	 * @param newRight the new right child
	 */
	public void setRight(TreeNode<T> newRight)
	{
		right = newRight;
	}

	/**
	 * Does an inorder traversal of the tree
	 * 
	 * @param items the list to add the items to
	 */
	public void inorder(ArrayList<T> items)
	{
		if (left != null)
		{
			left.inorder(items);
		}

		items.add(data);

		if (right != null)
		{
			right.inorder(items);
		}
	}

	/**
	 * Does a preorder traversal of the tree
	 * 
	 * @param items the list to add the items to
	 */
	public void preorder(ArrayList<T> items)
	{
		items.add(data);

		if (left != null)
		{
			left.preorder(items);
		}

		if (right != null)
		{
			right.preorder(items);
		}
	}

	/**
	 * Does a postorder traversal of the tree
	 * 
	 * @param items the list to add the items to
	 */
	public void postorder(ArrayList<T> items)
	{
		if (left != null)
		{
			left.postorder(items);
		}

		if (right != null)
		{
			right.postorder(items);
		}

		items.add(data);
	}

	@Override
	public String toString()
	{
		String treeString = "(";

		if (left != null)
		{
			treeString += left;
		}

		treeString += data;

		if (right != null)
		{
			treeString += right;
		}

		treeString += ")";

		return treeString;
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

		if (!data.equals(((TreeNode<?>)other).data))
		{
			return false;
		}

		if (left != null && !left.equals(((TreeNode<?>)other).left))
		{
			return false;
		}

		if (right != null && !right.equals(((TreeNode<?>)other).right))
		{
			return false;
		}

		return true;
	}
}
