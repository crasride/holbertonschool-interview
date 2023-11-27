#include "search.h"

/**
* express_lane_search - Searches the express lane of the skip list.
* @node: Pointer to the current node in the skip list.
* @value: The value to search for.
*
* Return: Pointer to the first node where the value is located, or NULL if
* not found.
*/
skiplist_t *express_lane_search(skiplist_t *node, int value)
{
	skiplist_t *current_node = node, *express_node = node;

	while (express_node->express && express_node->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				express_node->express->index, express_node->express->n);

		current_node = express_node;
		express_node = express_node->express;

		if (express_node->n == value)
			return (express_node);
	}

	if (express_node->n >= value)
		printf("Value found between indexes [%lu] and [%lu]\n",
				current_node->index, express_node->index);
	else
	{
		current_node = express_node;

		while (express_node->next)
			express_node = express_node->next;

		printf("Value found between indexes [%lu] and [%lu]\n",
				current_node->index, express_node->index);
	}

	return (current_node);
}

/**
* linear_search - Performs a linear search within the identified range.
* @node: Pointer to the current node in the skip list.
* @value: The value to search for.
*
* Return: Pointer to the first node where the value is located, or NULL if not
* found.
*/
skiplist_t *linear_search(skiplist_t *node, int value)
{
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);

		if (node->n == value)
			return (node);

		if (node->n > value)
			break;

		if (node->next)
			node = node->next;
		else
			node = NULL;
	}

	return (NULL);
}

/**
* linear_skip - Searches for a value in a sorted skip list of integers.
* @list: Pointer to the head of the skip list to search in.
* @value: The value to search for.
*
* Return: Pointer to the first node where the value is located, or NULL if not
* found.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL);

	skiplist_t *express_node = express_lane_search(list, value);

	return (linear_search(express_node, value));
}
