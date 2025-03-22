#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"

int main()
{
	char* temp1 = NULL;
	char* temp2 = NULL;

	Deque* deque = new_deque();
	assert(is_empty(deque));

	//test push_back
	push_back(deque, "0");
	assert(!is_empty(deque));
	assert(!strcmp(peek_front(deque), "0"));
	assert(!strcmp(peek_back(deque), "0"));
	push_back(deque, "1");
	assert(!strcmp(peek_front(deque), "0"));
	assert(!strcmp(peek_back(deque), "1"));
	assert(deque->size == 2);

	//test clear
	clear(deque);
	assert(is_empty(deque));
	push_back(deque, "5");
	assert(!is_empty(deque));
	assert(!strcmp(peek_front(deque), "5"));
	assert(!strcmp(temp1 = pop_front(deque), "5"));
	free(temp1);

	//test push front
	push_front(deque, "0");
	assert(!is_empty(deque));
	assert(!strcmp(peek_front(deque), "0"));
	assert(!strcmp(peek_back(deque), "0"));
	push_front(deque, "1");
	assert(!strcmp(peek_front(deque), "1"));
	assert(!strcmp(peek_back(deque), "0"));
	assert(deque->size == 2);
	clear(deque);

	//add to the deque
	push_back(deque, "0");
	push_back(deque, "1");
	push_back(deque, "2");
	assert(!strcmp(peek_back(deque), "2"));
	push_back(deque, "3");
	assert(!strcmp(peek_back(deque), "3"));
	push_back(deque, "4");
	assert(!strcmp(peek_back(deque), "4"));
	push_back(deque, "5");
	assert(!strcmp(peek_back(deque), "5"));
	push_back(deque, "6");
	assert(!strcmp(peek_front(deque), "0"));
	assert(!strcmp(peek_back(deque), "6"));
	assert(deque->size == 7);

	//test pop_front, and push_back after pop_front
	assert(!strcmp(temp1 = pop_front(deque), "0"));
	free(temp1);
	assert(!strcmp(peek_front(deque), "1"));
	assert(deque->size == 6);
	push_back(deque, "7");
	assert(deque->size == 7);
	assert(!strcmp(temp1 = pop_front(deque), "1"));
	free(temp1);
	assert(!strcmp(peek_front(deque), "2"));
	assert(deque->size == 6);

	//test pop front and pop back
	assert(!strcmp(temp1 = pop_back(deque), "7"));
	free(temp1);
	assert(!strcmp(temp1 = pop_front(deque), "2"));
	free(temp1);
	assert(!strcmp(temp1 = pop_back(deque), "6"));
	free(temp1);
	assert(!strcmp(temp1 = pop_front(deque), "3"));
	free(temp1);
	assert(!strcmp(temp1 = pop_back(deque), "5"));
	free(temp1);
	assert(!strcmp(temp1 = pop_front(deque), "4"));
	free(temp1);
	assert(is_empty(deque));
	push_back(deque, "8");
	assert(!is_empty(deque));
	assert(!strcmp(peek_front(deque), "8"));
	temp1 = pop_front(deque);
	free(temp1);

	//Test copy
	push_back(deque, "0");
	push_back(deque, "1");
	push_back(deque, "2");
	push_back(deque, "3");
	push_back(deque, "4");
	Deque* deque2 = copy_deque(deque);
	assert(deque->size == deque2->size);
	assert(deque->head != deque2->head); //make sure deep copy is done
	temp1 = pop_front(deque);
	free(temp1);
	assert(deque->size != deque2->size);
	assert(!strcmp(temp1 = pop_front(deque2), "0"));
	free(temp1);
	push_back(deque2, "5");
	for (int i = 1; i < 5; i++)
	{
		assert(!strcmp(temp1 = pop_front(deque), temp2 = pop_front(deque2)));
		free(temp1);
		free(temp2);
	}
	assert(is_empty(deque));
	assert(!strcmp(peek_front(deque2), "5"));

	delete_deque(deque);
	delete_deque(deque2);

	printf("All tests ran successfully!\n");
	return 0;
}
