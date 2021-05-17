import java.util.*;

/**
 * Array implementation of a stack
 */
public class Stack<T> extends ArrayCollection<T>
{
	/**
	 * Creates a new stack
	 */
	public Stack()
	{
		super();
	}

	/**
	 * Creates a new stack with a specified initial capacity
	 */
	public Stack(int initialCapacity)
	{
		super(initialCapacity);
	}

	/**
	 * Copies the stack
	 * 
	 * @param other the stack to copy
	 */
	public Stack(Stack<T> other)
	{
		super(other);
	}

	/**
	 * Adds an item to the stack.
	 * Expands capacity if full.
	 * @param item the item to add to the stack
	 */
	public void push(T item)
	{
		add(size, item);
	}

	/**
	 * Returns and removes the item on top of the stack
	 * 
	 * @return the item on top of the stack
	 * @throws EmptyStackException if the stack is empty
	 */
	public T pop()
	{
		return remove(size - 1);
	}

	/**
	 * @return the item on top of the stack without removing it
	 * @throws EmptyStackException if the stack is empty
	 */
	public T peek()
	{
		return get(size - 1);
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

		if (!(other instanceof Stack<?>))
		{
			return false;
		}

		if (size != ((Stack<?>)other).getSize())
		{
			return false;
		}

		for (int i = 0; i < size; i++)
		{
			if (!array[i].equals(((Stack<?>)other).array[i]))
			{
				return false;
			}
		}

		return true;
	}
}
