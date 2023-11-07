#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
* detchar - Determines whether to print '#' or ' ' at a given position.
* @row: Row index.
* @col: Column index.
* @size: Size of the current Menger sponge level.
*
* Return: '#' or ' '
*/
char detchar(size_t row, size_t col, size_t size)
{
	while (size > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
		size /= 3;
	}
	return ('#');
}

/**
* menger - Draws a 2D Menger sponge.
* @level: Level of Menger sponge to draw.
*
* Does nothing if the level is lower than 0.
*/
void menger(int level)
{
	if (level < 0)
		return;

	size_t size = pow(3, level);

	for (size_t row = 0; row < size; ++row)
	{
		for (size_t col = 0; col < size; ++col)
			putchar(detchar(row, col, size));
		putchar('\n');
	}
}



