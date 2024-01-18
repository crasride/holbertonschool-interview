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

	int extracted_value = (*root)->n;
	heap_t *last_node = find_last_node(*root);

	if (last_node != *root)
		(*root)->n = last_node->n;
	else
		free(last_node);

	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}

	if (last_node != *root)
		free(last_node);
	heapify_down(*root);

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

	if (queue == NULL)
		exit(EXIT_FAILURE);

	size_t front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		last_node = queue[front];

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

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{

		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;

		heapify_down(largest);
	}
}
