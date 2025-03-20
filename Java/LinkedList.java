import java.util.NoSuchElementException;

/**
 * Generic doubly linked list. Certain methods are protected so child classes
 * can rename them in their API.
 */
public abstract class LinkedList<T> {
	
	protected LinkedNode<T> head;
	protected LinkedNode<T> tail;
	protected int size;

	/**
	 * Creates a new linked list
	 */
	protected LinkedList()
	{
		head = null;
		tail = null;
		size = 0;
	}

	/**
	 * Copies a linked list
	 * 
	 * @param other the stack to copy
	 */
	protected LinkedList(LinkedList<T> other)
	{
		head = null;
		tail = null;
		size = 0;
		LinkedNode<T> curr = other.head;
		while (curr != null)
		{
			addBack(curr.getData());
			curr = curr.getNext();
		}
	}

	/**
	 * Adds an item to the end of the list.
	 * 
	 * @param item the item to add to the list
	 */
	protected void addBack(T item)
	{
		LinkedNode<T> newNode = new LinkedNode<>(item);

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail.setNext(newNode);
			tail = tail.getNext();
		}

		size++;
	}

	/**
	 * Adds an item to the end of the list.
	 * 
	 * @param item the item to add to the list
	 */
	protected void addFront(T item)
	{
		LinkedNode<T> newNode = new LinkedNode<>(item);

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode.setNext(head);
			head = newNode;
		}

		size++;
	}

	/**
	 * Returns and removes the item at the head of the list

	 * @return the item at the head of the list
	 * @throws NoSuchElementException if the list is empty
	 */
	protected T removeFront()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("List is empty");
		}

		T item = head.getData();
		head = head.getNext();
		if (head == null)
		{
			tail = null;
		}
		size--;
		return item;
	}

	/**
	 * Returns and removes the item at the end of the list
	 * 
	 * @return the item at the end of the list
	 * @throws NoSuchElementException if the list is empty
	 */
	protected T removeBack()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("List is empty");
		}

		T item = tail.getData();
		tail = tail.getPrevious();
		if (tail == null)
		{
			head = null;
		}
		size--;
		return item;
	}

	/**
	 * @return the item at the head of the list without removing it
	 * @throws NoSuchElementException if the list is empty
	 */
	protected T peekFront()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("List is empty");
		}

		return head.getData();
	}

	/**
	 * @return the item on top of the stack without removing it
	 * @throws NoSuchElementException if the queue is empty
	 */
	protected T peekBack()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("List is empty");
		}

		return tail.getData();
	}

	/**
	 * @return true if there are no items in the list
	 */
	public boolean isEmpty()
	{
		return size == 0;
	}

	/**
	 * @return the number of items in the list
	 */
	public int getSize()
	{
		return size;
	}

	/**
	 * Removes all items from the list
	 */
	public void clear()
	{
		head = null;
		tail = null;
		size = 0;
	}

	@Override
	@SuppressWarnings("unchecked")
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

		if (!(other instanceof LinkedList<?>))
		{
			return false;
		}

		if (size != ((LinkedList<?>)other).getSize())
		{
			return false;
		}

		LinkedNode<T> thisCurr = head;
		LinkedNode<T> otherCurr = ((LinkedList<T>)other).head;
		while (thisCurr != null)
		{
			if (!thisCurr.equals(otherCurr))
			{
				return false;
			}
			thisCurr = thisCurr.getNext();
			otherCurr = otherCurr.getNext();
		}

		return true;
	}

	@Override
	public String toString()
	{
		LinkedNode<T> curr = head;
		StringBuilder sb = new StringBuilder("[");
		while (curr != tail)
		{
			sb.append(curr.getData() + ", ");
			curr = curr.getNext();
		}

		//add the tail
		if (curr != null)
		{
			sb.append(curr.getData());
		}

		sb.append("]");

		return sb.toString();
	}
}
