//A doubly linked list implementation of deque of strings

#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include "node.h"

struct Deque_struct
{
	int size; //number of items in the queue
	Node* head;
	Node* tail;
};
typedef struct Deque_struct Deque;

//Create a new queue
//Will never return NULL, Exits if malloc fails.
Deque* new_deque(void);

//Frees the queue and its array
void delete_deque(Deque* deque);

//Returns a deep copy of the queue
Deque* copy_deque(const Deque* other);


//Adds a string to the front of the queue.
//Returns true if the value was successfully added, false otherwise.
bool push_front(Deque* deque, char* str);

//Adds a string to the end of the queue.
//Returns true if the value was successfully added, false otherwise.
bool push_back(Deque* deque, char* str);

//Removes and returns the string at the front of the queue
//Exits the program if the queue is null or empty.
char* pop_front(Deque* deque);

//Removes and returns the string at the end of the queue
//Exits the program if the queue is null or empty.
char* pop_back(Deque* deque);

//Returns the value at the front of the queue without removing it.
//Exits program if queue is null or empty.
char* peek_front(const Deque* deque);

//Returns the value at the end of the queue without removing it.
//Exits program if queue is null or empty.
char* peek_back(const Deque* deque);

//Returns true if the queue is null or has no items TODO NULL?
bool is_empty(const Deque* deque);

//Removes all items from the queue.
//Exits the program if the queue is null.
void clear(Deque* deque);

//Print the queue's info, used for debugging
void dump(const Deque* deque);

#endif
