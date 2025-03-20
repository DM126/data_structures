import java.util.NoSuchElementException;

/**
 * Linked list implementation of a double-ended queue
 */
public class Deque<T> extends LinkedList<T>
{
	/**
	 * Creates a new queue
	 */
	public Deque()
	{
		super();
	}

	/**
	 * Copies a queue
	 * 
	 * @param other the stack to copy
	 */
	public Deque(Deque<T> other)
	{
		super(other);
	}

	/**
	 * Adds an item to the end of the queue.
	 * 
	 * @param item the item to add to the queue
	 */
	public void pushBack(T item)
	{
		super.addBack(item);
	}

	/**
	 * Adds an item to the end of the queue.
	 * 
	 * @param item the item to add to the queue
	 */
	public void pushFront(T item)
	{
		super.addFront(item);
	}

	/**
	 * Returns and removes the item at the head of the queue

	 * @return the item at the head of the queue
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T popFront()
	{
		return super.removeFront();
	}

	/**
	 * Returns and removes the item at the end of the queue

	 * @return the item at the end of the queue
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T popBack()
	{
		return super.removeBack();
	}

	/**
	 * @return the item on top of the stack without removing it
	 * @throws NoSuchElementException if the queue is empty
	 */
	@Override
	public T peekFront()
	{
		return super.peekFront();
	}

	/**
	 * @return the item on top of the stack without removing it
	 * @throws NoSuchElementException if the queue is empty
	 */
	@Override
	public T peekBack()
	{
		return super.peekBack();
	}
}
