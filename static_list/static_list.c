#include "static_list.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct struct_static_list {
    
    void** content;
    int content_size;
    int static_list_size;
};

static_list
static_list_init_sequential_list(int content_size, int sequence_length) {

    if ( sequence_length < 0 || content_size <= 0 ) { return NULL; }
    if ( sequence_length > content_size           ) { return NULL; }

    static_list list = (static_list) malloc (sizeof ( struct struct_static_list ));

    if (list == NULL) { return NULL; }

    list->content = (void**) calloc (content_size, sizeof ( void* ));

    if (list->content == NULL) { free(list); return NULL; }

    for (int index = 0; index < sequence_length; ++index) {

        list->content[ index ] = malloc( sizeof(int) );
        *( (int *) list->content[ index ] ) = index + 1;
    }

    list->content_size = content_size;
    list->static_list_size = sequence_length;

    return list;
}

int
static_list_compare(static_list list, static_list other) {

    if ( list == NULL || other == NULL                     ) { return 0; }
    if ( list->static_list_size != other->static_list_size ) { return 0; }

    for ( int index = 0; index < list->static_list_size; ++index) {

        void* list_item      = list->content[ index ];
        void* other_item     = other->content[ index ];
        size_t numberofbytes = sizeof(list->content[ index ]);

        if ( memcmp(list_item, other_item, numberofbytes) ) { return 0; }
    }
    return 1;
}

void
static_list_println(static_list list) {

    if ( list == NULL ) { return; }

    for ( int index = 0; index < list->content_size; ++index) {

        void* item = list->content[ index ];

        if ( item ) { printf("%d ", *( (int*) item )); }
        else        { printf("nil ");                  }
    }
    putchar('\n');
    printf("content_size: %d\n", list->content_size);
    printf("list_length:  %d\n", list->static_list_size);
}

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

    for ( int index = 0; index < list->static_list_size; ++index ) {

        free( list->content[ index ] );
    }

    free(list->content);
    free(list);

    *list_pointer = NULL;
}

// auxiliary functions
int
static_list_isempty(static_list list) { return list->static_list_size == 0; }

int
static_list_isfull(static_list list) { return list->static_list_size == list->content_size; }

int
static_list_length(static_list list) { return list->static_list_size; }
