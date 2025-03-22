
public class DequeDriver
{
	public static void main(String[] args)
	{
		Deque<Integer> list = new Deque<>();

		//test constructor
		assert list.isEmpty();

		//add to the list
		for (int i = 0; i < 5; i++)
		{
			list.pushBack(i);
			assert list.peekFront() == 0;
			assert list.peekBack() == i;
			assert list.getSize() == i+1;
		}
		assert !list.isEmpty();
		for (int i = 5; i < 10; i++)
		{
			list.pushFront(i);
			assert list.peekFront() == i;
			assert list.peekBack() == 4;
			assert list.getSize() == i+1;
		}
		
		//test clear
		list.clear();
		assert list.isEmpty();
		for (int i = 0; i < 5; i++)
		{
			list.pushFront(i);
			assert list.peekFront() == i;
			assert list.peekBack() == 0;
			assert list.getSize() == i+1;
		}
		list.clear();
		list.pushBack(10);
		assert !list.isEmpty();
		assert list.peekBack() == 10;

		//test add and remove after removing
		list.popFront();
		assert list.isEmpty();
		list.pushBack(100);
		list.pushFront(200);
		assert list.peekFront() == 200;
		assert list.peekBack() == 100;
		list.popFront();
		assert !list.isEmpty();
		assert list.peekFront() == 100;
		list.popFront();
		
		//Test that items are in correct order
		for(int i = 0; i < 5; i++)
		{
			list.pushBack(i);
		}
		for(int i = 0; i < 5; i++)
		{
			assert list.popFront() == i;
		}

		//Test copy
		for(int i = 0; i < 5; i++)
		{
			list.pushBack(i);
		}
		Deque<Integer> copylist = new Deque<>(list);
		assert list.equals(copylist);
		assert list.getSize() == copylist.getSize();
		assert list.peekFront().equals(copylist.peekFront());
		assert list.peekBack().equals(copylist.peekBack());
		list.popFront();
		assert !list.peekFront().equals(copylist.peekFront());
		assert list.peekBack().equals(copylist.peekBack());
		assert list.getSize() != copylist.getSize();
		copylist.pushBack(5);
		copylist.popFront();
		copylist.popFront();
		copylist.popFront();
		copylist.popFront();
		copylist.popFront();
		assert list.peekFront() != 5;
		assert copylist.peekFront() == 5;

		System.out.println("All tests ran successfully!");
	}
}
