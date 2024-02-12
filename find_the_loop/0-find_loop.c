#include "lists.h"

/**
* find_listint_loop - Finds the loop in a linked list
* @head: Pointer to a struct
*
* Return: Address of the node where loop starts
* NULL if there is no loop
*/
listint_t *find_listint_loop(listint_t *head)
{
	/* two advances 2 nodes per iteration */
	/* one advances 1 node per iteration*/
	listint_t *two = head, *one = head;

	/* Loop to detect the existence of a loop in the linked list */
	while (one && two && two->next)
	{
		two = two->next->next;
		one = one->next;
		/* If the pointers meet, there is a loop */
		if (one == two)
		{
			one = head;
			/* Loop to find the node where the loop begins */
			while (two != one)
			{
				two = two->next;
				one = one->next;
			}
			return (one);
		}
	}
	return (NULL);
}
