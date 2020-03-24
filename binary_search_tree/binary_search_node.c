#include "binary_search_node.h"

#include <stdlib.h>

struct binary_search_node_st {
    
    void* data;

    binary_search_node_t parent;
    binary_search_node_t left, right;
};

binary_search_node_t
binary_search_node_create(void* data) {

    size_t bytes = sizeof( struct binary_search_node_st );

    binary_search_node_t node = (binary_search_node_t) malloc ( bytes );

    if (node == NULL) { return NULL; }

    node->data = data;
    node->parent = NULL;
    node->left   = NULL;
    node->right  = NULL;

    return node;
}

void
binary_search_node_destroy(binary_search_node_t* node_ptr) {

    if (node_ptr == NULL) { return; }

    binary_search_node_t node = *node_ptr;

    if (node == NULL) { return; }

    free(node->data);
    free(node);

    *node_ptr = NULL;
}

void*
binary_search_node_data(binary_search_node_t node) { return node->data; }

binary_search_node_t
binary_search_node_left(binary_search_node_t node) { return node->left; }

binary_search_node_t
binary_search_node_right(binary_search_node_t node) { return node->right; }

binary_search_node_t
binary_search_node_parent(binary_search_node_t node) { return node->parent; }

void
binary_search_node_set_left(node, left) 
    binary_search_node_t node;
    binary_search_node_t left;
{
    if (node != NULL) { node->left = left;   }
    if (left != NULL) { left->parent = node; }
}

void
binary_search_node_set_right(node, right)
    binary_search_node_t node;
    binary_search_node_t right;
{
    if (node  != NULL) { node->right = right;  }
    if (right != NULL) { right->parent = node; }
}

void
binary_search_node_set_parent_null(binary_search_node_t node) { node->parent = NULL;  }
