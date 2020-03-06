#ifndef STATIC_LIST
#define STATIC_LIST

struct struct_static_list;

typedef int position;
typedef struct  struct_static_list* static_list;

// just for unit test
static_list
static_list_init(int content_size, int length, const int itens[]);

static_list
static_list_init_sequential_list(int content_size, int sequence_length);

int
static_list_compare(static_list list, static_list other);

void
static_list_println(static_list list);

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
int
static_list_isempty(static_list list);

int
static_list_isfull(static_list list);

int
static_list_length(static_list list);

// list operations
int
static_list_insert(static_list list, position pos, void* item);

int
static_list_contains(static_list list, void* item, position* pos);

static_list
static_list_retrieve(static_list list, position pos);

int
static_list_delete(static_list list, position pos);

#endif
