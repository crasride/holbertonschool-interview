#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);

/* functions tasks*/
int heap_extract(heap_t **root);
heap_t *find_last_node(heap_t *root);
void heapify_down(heap_t *root);

#endif /* _BINARY_TREES_H_ */
