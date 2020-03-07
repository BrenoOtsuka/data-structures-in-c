#ifndef STATIC_LIST
#define STATIC_LIST

struct static_list_st;

typedef int position;
typedef struct  static_list_st* static_list_t;

// just for unit test
static_list_t
static_list_init(int content_size, int length, const int itens[]);

static_list_t
static_list_sequence(int content_size, int length);

int
static_list_compare(static_list_t list, static_list_t other);

void
static_list_println(static_list_t list);

// contructor
static_list_t 
static_list_create(int size);

// destructor
void 
static_list_destroy(static_list_t* list_pointer);

// auxiliary functions
int
static_list_isempty(static_list_t list);

int
static_list_isfull(static_list_t list);

int
static_list_length(static_list_t list);

// list operations
int
static_list_insert(static_list_t list, position pos, void* item);

int
static_list_contains(static_list_t list, void* item, position* pos);

static_list_t
static_list_retrieve(static_list_t list, position pos);

int
static_list_delete(static_list_t list, position pos);

#endif
