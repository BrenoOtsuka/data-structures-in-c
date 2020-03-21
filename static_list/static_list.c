#include "static_list.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

struct static_list_st {
    
    void** content;
    int content_size;
    int size;
};

static_list_t
static_list_init(int content_size, int length, const int itens[]) {

    if ( length < 0 || content_size <= 0 ) { return NULL; }
    if ( length > content_size           ) { return NULL; }

    static_list_t list = (static_list_t) malloc (sizeof ( struct static_list_st ));

    if (list == NULL) { return NULL; }

    list->content = (void**) calloc (content_size, sizeof ( void* ));

    if (list->content == NULL) { free(list); return NULL; }

    for (int index = 0; index < length; ++index) {

        list->content[ index ] = malloc( sizeof(int) );
        *( (int *) list->content[ index ] ) = itens[ index ];
    }

    list->content_size = content_size;
    list->size = length;

    return list;
}

static_list_t
static_list_sequence(int content_size, int length) {

    if ( length < 0 || content_size <= 0 ) { return NULL; }
    if ( length > content_size           ) { return NULL; }

    static_list_t list = (static_list_t) malloc (sizeof ( struct static_list_st ));

    if (list == NULL) { return NULL; }

    list->content = (void**) calloc (content_size, sizeof ( void* ));

    if (list->content == NULL) { free(list); return NULL; }

    for (int index = 0; index < length; ++index) {

        list->content[ index ] = malloc( sizeof(int) );
        *( (int *) list->content[ index ] ) = index + 1;
    }

    list->content_size = content_size;
    list->size = length;

    return list;
}

int
static_list_compare(static_list_t list, static_list_t other) {

    if ( list == NULL && other == NULL ) { return 0; }
    if ( list == NULL || other == NULL ) { return 0; }
    if ( list->size != other->size     ) { return 0; }

    for ( int index = 0; index < list->size; ++index) {

        void* list_item      = list->content[ index ];
        void* other_item     = other->content[ index ];
        size_t numberofbytes = sizeof(list->content[ index ]);

        if ( memcmp(list_item, other_item, numberofbytes) ) { return 0; }
    }
    return 1;
}

void
static_list_println(static_list_t list) {

    if ( list == NULL ) { return; }

    for ( int index = 0; index < list->content_size; ++index) {

        void* item = list->content[ index ];

        if ( item ) { printf("%d ", *( (int*) item )); }
        else        { printf("nil ");                  }
    }
    putchar('\n');
    printf("content_size: %d\n", list->content_size);
    printf("length: %d\n", list->size);
}

// contructor
static_list_t
static_list_create(int size) {

    if (size <= 0) { return NULL; }

    static_list_t list = (static_list_t) malloc (sizeof ( struct static_list_st ));

    if (list == NULL) { return NULL; }

    list->content = (void**) calloc (size, sizeof ( void* ));

    if (list->content == NULL) { free(list); return NULL; }

    list->content_size = size;
    list->size = 0;

    return list;
}

// destructor
void 
static_list_destroy(static_list_t* list_pointer) {

    static_list_t list = *list_pointer;

    if (list == NULL) { return; }

    for ( int index = 0; index < list->size; ++index ) {

        free( list->content[ index ] );
    }

    free(list->content);
    free(list);

    *list_pointer = NULL;
}

// auxiliary functions
int
static_list_isempty(static_list_t list) { return list->size == 0; }

int
static_list_isfull(static_list_t list) { return list->size == list->content_size; }

int
static_list_length(static_list_t list) { return list->size; }

// list operations
int
static_list_insert(static_list_t list, position pos, void* item) {

    if ( list == NULL                ) { return 0; }
    if ( pos < 0 || pos > list->size ) { return 0; }

    void** destination = &(list->content[ pos+1 ]);
    void** source      = &(list->content[ pos   ]);
    int numberofbytes  =  (list->size - pos) * sizeof( void* );
 
    memmove(destination, source, numberofbytes);

    list->content[ pos ] = item;
    list->size++;

    return 1;
}

int
static_list_contains(static_list_t list, void* item, position* pos) {

    size_t numberofbytes = sizeof( item );

    for (int index = 0; index < list->size; ++index) {

        void* list_item = list->content[ index ];

        if ( memcmp( list_item, item, numberofbytes ) == 0) { *pos = index; return 1; }
    }
    return 0;
}

static_list_t
static_list_retrieve(static_list_t list, position pos) {

    if ( pos < 0 || pos >= list->size ) { return NULL; }

    return list->content[ pos ];
}

int
static_list_delete(static_list_t list, position pos) {

    if ( pos < 0 || pos >= list->size ) { return 0; }
    
    free(list->content[ pos ]);

    void** destination = &(list->content[ pos   ]);
    void** source      = &(list->content[ pos+1 ]);
    int numberofbytes  =  (list->size - (pos + 1)) * sizeof( void* );
 
    memmove(destination, source, numberofbytes);

    list->size--;

    return 1;
}
