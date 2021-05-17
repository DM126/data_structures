#include <cassert>

#include "queue.hpp"

//Test deep copy for copy constructor and assignment operator.
//Queues should be initialized by enqueueing 0 through 4 onto them.
bool deepCopyTest(Queue<int>& queue, Queue<int>& copyqueue);

int main()
{
	Queue<int> queue;

	//test constructor
	assert(queue.isEmpty());

	//add to the queue
	for (int i = 0; i < 10; i++)
	{
		queue.enqueue(i);
		assert(queue.peek() == 0);
		assert(queue.getSize() == i+1);
	}
	assert(!queue.isEmpty());

	//test clear
	queue.clear();
	assert(queue.isEmpty());
	queue.enqueue(10);
	assert(!queue.isEmpty());
	assert(queue.peek() == 10);

	//test dequeue, and enqueueing after dequeueing
	queue.dequeue();
	assert(queue.isEmpty());
	queue.enqueue(100);
	queue.enqueue(200);
	queue.dequeue();
	assert(!queue.isEmpty());
	assert(queue.peek() == 200);
	queue.dequeue();
	
	//Test that items are in correct order
	for(int i = 0; i < 5; i++)
	{
		queue.enqueue(i);
	}
	for(int i = 0; i < 5; i++)
	{
		assert(queue.dequeue() == i);
	}

	//Test copy and assignment
	for(int i = 0; i < 5; i++)
	{
		queue.enqueue(i);
	}
	Queue<int> copyqueue = queue; //copy constructor
	assert(deepCopyTest(queue, copyqueue));

	queue.clear();
	for(int i = 0; i < 5; i++)
	{
		queue.enqueue(i);
	}
	Queue<int> assignqueue;
	assignqueue = queue; //assignment operator
	deepCopyTest(queue, assignqueue);

	//Test deletion after copy (should not throw exception)
	Queue<int>* queue2 = new Queue<int>(queue);
	delete queue2;
	queue.enqueue(10);
	queue.dequeue();

	std::cout << "All tests ran successfully!" << std::endl;
	return 0;
}

bool deepCopyTest(Queue<int>& queue, Queue<int>& copyqueue)
{
	assert(queue.getSize() == copyqueue.getSize());
	assert(queue.peek() == copyqueue.peek());
	queue.dequeue();
	assert(queue.peek() != copyqueue.peek());
	assert(queue.getSize() != copyqueue.getSize());
	copyqueue.enqueue(5);
	assert(queue.getSize() == 4);
	assert(copyqueue.getSize() == 6);
	
	return true;
}
