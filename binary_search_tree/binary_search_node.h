#ifndef BINARY_SEARCH_NODE_H
#define BINARY_SEARCH_NODE_H

typedef struct binary_search_node_st* binary_search_node_t;

binary_search_node_t
binary_search_node_create(void* data);

void
binary_search_node_destroy(binary_search_node_t* node_ptr);

void*
binary_search_node_data(binary_search_node_t node);

binary_search_node_t
binary_search_node_left(binary_search_node_t node);

binary_search_node_t
binary_search_node_right(binary_search_node_t node);

binary_search_node_t
binary_search_node_parent(binary_search_node_t node);

void
binary_search_node_set_left(binary_search_node_t node, binary_search_node_t left);

void
binary_search_node_set_right(binary_search_node_t node, binary_search_node_t right);

void
binary_search_node_set_parent_null(binary_search_node_t node);

#endif
