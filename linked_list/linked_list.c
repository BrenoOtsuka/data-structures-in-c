#include "linked_list.h"
#include "linked_node.h"

#include <stdlib.h>
#include <stdio.h>

struct linked_list_st {

    linked_node_t head;
    long int length;
};

linked_list_t 
linked_list_create(void) {

    linked_list_t list = (linked_list_t) malloc( sizeof(struct linked_list_st) );

    if (list == NULL) { return NULL; }

    list->head = NULL;
    list->length = 0;

    return list;
}

void
linked_list_destroy(linked_list_t* list_ptr) {

    if (list_ptr == NULL) { return; }

    linked_list_t list = *list_ptr;

    while(!linked_list_isempty(list)) {

        linked_list_delete(list, 0);
    }
    free(list);

    *list_ptr = NULL;
}

int
linked_list_isempty(linked_list_t list) { return list->length == 0; }

long int
linked_list_length(linked_list_t list) { return list->length; }

linked_node_t
linked_list_locate(linked_list_t list, position_t pos) {

    if ( list == NULL                  ) { return NULL; }
    if ( pos < 0 || pos > list->length ) { return NULL; }

    linked_node_t node = list->head;

    for (int i = 0; i < pos; ++i) {

        node = linked_node_next(node);
    }
    return node;
}

int
linked_list_add(linked_list_t list, position_t pos, void* data) {

    if ( list == NULL                  ) { return 0; }
    if ( pos < 0 || pos > list->length ) { return 0; }

    linked_node_t node = linked_node_create(data);

    if (node == NULL) { return 0; }

    if (pos == 0) {

        linked_node_link(node, list->head);
        list->head = node;
    } else {

        linked_node_t previous = linked_list_locate(list, pos-1);
        linked_node_link(node, linked_node_next(previous));
        linked_node_link(previous, node);
    }
    list->length++;
    return 1;
}

void*
linked_list_retrive(linked_list_t list, position_t pos) {

    if ( list == NULL                   ) { return NULL; }
    if ( pos < 0 || pos >= list->length ) { return NULL; }

    return linked_node_data(linked_list_locate(list, pos));
}

int
linked_list_delete(linked_list_t list, position_t pos) {

    if ( list == NULL                   ) { return 0; }
    if ( pos < 0 || pos >= list->length ) { return 0; }

    linked_node_t node;

    if (pos == 0) {

        node = list->head;
        list->head = linked_node_next(node);
    } else {

        linked_node_t previous = linked_list_locate(list, pos-1);
        node = linked_node_next(previous);
        linked_node_link(previous, linked_node_next(node));
    }
    linked_node_destroy(&node);
    list->length--;
    return 1;
}

int
linked_list_compare(linked_list_t list, linked_list_t other, long int byte) {

    if (list == NULL && other == NULL ) { return 0; }
    if (list == NULL || other == NULL ) { return 1; }
    if (list->length != other->length ) { return 1; }

    linked_node_t node1 = list->head;
    linked_node_t node2 = other->head;

    while (node1 != NULL) {

        if(linked_node_compare(node1, node2, byte) != 0) { return 1; }

        node1 = linked_node_next(node1);
        node2 = linked_node_next(node2);
    }
    return 0;
}
