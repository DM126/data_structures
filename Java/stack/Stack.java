import java.util.*;

/**
 * Array implementation of a stack
 */
public class Stack<T>
{
	private T[] array;
	private int size;

	//Default starting capacity if none specified
	private static final int DEFAULT_CAPACITY = 10;

	/**
	 * Creates a new stack with the default starting capacity
	 */
	public Stack()
	{
		this(DEFAULT_CAPACITY);
	}

	/**
	 * Creates a new stack with an initial starting capacity
	 * @param initialCapacity the starting capacity of the array
	 * @throws IllegalArgumentException if the capacity is not greater than 0
	 */
	@SuppressWarnings("unchecked")
	public Stack(int initialCapacity)
	{
		if (initialCapacity <= 0)
		{
			throw new IllegalArgumentException("Capacity must be greater than 0: " + initialCapacity);
		}

		array = (T[]) new Object[initialCapacity];
		size = 0;
	}

	/**
	 * Copy constructor
	 * @param other the stack to copy
	 */
	@SuppressWarnings("unchecked")
	public Stack(Stack<T> other)
	{
		array = (T[]) new Object[other.array.length];
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}

	/**
	 * Adds an item to the stack.
	 * Expands capacity if full.
	 * @param item the item to add to the stack
	 */
	public void push(T item)
	{
		if (isFull())
		{
			expandCapacity(array.length * 2);
		}

		array[size] = item;
		size++;
	}

	/**
	 * Returns and removes the item on top of the stack
	 * 
	 * @return the item on top of the stack
	 * @throws EmptyStackException if the stack is empty
	 */
	public T pop()
	{
		if (isEmpty())
		{
			throw new EmptyStackException();
		}

		T item = array[size-1];
		size--;
		return item;
	}

	/**
	 * @return the item on top of the stack without removing it
	 * @throws EmptyStackException if the stack is empty
	 */
	public T peek()
	{
		if (isEmpty())
		{
			throw new EmptyStackException();
		}

		return array[size-1];
	}

	/**
	 * @return true if there are no items in the stack
	 */
	public boolean isEmpty()
	{
		return size == 0;
	}

	/**
	 * @return true if the array is at capacity
	 */
	public boolean isFull()
	{
		return size == getCapacity();
	}

	/**
	 * @return the number of items in the stack
	 */
	public int getSize()
	{
		return size;
	}

	/**
	 * @return the length of the underlying array
	 */
	private int getCapacity()
	{
		return array.length;
	}

	/**
	 * Removes all items from the stack
	 */
	public void clear()
	{
		size = 0;
	}

	/**
	 * Expands the capacity of the underlying array
	 * @param newCapacity the new length of the array
	 */
	@SuppressWarnings("unchecked")
	public void expandCapacity(int newCapacity)
	{
		//TODO what if new capacity < old?
		if (newCapacity <= getCapacity())
		{
			return;
		}

		T[] newArray = (T[]) new Object[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}
		array = newArray;
	}

	@Override
	public String toString()
	{
		String stackString = new String("[");

		for (int i = 0; i < size-1; i++)
		{
			stackString += array[i] + ", ";
		}

		if (!isEmpty())
		{
			stackString += array[size-1];
		}

		stackString += "]";

		return stackString;
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
			if (array[i] != ((Stack<?>)other).array[i])
			{
				return false;
			}
		}

		return true;
	}
}
