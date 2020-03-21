#include "doubly_linked_node.h"

#include <stdlib.h>
#include <string.h>

struct doubly_linked_node_st {

    void* data;

    doubly_linked_node_t prev;
    doubly_linked_node_t next;
};

doubly_linked_node_t
doubly_linked_node_create(void* data) {

    size_t bytes = sizeof(struct doubly_linked_node_st);

    doubly_linked_node_t node = (doubly_linked_node_t) malloc (bytes);
    
    if (node == NULL) { return NULL; }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void
doubly_linked_node_destroy(doubly_linked_node_t* node_ptr) {

    if (node_ptr == NULL) { return; }

    doubly_linked_node_t node = *node_ptr;

    if (node == NULL) { return; }

    free(node->data);
    free(node);

    *node_ptr = NULL;
}

void*
doubly_linked_node_data (doubly_linked_node_t node) { return node->data; }

doubly_linked_node_t
doubly_linked_node_previous (doubly_linked_node_t node) { return node->prev; }

doubly_linked_node_t
doubly_linked_node_next (doubly_linked_node_t node) { return node->next; }

void
doubly_linked_node_link (node, next)
    doubly_linked_node_t node;
    doubly_linked_node_t next;
{
    next->prev = node;
    node->next = next;
}

int
doubly_linked_node_compare (node, other, bytes)
    doubly_linked_node_t node;
    doubly_linked_node_t other;
    long int bytes;
{
    if (node == NULL && other == NULL ) { return 0; }
    if (node == NULL || other == NULL ) { return 1; }

    void* node_data  = node->data;
    void* other_data = other->data;

    return memcmp(node_data, other_data, bytes);
}
