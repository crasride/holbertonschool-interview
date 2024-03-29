#include "sort.h"

/**
* getMax - Get the maximum value in an array
* @array: The array to be checked
* @size: Number of elements in the array
* Return: The maximum value
*/
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	/* Find the maximum value in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* countingSort - Sort an array using counting sort based on the
* significant place
* @array: The array to be sorted
* @size: Number of elements in the array
* @exp: The current exponent (1, 10, 100, ...)
*/
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Counting the frequency of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Cumulative sum to determine final positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Placing elements in the output array in the correct order */
	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
* radix_sort - Sort an array of integers in ascending order using Radix sort
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void radix_sort(int *array, size_t size)
{
	int max, exp;

	/* Check for NULL or empty array */
	if (!array || size < 2)
		return;

	/* Get the maximum value in the array */
	max = getMax(array, size);

	/* Iterate through each digit, starting with the least significant */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
	/*Call countingSort to sort the array based on the current digit*/
		countingSort(array, size, exp);
		/* Print the array after each iteration */
		print_array(array, size);
	}
}
