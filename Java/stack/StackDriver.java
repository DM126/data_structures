public class StackDriver
{
	public static void main(String[] args)
	{
		Stack<Integer> stack = new Stack<Integer>();

		//test constructor
		assert stack.isEmpty();
		assert !stack.isFull();

		//fill the stack
		for (int i = 0; i < 10; i++)
		{
			stack.push(i);
			assert stack.peek() == i;
			assert stack.getSize() == i+1;
		}
		assert stack.isFull();
		assert !stack.isEmpty();

		//add one more to expand capacity
		stack.push(stack.getSize());
		assert !stack.isFull();
		assert !stack.isEmpty();
		assert stack.getSize() == 11;
		//fill to new capacity
		for (int i = 11; i < 20; i++)
		{
			stack.push(i);
		}
		assert stack.isFull();

		//test clear
		stack.clear();
		assert stack.isEmpty();
		stack.push(10);
		assert !stack.isEmpty();
		assert stack.peek() == 10;

		//test pop, and pushing after popping
		stack.pop();
		assert stack.isEmpty();
		stack.push(100);
		stack.push(200);
		stack.pop();
		assert !stack.isEmpty();
		assert stack.peek() == 100;
		stack.pop();
		
		//Test that items are in correct order
		for(int i = 0; i < 5; i++)
		{
			stack.push(i);
		}
		for(int i = 4; i >= 0; i--)
		{
			assert stack.pop() == i;
		}

		//Test copy
		for(int i = 0; i < 5; i++)
		{
			stack.push(i);
		}
		Stack<Integer> copystack = new Stack<Integer>(stack);
		assert stack.getSize() == copystack.getSize();
		assert stack.peek() == copystack.peek();
		stack.pop();
		assert stack.peek() != copystack.peek();
		assert stack.getSize() != copystack.getSize();
		copystack.push(5);
		assert stack.peek() != 5;
		assert copystack.peek() == 5;

		System.out.println("All tests ran successfully!");
	}
}
