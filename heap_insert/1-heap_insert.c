#include "binary_trees.h"

/* Variable to track memory allocation errors */
static int memory_allocation_error;

/**
* restore_max_heap_property - Restores the Max Heap property by swapping values
* upwards
*
* @inserted: Pointer to the inserted node
*/
void restore_max_heap_property(heap_t **inserted)
{
	heap_t *c_node;
	int tmp;

	for (c_node = *inserted; c_node->parent; c_node = c_node->parent)
		if (c_node->n > c_node->parent->n)
		{
			tmp = c_node->parent->n;
			c_node->parent->n = c_node->n;
			c_node->n = tmp;
			*inserted = (*inserted)->parent;
		}
}

/**
* delete_n_queue - Deletes a node from the queue.
*
* @node_queue: Double pointer to the node in the queue
*/
void delete_n_queue(tree_queue **node_queue)
{
	tree_queue *tmp;

	if (*node_queue)
	{
		tmp = *node_queue;
		*node_queue = (*node_queue)->next;
		free(tmp);
	}
}

/**
* enqueue - Adds the address of 'c_node' to the queue.
*
* @node_queue: Double pointer to the node in the queue
* @c_node: Pointer to the current node
*
* Return: Pointer to the newly created queue node
*/
tree_queue *enqueue(tree_queue **node_queue, heap_t *c_node)
{
	tree_queue **c_queue, *new_node_queue = malloc(sizeof(*new_node_queue));

	if (!new_node_queue)
		return (NULL);
	new_node_queue->node = c_node;
	new_node_queue->next = NULL;

	c_queue = node_queue;
	while (*c_queue)
		c_queue = &(*c_queue)->next;
	new_node_queue->next = *c_queue;
	*c_queue = new_node_queue;
	return (new_node_queue);
}


/**
* push_insert - Adds a node to the queue and inserts it into the binary tree.
*
* @c_node: Pointer to the current node
* @node_queue: Double pointer to the current queue node
* @inserted: Double pointer to the inserted node
* @direction: Double pointer to the current direction
* @value: Value stored in the node to insert
*
* Return: Pointer to the inserted node
*/
heap_t *push_insert(heap_t *c_node, tree_queue **node_queue, heap_t **inserted,
					heap_t **direction, int value)
{
	if (*direction)
	{
		if (!enqueue(node_queue, *direction))
			memory_allocation_error = 1;
	}
	else
	{
		*direction = binary_tree_node(c_node, value);
		if (!*direction)
			memory_allocation_error = 1;
		*inserted = *direction;
	}
	return (*inserted);
}

/**
* order - Traverses the tree in level order.
*
* @root: Double pointer to the root node
* @value: Value stored in the node to insert
*
* Return: Pointer to the inserted node, or NULL on failure
*/
heap_t *order(heap_t **root, int value)
{
	tree_queue *c_queue = NULL;
	heap_t *inserted, *c_node = *root;

	if (!enqueue(&c_queue, c_node))
		return (NULL);
	inserted = NULL;
	while (c_queue)
	{
		c_node = c_queue->node;
		if (!inserted)
			push_insert(c_node, &c_queue, &inserted, &c_node->left, value);
		if (!inserted)
			push_insert(c_node, &c_queue, &inserted, &c_node->right, value);
		if (memory_allocation_error)
			return (NULL);
		delete_n_queue(&c_queue);
	}
	return (inserted);
}

/**
* heap_insert - Inserts a value into a maximum binary heap.
*
* @root: Double pointer to the root node of the heap
* @value: Value stored in the node to insert
*
* Return: Pointer to the added node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *inserted;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		inserted = *root;
	}
	else
	{
		inserted = order(root, value);
		restore_max_heap_property(&inserted);
	}
	return (inserted);
}

