#include "static_list.h"

#include <stdlib.h>

struct struct_static_list {
    
    void** content;
    int content_size;
    int static_list_size;
};

// contructor
static_list 
static_list_create(int size) {

    if (size <= 0) { return NULL; }

    static_list list = (static_list) malloc (sizeof ( struct struct_static_list ));

    if (list == NULL) { return NULL; }

    list->content = (void**) calloc (size, sizeof ( void* ));

    if (list->content == NULL) { free(list); return NULL; }

    list->content_size = size;
    list->static_list_size = 0;

    return list;
}

// destructor
void 
static_list_destroy(static_list* list_pointer) {

    static_list list = *list_pointer;

    if (list == NULL) { return; }

    for (int pos = 0; pos < list->static_list_size; ++pos) {
        
        free(list->content[ pos ]);
    }

    free(list->content);
    free(list);

    *list_pointer = NULL;
}
