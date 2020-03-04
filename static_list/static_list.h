#ifndef STATIC_LIST
#define STATIC_LIST

struct struct_static_list;

typedef struct  struct_static_list * static_list;

typedef int position;

enum STATIC_LIST_FLAGS {
    OK,
    OUT_OF_BOUND_ERROR,
    UNKNOWN_POINTER_ERROR
};

// contructor
static_list 
static_list_create(int size);

// destructor
void 
static_list_destroy(static_list* list_pointer);

// auxiliary functions
// int
// static_list_isempty(static_list list);

// list operations
// int
// static_list_insert(static_list list, position pos, void* x);

#endif
