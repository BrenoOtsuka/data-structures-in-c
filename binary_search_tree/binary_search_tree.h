#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct binary_search_tree_st* binary_search_tree_t;

binary_search_tree_t
binary_search_tree_create(void);

void
binary_search_tree_destroy(binary_search_tree_t* tree_ptr);

int
binary_search_tree_add(binary_search_tree_t tree, void* data);

void*
binary_search_tree_retrieve(binary_search_tree_t tree, int key);

int
binary_search_tree_delete(binary_search_tree_t tree, int key);

void
binary_search_tree_print(binary_search_tree_t tree);

void
binary_search_tree_println(binary_search_tree_t tree);

#endif
