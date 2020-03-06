#ifndef STATIC_LIST
#define STATIC_LIST

struct struct_static_list;

typedef int position;
typedef struct  struct_static_list* static_list;

// just for unit test
static_list
static_list_init_sequential_list(int content_size, int sequence_length);

int
static_list_compare(static_list list, static_list other);

void
static_list_println(static_list list);

// contructor
static_list 
static_list_create(int size);

// destructor
void 
static_list_destroy(static_list* list_pointer);

// auxiliary functions
int
static_list_isempty(static_list list);

int
static_list_isfull(static_list list);

int
static_list_length(static_list list);

#endif
