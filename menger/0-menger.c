#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
* position_character - Determines whether to print '#' or ' ' at a given
* position.
* @row: Row index.
* @col: Column index.
* @size: Size of the current Menger sponge level.
*
* Return: '#' or ' '
*/
char position_character(size_t row, size_t col, size_t size)
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
	size_t size = pow(3, level);
	size_t row, col;

	if (level < 0)
		return;

	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			putchar(position_character(row, col, size));
		putchar('\n');
	}
}



