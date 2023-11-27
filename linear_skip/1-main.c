#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "search.h"

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	skiplist_t *head, *res;
	int array[23] = {
		0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 100, 100, 100, 111, 122, 123, 145, 155, 260
	};

	head = create_skiplist(array, 23);
	res = linear_skip(head, 100);
	printf("Found at index: %lu\n", res->index);
	free_skiplist(head);
	return (0);
}
