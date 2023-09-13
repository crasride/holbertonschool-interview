#include "sandpiles.h"

/**
 * topple_and_check_stability - Distributes excess sand and checks stability
 * @grid: The sandpile to evaluate
 * @row: Row index
 * @col: Column index
 *
 * Return: Number of unstable elements found
 */
short topple_and_check_stability(int grid[3][3], int row, int col)
{
	short unstable_count = 0;
	/* Directions: right, down, left, up */
	int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int i = 0;

	/* Reduce the sand in the current cell by 4 */
	grid[row][col] -= 4;

	for (i = 0; i < 4; ++i)
	{
		int newRow = row + directions[i][0];
		int newCol = col + directions[i][1];

		if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
		{
			++grid[newRow][newCol];
			if (grid[newRow][newCol] > 3)
				++unstable_count;
		}
	}

	return (unstable_count);
}

/**
 * is_stable - Checks if a sandpile is stable and triggers topple if needed
 * @grid: The sandpile to evaluate
 *
 * Return: 1 if stable, otherwise 0
 */
int is_stable(int grid[3][3])
{
	size_t row, col;
	int stable;
	int backup_grid[3][3];
	static int first_call = 1;

	/* Create a backup of the grid */
	for (row = 0; row < 3; ++row)
	{
		for (col = 0; col < 3; ++col)
		{
			backup_grid[row][col] = grid[row][col];
		}
	}

	stable = 1;

	/* Check each cell for stability */
	for (row = 0; row < 3; ++row)
	{
		for (col = 0; col < 3; ++col)
		{
			if (backup_grid[row][col] > 3)
			{
				stable = 0;
				/* If not the first call, try to stabilize the cell */
				if (!first_call && !topple_and_check_stability(grid, row, col))
					stable = 1;
			}
		}
	}
	first_call = 0;
	return (stable);
}

/**
 * print_grid - Prints a sandpile grid
 * @grid: The grid to print
 */
static void print_grid(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}

/**
 * add_grids - Sums two sandpiles
 * @grid1: The first sandpile
 * @grid2: The second sandpile
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	size_t row, col;

	/* Sum the corresponding elements of grid1 and grid2 */
	for (row = 0; row < 3; ++row)
	{
		for (col = 0; col < 3; ++col)
		{
			grid1[row][col] += grid2[row][col];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first sandpile
 * @grid2: The second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	/* Initial sum of grid1 and grid2 */
	add_grids(grid1, grid2);

	/* Continue adding and stabilizing until grid1 is stable */
	while (!is_stable(grid1))
	{
		puts("=");
		print_grid(grid1);
	}
}
