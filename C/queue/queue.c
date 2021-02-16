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
}

void delete_queue(Queue* queue)
{
	if (queue != NULL)
	{
		delete_node(queue->head);
		free(queue);
	}
}

Queue* copy_queue(Queue* other)
{

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
		queue->tail == NULL;
	}

	return value;
}

int peek(Queue* queue)
{
	if (queue == NULL)
	{
		exit_with_error("pop - queue is null");
	}
	else if (isEmpty(queue))
	{
		exit_with_error("pop - queue is empty");
	}

	return queue->head->data;
}

bool isEmpty(Queue* queue)
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

void dump(Queue* queue)
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
		int i = 0;
		do
		{
			printf("%d: %d\n", i, curr->data);
			curr = queue->head->next;
		}
		while (curr != NULL);

		printf("size: %d\n", queue->size);
	}
}
