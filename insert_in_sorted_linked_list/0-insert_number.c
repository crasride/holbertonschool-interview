#include "lists.h"

/**
 * newnode - creates a new node for the linked list
 * @number: value to assign to the node
 *
 * Return: the newly created linked list node
 */
listint_t *newnode(int number)
{
	listint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	/* Assign the value to the 'n' field of the new node */
	new_node->n = number;

	/* Initialize the 'next' field as NULL */
	new_node->next = NULL;

	return (new_node);
}

/**
 * insert_node - inserts a node into the linked list in a sorted order
 * @head: pointer to the pointer of the head node
 * @number: value to assign to the node
 *
 * Return: the newly created node, NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t **current_ptr, *new_node;

	/* Initialize 'current_ptr' with the address of 'head' */
	current_ptr = head;

	/* Create a new node using 'newnode' function */
	new_node = newnode(number);

	/* Check if creating the new node was successful */
	if (!new_node)
		return (NULL);

	/* Traverse the list until finding the correct position for insertion */
	while (*current_ptr && new_node->n > (*current_ptr)->n)
		current_ptr = &(*current_ptr)->next;

	/* Insert the new node into the list */
	new_node->next = *current_ptr;
	*current_ptr = new_node;

	return (*head);
}
