#include "stdio.h"
#include "stdlib.h"

void exit_with_error(char* message)
{
	printf("ERROR: %s\n", message);
	exit(EXIT_FAILURE);
}
