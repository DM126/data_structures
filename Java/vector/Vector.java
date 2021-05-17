/**
 * Implementation of a C++ vector, or ArrayList in java
 */
public class Vector<T> extends ArrayCollection<T>
{
	public Vector()
	{
		super();
	}

	public Vector(int initialCapacity)
	{
		super(initialCapacity);
	}

	public Vector(Vector<T> other)
	{
		super(other);
	}

	public void add(int index, T item)
	{
		super.add(index, item);
	}

	/**
	 * Adds an item to the end of the vector
	 * 
	 * @param item the item to add
	 * @return true if the item was added
	 */
	public void addBack(T item)
	{
		super.add(size, item);
	}

	/**
	 * Adds an item to the front of the vector
	 * 
	 * @param item the item to add
	 */
	public void addFront(T item)
	{
		super.add(0, item);
	}

	public T remove(int index)
	{
		return super.remove(index);
	}

	/**
	 * Removes the item at the end of the vector
	 *  
	 * @return the item at the end of the vector
	 */
	public T removeBack()
	{
		return super.remove(size - 1);
	}

	/**
	 * Removes the item at the front of the vector
	 * 
	 * @return the item at the front of the vector
	 */
	public T removeFront()
	{
		return super.remove(0);
	}

	public T get(int index)
	{
		return super.get(index);
	}

	/**
	 * @return the item at the end of the vector
	 */
	public T getBack()
	{
		return super.get(size - 1);
	}

	/**
	 * @return the item at the front of the vector
	 */
	public T getFront()
	{
		return super.get(0);
	}
}
