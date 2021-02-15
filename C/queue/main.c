
#include "queue.h"

int main()
{
	Queue* queue = new_queue();

	delete_queue(queue);

	return 0;
}
