#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "../error.h"

Queue* new_queue(void)
{
	Queue* queue = malloc(sizeof(Queue));
	if (queue == NULL)
	{
		exit_with_error("new_queue - Out of memory");
	}

	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void delete_queue(Queue* queue)
{
	if (queue != NULL)
	{
		delete_node(queue->head);
		free(queue);
	}
}

Queue* copy_queue(const Queue* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Queue* queue = new_queue();
	Node* curr = other->head;
	while (curr != NULL)
	{
		enqueue(queue, curr->data);
		curr = curr->next;
	}

	return queue;

	//More complicated way of doing it, but potentially faster.
	//Both ways are O(n), but enqueueing may have more overhead.
	//Could also use copy_node, but requires iterating through again to set tail.
	//TODO Benchmark this:
	// Node* curr1 = new_node(other->head->data);
	// Node* curr2 = other->head;
	// queue->head = curr1;
	// queue->tail = curr1;
	// queue->size = other->size;
	// while (curr1 != NULL)
	// {
	// 	curr1->next = new_node(curr2->next);
	// 	curr1 = curr1->next;
	// 	if (curr1 != NULL)
	// 	{
	// 		queue->tail = curr1;
	// 		curr2 = curr2->next;
	// 	}
	// }
}


bool enqueue(Queue* queue, int value)
{
	if (queue == NULL)
	{
		exit_with_error("enqueue - queue is null");
	}

	Node* newnode = new_node(value);

	if (isEmpty(queue))
	{
		queue->head = newnode;
		queue->tail = newnode;
	}
	else
	{
		queue->tail->next = newnode;
		queue->tail = newnode;
	}

	queue->size++;
	return true;
}

int dequeue(Queue* queue)
{
	if (queue == NULL)
	{
		exit_with_error("dequeue - queue is null");
	}
	else if (isEmpty(queue))
	{
		exit_with_error("dequeue - queue is empty");
	}

	int value = queue->head->data;
	Node* temp = queue->head;
	queue->head = queue->head->next;
	free(temp);
	queue->size--;

	if (queue->head == NULL)
	{
		queue->tail = NULL;
	}

	return value;
}

int peek(const Queue* queue)
{
	if (queue == NULL)
	{
		exit_with_error("peek - queue is null");
	}
	else if (isEmpty(queue))
	{
		exit_with_error("peek - queue is empty");
	}

	return queue->head->data;
}

bool isEmpty(const Queue* queue)
{
	return queue == NULL || queue->size == 0;
}

void clear(Queue* queue)
{
	if (queue == NULL)
	{
		exit_with_error("clear - queue is null");
	}

	delete_node(queue->head);
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
}

void dump(const Queue* queue)
{
	if (queue == NULL)
	{
		printf("Queue is null.\n");
	}
	else if (isEmpty(queue))
	{
		printf("Queue is empty.\n");
	}
	else
	{
		Node* curr = queue->head;
		for (int i = 0; curr != NULL; i++, curr = curr->next)
		{
			printf("%d: %d\n", i, curr->data);
		}

		printf("size: %d\n", queue->size);
	}
}
