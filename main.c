#include "stack.h"

int main()
{
	Stack* stack = new_stack();
	Stack* stack2 = new_stack_with_capacity(50);
	delete_stack(stack);
	delete_stack(stack2);

	return 0;
}
