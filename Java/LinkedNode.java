public class LinkedNode<T>
{
	private T data;
	private LinkedNode<T> next;

	/**
	 * Creates a node
	 * @param item the data for the node to hold
	 */
	public LinkedNode(T item)
	{
		data = item;
		next = null;
	}

	/**
	 * Copies a node
	 * @param other the node to copy
	 */
	public LinkedNode(LinkedNode<T> other)
	{
		data = other.data;
		next = new LinkedNode<>(other.next);
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
	 * Sets the next node after this one
	 * @param newNext the node to connect this node to
	 */
	public void setNext(LinkedNode<T> newNext)
	{
		next = newNext;
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
