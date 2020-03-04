#ifndef STATIC_LIST
#define STATIC_LIST

struct struct_static_list;

typedef struct  struct_static_list * static_list;

typedef int position;

// contructor
static_list 
static_list_create(int size);

// destructor
void 
static_list_destroy(static_list list);

// auxiliary functions
int
static_list_isempty(static_list list);

int
static_list_isfull(static_list list);

int
static_list_length(static_list list);

position
static_list_first_position(void);

position
static_list_last_position(static_list list);

position
static_list_endof(static_list list);

// list operations
int
static_list_insert(static_list list, position pos, void* x);

int
static_list_locate(static_list list, void* x, position* pos);

void*
static_list_retrieve(static_list list, position pos);

int
static_list_delete(static_list list, position pos);

#endif
