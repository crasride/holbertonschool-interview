#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>


/**
 * struct binary_tree_s - binary tree node
 *
 * @n: integer stored in the node
 * @parent: pointer to the parent node
 * @left: pointer to the left child node
 * @right: pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s heap_t;


/**
 * struct tree_queue - linked list
 * @node: pointer binary tree node
 * @next: pointer next queue node
 */
typedef struct tree_queue
{
	struct binary_tree_s *node;
	struct tree_queue *next;
} tree_queue;

/* Prototype Functions*/
void restore_max_heap_property(heap_t **inserted);
void delete_n_queue(tree_queue **node_queue);
tree_queue *enqueue(tree_queue **node_queue, heap_t *c_node);
heap_t *push_insert(heap_t *c_node, tree_queue **node_queue, heap_t **inserted,
					heap_t **direction, int value);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *order(heap_t **root, int value);

#endif /* BINARY_TREES_H */
