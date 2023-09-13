#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* Functions */
short topple_and_check_stability(int grid[3][3], int row, int col);
int is_stable(int grid[3][3]);
static void print_grid(int grid[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);


#endif /* SANDPILES_H */
