#include "lists.h"

/**
 * newnode - creates a new node for the linked list
 * @number: value to assign to the node
 *
 * Return: the newly created linked list node
 */

listint_t *newnode(int number)
{
	/* Allocate memory for a new node and assign its address to 'new' */
	listint_t *new = malloc(sizeof(*new));

	/* Check if memory allocation was successful */
	if (new)
	{
		/* Assign the 'number' value to the 'n' field of the new node */
		new->n = number;

		/* Initialize the 'next' field of the new node as NULL */
		new->next = NULL;
	}

	/*Return the 'new' pointer, which can be NULL if memory allocation failed */
	return (new);
}

/**
 * insert_node - inserts a node into the linked list in sorted order
 * @head: pointer to the pointer of the head node
 * @number: value to assign to the node
 *
 * Return: the newly created node, NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	/* Call the 'newnode' function to create a new node with 'number' */
	listint_t *new = newnode(number);

	/* Check if creating the new node was successful */
	if (!new)
		return (NULL);

	/**
	 * Create a double pointer 'current' and initialize it with the address
	 * of the 'head' pointer
	 */
	listint_t **current = head;

	/**
	 * Traverse 'current' through the list until finding the correct position
	 * to insert the new node
	 */
	while (*current && new->n > (*current)->n)
		current = &(*current)->next;

	/* Link the new node with the current node */
	new->next = *current;

	/* Update the current pointer to point to the new node */
	*current = new;

	/* Return the pointer to the head node, which might have been updated */
	return (*head);
}



