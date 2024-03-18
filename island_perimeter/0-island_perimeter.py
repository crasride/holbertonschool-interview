#!/usr/bin/python3
"""
0-island_perimeter module
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid (list[list[int]]): list of list of integers representing the grid.

    Returns:
        int: The perimeter of the island.

    """

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    # Traverse through each cell of the grid
    for i in range(rows):
        for j in range(cols):
            # If the cell represents land, add 4 to perimeter
            if grid[i][j] == 1:
                perimeter += 4
                # If the adjacent cell is also land, subtract 2 from perimeter
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
