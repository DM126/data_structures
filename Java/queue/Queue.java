
/**
 * Linked list implementation of a queue
 */
public class Queue<T> extends LinkedList<T>
{
	/**
	 * Creates a new queue
	 */
	public Queue()
	{
		super();
	}

	/**
	 * Copies a queue
	 * 
	 * @param other the stack to copy
	 */
	public Queue(Queue<T> other)
	{
		super(other);
	}

	/**
	 * Adds an item to the end of the queue.
	 * 
	 * @param item the item to add to the queue
	 */
	public void enqueue(T item)
	{
		super.addBack(item);
	}

	/**
	 * Returns and removes the item at the head of the queue

	 * @return the item at the head of the queue
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T dequeue()
	{
		return super.removeFront();
	}

	/**
	 * @return the item at the head of the queue without removing it
	 * @throws NoSuchElementException if the queue is empty
	 */
	public T peek()
	{
		return super.peekFront();
	}
}
