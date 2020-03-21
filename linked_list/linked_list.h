#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_st* linked_list_t;
typedef long int position_t;

linked_list_t 
linked_list_create(void);

void
linked_list_destroy(linked_list_t* list_ptr);

int
linked_list_isempty(linked_list_t list);

long int
linked_list_length(linked_list_t list);

int
linked_list_add(linked_list_t list, position_t pos, void* data);

void*
linked_list_retrive(linked_list_t list, position_t pos);

int
linked_list_delete(linked_list_t list, position_t pos);

int
linked_list_compare(linked_list_t list, linked_list_t other, long int byte);

#endif
