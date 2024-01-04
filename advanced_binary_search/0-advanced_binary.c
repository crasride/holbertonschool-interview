#include "search_algos.h"

/**
* advanced_binary_recursive - Recursive binary search algorithm with print
* @a: Array being searched
* @target: Target value to find
* @left: Left boundary index of the subarray
* @right: Right boundary index of the subarray
*
* Return: Index where target is located or -1 if target not found
*/
int advanced_binary_recursive(int *a, int target, int left, int right)
{
	int i;

	/* If the left boundary equals the right boundary */
	if (left == right)
	{
		/* Check if the value at the left index is the target */
		if (a[left] != target)
		{
			/* Print the last element in the search and return -1 */
			printf("Searching in array: %d\n", a[left]);
			return (-1);
		}
		/* Return the index where the target is found */
		return (left);
	}

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (i = left; i <= right; ++i)
		printf("%d%s", a[i], i < right ? ", " : "");
	printf("\n");

	/* Calculate the middle index of the subarray */
	i = (left + right) / 2;

	/* Adjust the boundaries based on the comparison with the target */
	if (a[i] < target)
		left = i + 1;
	else
		right = i;

	/* Recursive call with updated boundaries */
	return (advanced_binary_recursive(a, target, left, right));
}

/**
* advanced_binary - Find leftmost value in array using binary search
* @array: Pointer to the array to search
* @size: Size of the array
* @value: Value to search for
*
* Return: Index where value is located or -1 if array is NULL, size is 0,
* or value not found
*/
int advanced_binary(int *array, size_t size, int value)
{
	/* Check for NULL array or size 0 */
	if (!array || !size)
		return (-1);

	/* Initial call to the recursive binary search function */
	return (advanced_binary_recursive(array, value, 0, size - 1));
}

