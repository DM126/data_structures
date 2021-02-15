#include "stdbool.h"

struct Stack_struct
{
	int size;
	int capacity;
	int* array;
};
typedef struct Stack_struct Stack;


const int DEFAULT_CAPACITY = 10; //starting capacity if none specified

Stack* new_stack(void);
Stack* new_stack_with_capacity(int initial_capacity);
void destroy_stack(Stack* stack);
Stack* copy_stack(Stack* other);

bool push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
bool isEmpty(Stack* stack);
void clear(Stack* stack);
bool expand_capacity(Stack* stack, int new_capacity);
