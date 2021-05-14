//A linked list implementation of an int queue

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "node.h"

struct Queue_struct
{
	int size; //number of items in the queue
	Node* head;
	Node* tail;
};
typedef struct Queue_struct Queue;

//Create a new queue
//Will never return NULL, Exits if malloc fails.
Queue* new_queue(void);

//Frees the queue and its array
void delete_queue(Queue* queue);

//Returns a deep copy of the queue
Queue* copy_queue(const Queue* other);


//Adds a value to the tail of the queue.
//Returns true if the value was successfully added, false otherwise.
bool enqueue(Queue* queue, int value);

//Removes and returns the value at the head of the queue
//Exits the program if the queue is null or empty.
int dequeue(Queue* queue);

//Returns the value at the head of the queue without removing it.
//Exits program if queue is null or empty.
int peek(const Queue* queue);

//Returns true if the queue is null or has no items TODO NULL?
bool isEmpty(const Queue* queue);

//Removes all items from the queue.
//Exits the program if the queue is null.
void clear(Queue* queue);

//Print the queue's info, used for debugging
void dump(const Queue* queue);

#endif
