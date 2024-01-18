#include "binary_trees.h"

/**
* heap_extract - Extracts the root node of a Max Binary Heap.
* @root: Double pointer to the root node of the heap.
*
* Return: Value stored in the root node, or 0 on failure.
*/
int heap_extract(heap_t **root)
{
	if (root == NULL || *root == NULL)
		return (0);

	/* Extract the value from the root node */
	int extracted_value = (*root)->n;
	/* Find the last level-order node in the heap */
	heap_t *last_node = find_last_node(*root);

	/* If the last node is not the root */
	if (last_node != *root)
	{
		/* Copy the value of the last node to the root */
		(*root)->n = last_node->n;
		/* Update the parent's pointer to the last node to NULL */
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;

		free(last_node);
		/* Restore the Max Heap property */
		heapify_down(*root);
	}
	else
	{
	/* If the root is also the last node, free the root and set it to NULL */
		free(*root);
		*root = NULL;
	}

	return (extracted_value);
}

/**
* find_last_node - Finds the last level-order node in the heap.
* @root: Pointer to the root node of the heap.
*
* Return: Pointer to the last level-order node.
*/
heap_t *find_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	heap_t *last_node = NULL;
	heap_t **queue = malloc(sizeof(heap_t *) * 1024);

	/* Check if memory allocation fails */
	if (queue == NULL)
		exit(EXIT_FAILURE);

	size_t front = 0, rear = 0;
	/* Enqueue the root */
	queue[rear++] = root;
	/* Breadth-first search to find the last node */
	while (front < rear)
	{
		last_node = queue[front];
	/* Enqueue left and right children if they exist */
		if (last_node->left)
			queue[rear++] = last_node->left;
		if (last_node->right)
			queue[rear++] = last_node->right;

		front++;
	}

	free(queue);

	return (last_node);
}

/**
* heapify_down - Restores the Max Heap property by moving the node down.
* @root: Pointer to the root node of the heap.
*/
void heapify_down(heap_t *root)
{
	if (root == NULL)
		return;

	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	/* Identify the largest node among the root, left, and right */
	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	/* If the largest node is not the root, swap values continue heapifying */
	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;
		/* Recursively heapify down the affected subtree */
		heapify_down(largest);
	}
}
