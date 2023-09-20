#include "lists.h"

/**
 * reverseList - Reverse a linked list
 * @head: Pointer to address of a list
 * Return: Pointer to first node of reversed list
 */
listint_t *reverseList(listint_t **head)
{
	listint_t *currentNode, *previousNode, *reversedList;

	/* currentNode points to the first original node */
	currentNode = *head;
	/* reversedList points to the first reversed node (is NULL initially) */
	reversedList = NULL;

	while (currentNode != NULL)
	{
		/* We keep a reference to the current node */
		previousNode = currentNode;
		/* Move to the next node in the original list */
		currentNode = currentNode->next;
		/* Current node now points to the previous node in the reversed list */
		previousNode->next = reversedList;
		/* Update the pointer to the reversed list to the current node */
		reversedList = previousNode;
	}

	/* We return a pointer to the first node of the reversed list */
	return (reversedList);
}


/**
 * is_palindrome - checks if singly linked list
 * @head: double pointer to linked list head node
 * Return: 1 if palindrome o otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle_pointer, *fast_ptr, *reversed_half, *current_ptr;

	middle_pointer = current_ptr = *head;

	if (*head)
	{
		/* Find the middle of the list using slow and fast pointers */
		for (fast_ptr = *head; fast_ptr && fast_ptr->next;
			fast_ptr = fast_ptr->next->next)
			middle_pointer = middle_pointer->next;

		/* Reverse the second half of the list */
		reversed_half = reverseList(&middle_pointer);

		/* Compare the first half with the reversed second half */
		for (current_ptr = *head; reversed_half != NULL;
			current_ptr = current_ptr->next)
		{
			if (current_ptr->n != reversed_half->n)
			{
				/* Restore original list , return 0 if it's not a palindrome */
				reverseList(&middle_pointer);
				return (0);
			}
			reversed_half = reversed_half->next;
		}

		/* Restore the original list after comparison */
		reverseList(&middle_pointer);
	}

	return (1);
}

