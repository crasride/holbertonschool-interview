#include "slide_line.h"

/**
* slide_left - Slide and merge an array of integers to the left.
* @line: Pointer to an array of integers.
* @size: Number of elements in the array.
*/
void slide_left(int *line, size_t size)
{
	size_t i, j = 0;
	int merged[32];

	for (i = 0; i < size; i++)
		merged[i] = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (merged[j] == 0)
			{
				merged[j] = line[i];
			}
			else if (merged[j] == line[i])
			{
				merged[j] += line[i];
				j++;
			}
			else
			{
				j++;
				merged[j] = line[i];
			}
		}
	}

	for (i = 0; i < size; i++)
		line[i] = merged[i];
}

/**
* slide_right - Slide and merge an array of integers to the right.
* @line: Pointer to an array of integers.
* @size: Number of elements in the array.
*/
void slide_right(int *line, size_t size)
{
	size_t i, j = size - 1;
	int merged[32];

	for (i = 0; i < size; i++)
		merged[i] = 0;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0)
		{
			if (merged[j] == 0)
			{
				merged[j] = line[i];
			}
			else if (merged[j] == line[i])
			{
				merged[j] += line[i];
				j--;
			}
			else
			{
				j--;
				merged[j] = line[i];
			}
		}
	}

	for (i = 0; i < size; i++)
		line[i] = merged[i];
}

/**
* slide_line - Slide and merge an array of integers to the left or right.
* @line: Pointer to an array of integers.
* @size: Number of elements in the array.
* @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
* Return: 1 on success, 0 on failure.
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else
	{
		slide_right(line, size);
	}

	return (1);
}
