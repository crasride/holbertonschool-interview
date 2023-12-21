#include "sort.h"

/**
* move_node - Moves a node down the tree
* @array: Array to be sorted
* @size: Size of the array
* @root: Index of the root of the current subtree
* @total_size: Total size of the array
*/
void move_node(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int temp = array[root];

		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		move_node(array, size, largest, total_size);
	}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: Array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		move_node(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		move_node(array, i, 0, size);
	}
}
