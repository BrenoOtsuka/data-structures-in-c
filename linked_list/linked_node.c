#include "linked_node.h"

#include <stdlib.h>
#include <string.h>

struct linked_node_st {

    void* data;
    linked_node_t next;
};

linked_node_t
linked_node_create(void* data) {

    linked_node_t node = (linked_node_t) malloc( sizeof(struct linked_node_st) );

    if (node == NULL) { return NULL; }

    node->data = data;
    node->next = NULL;

    return node;
}

void
linked_node_destroy(linked_node_t* node_ptr) {

    if (node_ptr == NULL) { return; }

    linked_node_t node = *node_ptr;

    if (node == NULL) { return; }

    free(node->data);
    free(node);

    *node_ptr = NULL;
}

void*
linked_node_data(linked_node_t node) { return node->data; }

linked_node_t
linked_node_next(linked_node_t node) { return node->next; }

void
linked_node_link(linked_node_t node, linked_node_t next) { node->next = next; }

int
linked_node_compare(linked_node_t node, linked_node_t other, long int bytes) {

    if (node == NULL && other == NULL ) { return 0; }
    if (node == NULL || other == NULL ) { return 1; }

    void* node_data  = node->data;
    void* other_data = other->data;

    return memcmp(node_data, other_data, bytes);
}
