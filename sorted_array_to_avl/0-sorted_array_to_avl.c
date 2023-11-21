#include "binary_trees.h"

/**
* add_new_node - Create AVL tree node
* @value: Value of the node
* @parent: Pointer to the parent node
*
* Return: Newly created node
*/
avl_t *add_new_node(int value, avl_t *parent)
{
	/* Allocate memory for a new AVL tree node */
	avl_t *new_node = malloc(sizeof(*new_node));

	/* Initialize node with provided value and return the newly created node */
	return (new_node ? (new_node->n = value, new_node->parent = parent,
			new_node->left = NULL, new_node->right = NULL, new_node) : NULL);
}


/**
* binary_tree_from_array - Build AVL tree from a sorted array
* @parent: Pointer to the parent node
* @array: Array of node values
* @left_idx: Left index of the array
* @right_idx: Right index of the array
*
* Return: Final created node, NULL on malloc failure
*/
avl_t *binary_tree_from_array(avl_t *parent, int *array, int left_idx,
								int right_idx)
{
	int middle_idx;
	avl_t *new_node = NULL;
	/* if left index is greater than right index, returns NULL */
	if (left_idx > right_idx)
		return (NULL);

	/* Calculate the index of the middle element */
	middle_idx = (left_idx + right_idx) / 2;
	/* Create a new node with the middle element value */
	new_node = add_new_node(array[middle_idx], parent);

	/* Check for malloc failure */
	if (!new_node)
		return (NULL);

	/* Recursively construct the left and right subtrees */
	new_node->left = binary_tree_from_array(new_node, array, left_idx,
											middle_idx - 1);
	new_node->right = binary_tree_from_array(new_node, array,
											middle_idx + 1, right_idx);

	return (new_node);
}

/**
* sorted_array_to_avl - Build AVL tree from array
* @array: Pointer to the first element of the array
* @size: Size of the array
*
* Return: Pointer to the root node of the created AVL tree, NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	/* Check if the array is empty */
	if (size == 0)
		return (NULL);

	/*
	* Pass NULL as parent for initial call
	* Start with the entire array, from index 0 to size - 1
	*/
	return (binary_tree_from_array(NULL, array, 0, size - 1));
}
