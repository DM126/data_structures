public class QueueDriver 
{
	public static void main(String[] args)
	{
		Queue<Integer> queue = new Queue<>();

		//test constructor
		assert queue.isEmpty();

		//add to the queue
		for (int i = 0; i < 10; i++)
		{
			queue.enqueue(i);
			assert queue.peek() == 0;
			assert queue.getSize() == i+1;
		}
		assert !queue.isEmpty();

		//test clear
		queue.clear();
		assert queue.isEmpty();
		queue.enqueue(10);
		assert !queue.isEmpty();
		assert queue.peek() == 10;

		//test dequeue, and enqueueing after dequeueping
		queue.dequeue();
		assert queue.isEmpty();
		queue.enqueue(100);
		queue.enqueue(200);
		queue.dequeue();
		assert !queue.isEmpty();
		assert queue.peek() == 100;
		queue.dequeue();
		
		//Test that items are in correct order
		for(int i = 0; i < 5; i++)
		{
			queue.enqueue(i);
		}
		for(int i = 0; i < 5; i++)
		{
			assert queue.dequeue() == i;
		}

		//Test copy
		for(int i = 0; i < 5; i++)
		{
			queue.enqueue(i);
		}
		Queue<Integer> copyqueue = new Queue<>(queue);
		assert queue.equals(copyqueue);
		assert queue.getSize() == copyqueue.getSize();
		assert queue.peek().equals(copyqueue.peek());
		queue.dequeue();
		assert !queue.peek().equals(copyqueue.peek());
		assert queue.getSize() != copyqueue.getSize();
		copyqueue.enqueue(5);
		copyqueue.dequeue();
		assert queue.peek() != 5;
		assert copyqueue.peek() == 5;

		System.out.println("All tests ran successfully!");
	}
}
