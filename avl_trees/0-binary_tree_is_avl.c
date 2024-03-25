#include "binary_trees.h"

/**
* is_avl - check if a binary tree is a valid AVL tree
* @root: root of a tree
* @min: value of min node
* @max: value of max node
* @height: height of the tree
* Return: 1 if the tree is a valid AVL tree, and 0 otherwise
*/
int is_avl(const binary_tree_t *root, int min, int max, int *height)
{
	int left_height = 0, right_height = 0;

	/* Check if the current node is NULL (base case for recursion) */
	if (root == NULL)
		return (1);

	/* Check if the current node's value is within the allowed range */
	if (root->n < min || root->n > max)
		return (0);

	/* Recursively check the left and right subtrees */
	if (!is_avl(root->left, min, root->n - 1, &left_height))
		return (0);
	if (!is_avl(root->right, root->n + 1, max, &right_height))
		return (0);

	/* Calculate the height of the current subtree */
	*height = 1 + (left_height > right_height ? left_height : right_height);

	/*
	* Check if difference between the heights of the left and right subtrees
	* is at most 1
	*/
	return (abs(left_height - right_height) <= 1);
}

/**
* binary_tree_is_avl - function that checks if a
* binary tree is a valid AVL Tree
* @tree: binary tree
* Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	/* Check if the tree is NULL */
	if (!tree)
		return (0);

	/* Call the helper function to check if the tree is a valid AVL tree */
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}

