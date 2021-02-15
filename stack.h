//A stack of ints

#include "stdbool.h"

struct Stack_struct
{
	int size;
	int capacity;
	int* array;
};
typedef struct Stack_struct Stack;


const int DEFAULT_CAPACITY = 10; //starting capacity if none specified

//Create a new stack with either the default capacity or a specified one.
//Will never return NULL, Exits if malloc fails.
Stack* new_stack(void);
Stack* new_stack_with_capacity(int initial_capacity);

//Frees the stack and its array
void delete_stack(Stack* stack);

//Returns a deep copy of the stack
Stack* copy_stack(Stack* other);


bool push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
bool isEmpty(Stack* stack);
void clear(Stack* stack);
bool expand_capacity(Stack* stack, int new_capacity);
