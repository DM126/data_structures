public class VectorDriver 
{
	public static void main(String[] args)
	{
		Vector<Integer> vec = new Vector<Integer>();

		//test constructors
		assert vec.isEmpty();
		assert !vec.isFull();

		//fill the vector
		for (int i = 0; !vec.isFull(); i++)
		{
			vec.addBack(i);
			assert vec.get(i) == i;
			assert vec.getSize() == i+1;
		}
		assert vec.getSize() == 10;
		assert vec.getFront() == vec.get(0);
		assert vec.getBack() == vec.get(vec.getSize()-1);
		assert vec.isFull();
		assert !vec.isEmpty();

		//add one more to expand capacity
		vec.addBack(vec.getSize());
		assert !vec.isFull();
		assert !vec.isEmpty();
		assert vec.getSize() == 11;
		for (int i = 0; i < vec.getSize(); i++)
		{
			assert vec.get(i) == i;
		}

		//test clear
		vec.clear();
		assert vec.isEmpty();
		vec.addBack(10);
		assert !vec.isEmpty();
		//test get and add functions
		assert vec.get(0) == 10;
		assert vec.getFront() == 10;
		assert vec.getBack() == 10;
		vec.addBack(20);
		assert vec.getFront() == 10;
		assert vec.getBack() == 20;
		vec.addFront(30);
		assert vec.getFront() == 30;
		assert vec.get(1) == 10;
		assert vec.getBack() == 20;

		//test remove functions
		vec.clear();
		for (int i = 0; i < 10; i++)
		{
			vec.addBack(i);
		}
		assert vec.remove(3) == 3;
		assert vec.removeFront() == 0;
		assert vec.removeBack() == 9;
		vec.clear();

		//test copy
		for(int i = 0; i < 5; i++)
		{
			vec.addBack(i);
		}
		Vector<Integer> copyvec = new Vector<Integer>(vec);
		assert(vec.getSize() == copyvec.getSize());
		for (int i = 0; i < vec.getSize(); i++)
		{
			assert(vec.get(i).equals(copyvec.get(i)));
		}
		vec.removeBack();
		assert(!vec.getBack().equals(copyvec.getBack()));
		assert(vec.getSize() != copyvec.getSize());
		copyvec.addFront(5);
		assert(vec.getFront() != 5);
		assert(copyvec.getFront() == 5);

		System.out.println("All tests ran successfully!");
	}
}
