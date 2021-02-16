//A stack of ints

#ifndef STACK_H
#define STACK_H

#include "stdbool.h"

struct Stack_struct
{
	int size; //number of items in the stack, signifies next index to push to
	int capacity; //capacity of the array
	int* array;
};
typedef struct Stack_struct Stack;


static const int DEFAULT_CAPACITY = 10; //starting capacity if none specified

//Create a new stack with either the default capacity or a specified one.
//Will never return NULL, Exits if malloc fails.
Stack* new_stack(void);
Stack* new_stack_with_capacity(int initial_capacity);

//Frees the stack and its array
void delete_stack(Stack* stack);

//Returns a deep copy of the stack
Stack* copy_stack(Stack* other);


//Adds a value to the stack.
//If the stack is at capacity it will be expanded.
//Returns true if the value was successfully added, false otherwise.
bool push(Stack* stack, int value);

//Remove an item from the stack and returns its value.
//Exits the program if stack is null or empty.
int pop(Stack* stack);

//Returns the value on top of the stack, without removing it.
//Exits program if stack is null or empty.
int peek(Stack* stack);

//Returns true if the stack is null or has no items TODO NULL?
bool isEmpty(Stack* stack);

//Returns true if the stack's size is equal to its capacity TODO NULL?
bool isFull(Stack* stack);

//Removes all items from the stack.
//Exits the program if the stack is null.
void clear(Stack* stack);

//Expands the capacity of the stack.
//Returns false if new_capacity is <= to the old capacity or if the stack is null.
//Exits program if malloc fails.
bool expand_capacity(Stack* stack, int new_capacity);

//Print the stack's info, used for debugging
void dump(Stack* stack);

#endif
