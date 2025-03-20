
/**
 * Node for a doubly linked list.
 */
public class LinkedNode<T>
{
	private T data;
	private LinkedNode<T> next;
	private LinkedNode<T> previous;

	/**
	 * Creates a node
	 * @param item the data for the node to hold
	 */
	public LinkedNode(T item)
	{
		data = item;
		next = null;
		previous = null;
	}

	/**
	 * @return the node's data
	 */
	public T getData()
	{
		return data;
	}

	/**
	 * Updates the data in the node
	 * 
	 * @param newValue the new data
	 */
	public void setData(T newValue)
	{
		data = newValue;
	}

	/**
	 * @return the next node
	 */
	public LinkedNode<T> getNext()
	{
		return next;
	}

	/**
	 * Sets the next node after this one.
	 * Will set the previous node of newNext to this node.
	 * @param newNext the node to connect this node to
	 */
	public void setNext(LinkedNode<T> newNext)
	{
		next = newNext;
		newNext.setPrevious(this);
	}

	/**
	 * @return the previous node
	 */
	public LinkedNode<T> getPrevious()
	{
		return previous;
	}

	/**
	 * Sets the node before this one.
	 * Use setNext() for setting order of nodes.
	 * @param newNext the node to connect this node to
	 */
	private void setPrevious(LinkedNode<T> newPrevious)
	{
		previous = newPrevious;
	}

	@Override
	public String toString()
	{
		return data.toString();
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

		if (!(other instanceof LinkedNode<?>))
		{
			return false;
		}

		if (!data.equals(((LinkedNode<?>)other).data))
		{
			return false;
		}

		return true;
	}
}
