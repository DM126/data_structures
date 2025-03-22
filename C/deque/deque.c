#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"
#include "../error.h"

Deque* new_deque(void)
{
	Deque* deque = malloc(sizeof(Deque));
	if (deque == NULL)
	{
		exit_with_error("new_deque - Out of memory");
	}

	deque->size = 0;
	deque->head = NULL;
	deque->tail = NULL;

	return deque;
}

void delete_deque(Deque* deque)
{
	if (deque != NULL)
	{
		delete_node(deque->head);
		free(deque);
	}
}

Deque* copy_deque(const Deque* other)
{
	if (other == NULL)
	{
		return NULL;
	}

	Deque* deque = new_deque();

	Node* other_node = other->head;
	while(other_node != NULL)
	{
		push_back(deque, other_node->data);
		other_node = other_node->next;
	}

	return deque;
}


bool push_front(Deque* deque, char* str)
{
	if (deque == NULL)
	{
		exit_with_error("push_front - deque is null");
	}

	Node* new_head = new_node(str);

	if (is_empty(deque))
	{
		deque->head = new_head;
		deque->tail = deque->head;
	}
	else
	{
		new_head->next = deque->head;
		deque->head->previous = new_head;
		deque->head = new_head;
	}

	deque->size++;
	return true;
}

bool push_back(Deque* deque, char* str)
{
	if (deque == NULL)
	{
		exit_with_error("push_back - deque is null");
	}

	Node* new_tail = new_node(str);

	if (is_empty(deque))
	{
		deque->head = new_tail;
		deque->tail = deque->head;
	}
	else
	{
		deque->tail->next = new_tail;
		new_tail->previous = deque->tail;
		deque->tail = new_tail;
	}

	deque->size++;
	return true;
}

char* pop_front(Deque* deque)
{
	if (deque == NULL)
	{
		exit_with_error("pop_front - deque is null");
	}
	else if (is_empty(deque))
	{
		exit_with_error("pop_front - deque is empty");
	}

	Node* old_head = deque->head;
	char* str = old_head->data;
	deque->head = old_head->next;

	if (deque->head == NULL)
	{
		deque->tail = NULL;
	}
	else
	{
		deque->head->previous = NULL;
	}
	
	free(old_head); //Don't use delete_node so str isn't freed
	deque->size--;
	return str;
}

char* pop_back(Deque* deque)
{
	if (deque == NULL)
	{
		exit_with_error("pop_back - deque is null");
	}
	else if (is_empty(deque))
	{
		exit_with_error("pop_back - deque is empty");
	}
	
	Node* old_tail = deque->tail;
	char* str = old_tail->data;
	deque->tail = old_tail->previous;

	if (deque->tail == NULL)
	{
		deque->head = NULL;
	}
	else
	{
		deque->tail->next = NULL;
	}

	free(old_tail); //Don't use delete_node so str isn't freed
	deque->size--;
	return str;
}

char* peek_front(const Deque* deque)
{
	if (deque == NULL)
	{
		exit_with_error("peek_front - deque is null");
	}
	else if (is_empty(deque))
	{
		exit_with_error("peek_front - deque is empty");
	}

	return deque->head->data;
}

char* peek_back(const Deque* deque)
{
	if (deque == NULL)
	{
		exit_with_error("peek_back - deque is null");
	}
	else if (is_empty(deque))
	{
		exit_with_error("peek_back - deque is empty");
	}

	return deque->tail->data;
}

bool is_empty(const Deque* deque)
{
	return deque == NULL || deque->size == 0;
}

void clear(Deque* deque)
{
	if (deque == NULL)
	{
		exit_with_error("clear - deque is null");
	}

	delete_node(deque->head);
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
}

void dump(const Deque* deque)
{
	if (deque == NULL)
	{
		printf("Deque is null.\n");
	}
	else if (is_empty(deque))
	{
		printf("Deque is empty.\n");
	}
	else
	{
		Node* curr = deque->head;
		for (int i = 0; curr != NULL; i++)
		{
			printf("%d: %s\n", i, curr->data);
		}

		printf("size: %d\n", deque->size);
	}
}

