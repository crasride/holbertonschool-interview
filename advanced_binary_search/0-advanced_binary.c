#include "search_algos.h"

/**
* advanced_binary_recursive - recursive binary search algorithm with print
* @a: array being searched
* @target: target to find
* @l: left boundary index
* @r: right boundary index
*
* Return: index where target found or -1 if target not found
*/
int advanced_binary_recursive(int *a, int target, int l, int r)
{
	int i;

	if (l == r)
	{
		if (a[l] != target)
		{
			printf("Searching in array: %d\n", a[l]);
			return (-1);
		}
		return (l);
	}

	printf("Searching in array: ");
	for (i = l; i <= r; ++i)
		printf("%d%s", a[i], i < r ? ", " : "");
	printf("\n");

	i = (l + r) / 2;
	if (a[i] < target)
		l = i + 1;
	else
		r = i;

	return (advanced_binary_recursive(a, target, l, r));
}

/**
* advanced_binary - find leftmost value in array using binary search
* @array: pointer to array to search
* @size: size of array
* @value: value to search for
*
* Return: index where value is located or -1 if array is NULL, size is 0,
* or value not found
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);

	return (advanced_binary_recursive(array, value, 0, size - 1));
}
