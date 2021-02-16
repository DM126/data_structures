#include <assert.h>
#include <stdio.h>

#include "queue.h"

int main()
{
	Queue* queue = new_queue();
	assert(isEmpty(queue));

	//test enqueue
	enqueue(queue, 0);
	assert(!isEmpty(queue));
	assert(peek(queue) == 0);
	enqueue(queue, 1);
	assert(peek(queue) == 0);
	assert(queue->size == 2);

	//add to the queue
	for (int i = 2; i < 100; i++)
	{
		enqueue(queue, i);
	}
	assert(peek(queue) == 0);
	assert(queue->size == 100);

	//test dequeue, and enqueue after dequeue
	// assert(dequeue(queue) == 0);
	// assert(peek(queue) == 1);
	// assert(queue->size == 99);
	// enqueue(queue, 100);
	// assert(dequeue(queue) == 0);
	// assert(peek(queue) == 1);
	// assert(queue->size == 100);

	// //dequeue until empty
	// for (int i = 0; i < 100; i++)
	// {
	// 	assert(dequeue(queue) == i + 1);
	// }
	// assert(isEmpty(queue));
	// enqueue(queue, 200);
	// assert(!isEmpty(queue));
	// assert(peek(queue) == 200);
	// dequeue(queue);

	// //test clear
	// for (int i = 100; i < 150; i++)
	// {
	// 	enqueue(queue, i);
	// }
	// clear(queue);
	// assert(isEmpty(queue));
	// enqueue(queue, 10);
	// assert(!isEmpty(queue));
	// assert(peek(queue) == 10);
	// assert(dequeue(queue) == 10);


	//Test copy
	// for(int i = 0; i < 5; i++)
	// {
	// 	enqueue(queue, i);
	// }
	// Queue* queue2 = copy_queue(queue);
	// assert(queue->size == queue2->size);
	// assert(queue->array != queue2->array); //make sure deep copy is done
	// dequeue(queue);
	// assert(peek(queue2) == 4);
	// assert(peek(queue) != peek(queue2));
	// assert(queue->size != queue2->size);
	// enqueue(queue2, 5);
	// assert(peek(queue) != 5);
	// assert(peek(queue) != peek(queue2));

	delete_queue(queue);
	// delete_queue(queue2);

	printf("All tests ran successfully!\n");
	return 0;
}
