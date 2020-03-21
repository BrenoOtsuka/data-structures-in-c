#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_list_st* doubly_linked_list_t;
typedef long int position_t;

doubly_linked_list_t 
doubly_linked_list_create(void);

void
doubly_linked_list_destroy(doubly_linked_list_t* list_ptr);

int
doubly_linked_list_isempty(doubly_linked_list_t list);

long int
doubly_linked_list_length(doubly_linked_list_t list);

int
doubly_linked_list_add(doubly_linked_list_t list, position_t pos, void* data);

void*
doubly_linked_list_retrive(doubly_linked_list_t list, position_t pos);

int
doubly_linked_list_delete(doubly_linked_list_t list, position_t pos);

int
doubly_linked_list_compare(doubly_linked_list_t list, doubly_linked_list_t other, long int byte);

#endif
