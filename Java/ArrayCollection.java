import java.util.*;

public abstract class ArrayCollection<T>
{
	protected T[] array;
	protected int size;

	//Default starting capacity if none specified
	protected static final int DEFAULT_CAPACITY = 10;

	/**
	 * Creates a new collection with the default starting capacity
	 */
	public ArrayCollection()
	{
		this(DEFAULT_CAPACITY);
	}

	/**
	 * Creates a new collection with an initial starting capacity
	 * 
	 * @param initialCapacity the starting capacity of the array
	 * @throws IllegalArgumentException if the capacity is not greater than 0
	 */
	@SuppressWarnings("unchecked")
	public ArrayCollection(int initialCapacity)
	{
		if (initialCapacity <= 0)
		{
			throw new IllegalArgumentException("Capacity must be greater than 0: " + initialCapacity);
		}

		array = (T[]) new Object[initialCapacity];
		size = 0;
	}

	/**
	 * Copies the collection
	 * 
	 * @param other the collection to copy
	 */
	@SuppressWarnings("unchecked")
	public ArrayCollection(ArrayCollection<T> other)
	{
		array = (T[]) new Object[other.array.length];
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}

	public boolean add(int index, T item)
	{
		if (index < 0 || index > size)
		{
			throw new IllegalArgumentException("Index is out of bounds: " + index);
		}

		//double the capacity if full
		if (isFull())
		{
			expandCapacity(getCapacity() * 2);
		}

		//push everything back
		for (int i = size; i > index; i--)
		{
			array[i] = array[i-1];
		}
		array[index] = item;
		size++;

		return true;
	}

	public T remove(int index)
	{
		if (isEmpty())
		{
			throw new NoSuchElementException("Collection is empty");
		}
		else if (index < 0 || index > size)
		{
			throw new IllegalArgumentException("Index is out of bounds: " + index);
		}

		T item = array[index];

		//move everything forward
		for (int i = index; i < size - 1; i++)
		{
			array[i] = array[i+1];
		}

		size--;

		return item;
	}

	public T get(int index)
	{
		if (index < 0 || index >= size)
		{
			throw new IllegalArgumentException("Index is out of bounds: " + index);
		}

		return array[index];
	}

	/**
	 * @return true if there are no items in the collection
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
	 * @return the number of items in the collection
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
}
