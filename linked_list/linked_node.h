#ifndef LINKED_NODE_H
#define LINKED_NODE_H

typedef struct linked_node_st* linked_node_t;

linked_node_t
linked_node_create(void* data);

void
linked_node_destroy(linked_node_t* node_ptr);

void*
linked_node_data(linked_node_t node);

linked_node_t
linked_node_next(linked_node_t node);

void
linked_node_link(linked_node_t node, linked_node_t next);

int
linked_node_compare(linked_node_t node, linked_node_t other, long int bytes);

#endif
