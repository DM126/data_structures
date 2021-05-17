import java.util.*;

/**
 * Linked list implementation of a queue
 */
public class Queue<T>
{
	private Node<T> head;
	private Node<T> tail;
	private int size;

	/**
	 * Creates a new queue
	 */
	public Queue()
	{
		head = null;
		tail = null;
		size = 0;
	}

	/**
	 * Copies a queue
	 * 
	 * @param other the stack to copy
	 */
	public Queue(Queue<T> other)
	{
		head = null;
		tail = null;
		Node<T> curr = other.head;
		while (curr != null)
		{
			enqueue(curr.getData());
			curr = curr.getNext();
		}
	}

	/**
	 * Adds an item to the end of the queue.
	 * 
	 * @param item the item to add to the queue
	 */
	public void enqueue(T item)
	{
		Node<T> newNode = new Node<T>(item);

		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail.setNext(new Node<T>(item));
			tail = tail.getNext();
		}

		size++;
	}

	/**
	 * Returns and removes the item at the head of the queue

	 * @return the item at the head of the queue
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T dequeue()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("Queue is empty");
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
	 * @return the item on top of the stack without removing it
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T peek()
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("Queue is empty");
		}

		return head.getData();
	}

	/**
	 * @return true if there are no items in the queue
	 */
	public boolean isEmpty()
	{
		return size == 0;
	}

	/**
	 * @return the number of items in the queue
	 */
	public int getSize()
	{
		return size;
	}

	/**
	 * Removes all items from the queue
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

		if (!(other instanceof Queue<?>))
		{
			return false;
		}

		if (size != ((Queue<?>)other).getSize())
		{
			return false;
		}

		Node<T> thisCurr = head;
		Node<T> otherCurr = ((Queue<T>)other).head;
		while (head != null)
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
		String queueString = "[";

		Node<T> curr = head;
		while (curr != tail)
		{
			queueString += curr.getData() + ", ";
			curr = curr.getNext();
		}

		//add the tail
		if (curr != null)
		{
			queueString += curr.getData();
		}

		queueString += "]";

		return queueString;
	}
}
