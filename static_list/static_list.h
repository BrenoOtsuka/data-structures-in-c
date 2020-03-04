#ifndef STATIC_LIST
#define STATIC_LIST

struct struct_static_list;

typedef struct  struct_static_list * static_list;

// contructor
static_list 
static_list_create(int size);

// destructor
void 
static_list_destroy(static_list* list_pointer);

#endif
