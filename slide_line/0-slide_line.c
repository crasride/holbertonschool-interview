#include "slide_line.h"

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

	size_t i, j;
	int merged[size];

	for (i = 0; i < size; i++)
		merged[i] = 0;

	j = 0;

	if (direction == SLIDE_LEFT)
	{
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
	}
	else
	{
		j = size - 1;
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
	}

	for (i = 0; i < size; i++)
		line[i] = merged[i];

	return (1);
}

