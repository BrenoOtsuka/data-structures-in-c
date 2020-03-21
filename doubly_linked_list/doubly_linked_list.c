#include "doubly_linked_list.h"
#include "doubly_linked_node.h"

#include <stdlib.h>

struct doubly_linked_list_st {

    doubly_linked_node_t sentinel;
    long int length;
};

doubly_linked_list_t 
doubly_linked_list_create(void) {

    size_t bytes = sizeof(struct doubly_linked_list_st);

    doubly_linked_list_t list = (doubly_linked_list_t) malloc( bytes );

    if (list == NULL) { return NULL; }

    doubly_linked_node_t sentinel = doubly_linked_node_create(NULL);

    if (sentinel == NULL) { free(list); return NULL; }

    doubly_linked_node_link(sentinel, sentinel);

    list->sentinel = sentinel;
    list->length = 0;

    return list;
}

void
doubly_linked_list_destroy(doubly_linked_list_t* list_ptr) {

    if (list_ptr == NULL) { return; }

    doubly_linked_list_t list = *list_ptr;

    if (list == NULL) { return; }

    while(!doubly_linked_list_isempty(list)) {

        doubly_linked_list_delete(list, 0);
    }
    free(list);

    *list_ptr = NULL;
}

doubly_linked_node_t
doubly_linked_list_first(doubly_linked_list_t list) {

    return doubly_linked_node_next(list->sentinel);
}

doubly_linked_node_t
doubly_linked_list_last(doubly_linked_list_t list) {

    return doubly_linked_node_previous(list->sentinel);
}

int
doubly_linked_list_isempty(doubly_linked_list_t list) { return list->length == 0; }

long int
doubly_linked_list_length (doubly_linked_list_t list) { return list->length; }

doubly_linked_node_t
doubly_linked_list_locate(doubly_linked_list_t list, position_t pos) {

    if ( pos < 0 || pos >= list->length ) { return list->sentinel; }

    doubly_linked_node_t node = doubly_linked_list_first(list);
    
    for (int i = 0; i < pos; ++i) {

        node = doubly_linked_node_next(node);
    }
    return node;
}

int
doubly_linked_list_add(list, pos, data)
    doubly_linked_list_t list;
    position_t pos;
    void* data;
{

    if ( list == NULL                  ) { return 0; }
    if ( pos < 0 || pos > list->length ) { return 0; }
    
    doubly_linked_node_t node = doubly_linked_node_create(data);
    
    if (node == NULL) { return 0; }

    doubly_linked_node_t next = doubly_linked_list_locate(list, pos);
    doubly_linked_node_t prev = doubly_linked_node_previous(next);

    doubly_linked_node_link(prev, node);
    doubly_linked_node_link(node, next);

    list->length++;

    return 1;
}

void*
doubly_linked_list_retrive(doubly_linked_list_t list, position_t pos) {

    if ( list == NULL                   ) { return NULL; }
    if ( pos < 0 || pos >= list->length ) { return NULL; }

    doubly_linked_node_t node = doubly_linked_list_locate(list, pos);

    return doubly_linked_node_data(node);
}

int
doubly_linked_list_delete(doubly_linked_list_t list, position_t pos) {

    if ( list == NULL                   ) { return 0; }
    if ( pos < 0 || pos >= list->length ) { return 0; }

    doubly_linked_node_t node = doubly_linked_list_locate(list, pos);
    doubly_linked_node_t prev = doubly_linked_node_previous(node);
    doubly_linked_node_t next = doubly_linked_node_next(node);

    doubly_linked_node_link(prev, next);
    doubly_linked_node_destroy(&node);

    list->length--;

    return 1;
}

int
doubly_linked_list_compare(list, other, byte)
    doubly_linked_list_t list;
    doubly_linked_list_t other;
    long int byte;
{
    if (list == NULL && other == NULL ) { return 0; }
    if (list == NULL || other == NULL ) { return 1; }
    if (list->length != other->length ) { return 1; }

    doubly_linked_node_t node1 = doubly_linked_list_first(list);
    doubly_linked_node_t node2 = doubly_linked_list_first(other);

    while (node1 != list->sentinel) {

        if(doubly_linked_node_compare(node1, node2, byte) != 0) { return 1; }

        node1 = doubly_linked_node_next(node1);
        node2 = doubly_linked_node_next(node2);
    }
    return 0;
}
