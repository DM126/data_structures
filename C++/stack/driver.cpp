#include <cassert>
#include <iostream>

#include "stack.h"

//Test deep copy for copy constructor and assignment operator.
//Stacks should be initialized by pushing 0 through 4 onto them.
bool deepCopyTest(Stack<int>& stack, Stack<int>& copystack);

int main()
{
	Stack<int> stack;

	//test constructor
	assert(stack.isEmpty());
	assert(!stack.isFull());

	//fill the stack
	for (int i = 0; i < 10; i++)
	{
		stack.push(i);
		assert(stack.peek() == i);
		assert(stack.getSize() == i+1);
	}
	assert(stack.isFull());
	assert(!stack.isEmpty());

	//add one more to expand capacity
	stack.push(stack.getSize());
	assert(!stack.isFull());
	assert(!stack.isEmpty());
	assert(stack.getSize() == 11);
	//fill to new capacity
	for (int i = 11; i < 20; i++)
	{
		stack.push(i);
	}
	assert(stack.isFull());

	//test clear
	stack.clear();
	assert(stack.isEmpty());
	stack.push(10);
	assert(!stack.isEmpty());
	assert(stack.peek() == 10);

	//test pop, and pushing after popping
	stack.pop();
	assert(stack.isEmpty());
	stack.push(100);
	stack.push(200);
	stack.pop();
	assert(!stack.isEmpty());
	assert(stack.peek() == 100);
	stack.pop();
	
	//Test that items are in correct order
	for(int i = 0; i < 5; i++)
	{
		stack.push(i);
	}
	for(int i = 4; i <= 0; i--)
	{
		assert(stack.pop() == i);
	}

	//Test copy and assignment
	for(int i = 0; i < 5; i++)
	{
		stack.push(i);
	}
	Stack<int> copystack = stack; //copy constructor
	assert(deepCopyTest(stack, copystack));

	stack.clear();
	for(int i = 0; i < 5; i++)
	{
		stack.push(i);
	}
	Stack<int> assignstack;
	assignstack = stack; //assignment operator
	deepCopyTest(stack, assignstack);

	//Test deletion after copy (should not throw exception)
	Stack<int>* stack2 = new Stack<int>(stack);
	delete stack2;
	stack.push(10);
	stack.pop();

	printf("All tests ran successfully!\n");
	return 0;
}

bool deepCopyTest(Stack<int>& stack, Stack<int>& copystack)
{
	assert(stack.getSize() == copystack.getSize());
	assert(stack.peek() == copystack.peek());
	stack.pop();
	assert(stack.peek() != copystack.peek());
	assert(stack.getSize() != copystack.getSize());
	copystack.push(5);
	assert(stack.peek() != 5);
	assert(copystack.peek() == 5);
	
	return true;
}
