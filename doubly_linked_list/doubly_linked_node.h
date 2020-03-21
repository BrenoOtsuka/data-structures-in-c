#ifndef DOUBLY_LINKED_NODE_H
#define DOUBLY_LINKED_NODE_H

typedef struct doubly_linked_node_st* doubly_linked_node_t;

doubly_linked_node_t
doubly_linked_node_create(void* data);

void
doubly_linked_node_destroy(doubly_linked_node_t* node_ptr);

void*
doubly_linked_node_data(doubly_linked_node_t node);

doubly_linked_node_t
doubly_linked_node_previous(doubly_linked_node_t node);

doubly_linked_node_t
doubly_linked_node_next(doubly_linked_node_t node);

void
doubly_linked_node_link(doubly_linked_node_t node, doubly_linked_node_t next);

int
doubly_linked_node_compare (doubly_linked_node_t node, doubly_linked_node_t other, long int bytes);

#endif
