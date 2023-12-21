#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Functions Task 0*/
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void move_node(int *array, size_t size, size_t root, size_t total_size);

#endif /* SORT_H */
