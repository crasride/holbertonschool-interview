#include "list.h"

/**
* add_node_end - Add a new node to the end of a double circular linked list
* @list: the list to modify
* @str: the string to copy into the new node
*
* Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	/* allocate memory for a new node */
	List *new_node = malloc(sizeof(List));

	/* if malloc fails, return NULL */
	if (!new_node)
		return (NULL);

	/* returns a pointer to a new string which is a duplicate of the string str*/
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* if the list is empty, the new node is the only node in the list */
	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	/* if the list is not empty, the new node is added to the end of the list */
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
* add_node_begin - Add a new node to the beginning of a double circular
* linked list
* @list: the list to modify
* @str: the string to copy into the new node
*
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	/* allocate memory for a new node */
	List *new_node = malloc(sizeof(List));

	/* if malloc fails, return NULL */
	if (!new_node)
		return (NULL);

	/* returns a pointer to a new string which is a duplicate of the string str*/
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	/* if the list is empty, the new node is the only node in the list */
	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	/*the list is not empty, the new node is added to the beginning of the list */
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}
