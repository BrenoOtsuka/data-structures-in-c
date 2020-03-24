#include "binary_search_tree.h"
#include "binary_search_node.h"

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct binary_search_tree_st { binary_search_node_t root; };

int
binary_search_tree_key(void* data) {

    int key;
    memcpy(&key, data, sizeof(int));

    return key;
}

binary_search_node_t
binary_search_tree_smallest (binary_search_node_t node) {

    binary_search_node_t min = node;

    if (min != NULL) {

        while(binary_search_node_left(min) != NULL) {

            min = binary_search_node_left(min);
        }
    }
    return min;
}

binary_search_node_t
binary_search_tree_sucessor (binary_search_node_t node) {

    if (node == NULL) { return NULL; }

    return binary_search_tree_smallest( binary_search_node_right(node) );
}

binary_search_node_t
binary_search_tree_biggest (binary_search_node_t node) {

    binary_search_node_t max = node;

    if (max != NULL) {

        while(binary_search_node_right(max) != NULL) {

            max = binary_search_node_right(max);
        }
    }
    return max;
}

binary_search_node_t
binary_search_tree_predecessor (binary_search_node_t node) {

    if (node == NULL) { return NULL; }

    return binary_search_tree_biggest( binary_search_node_left(node) );
}

binary_search_tree_t
binary_search_tree_create(void) {

    size_t bytes = sizeof( struct binary_search_tree_st );

    binary_search_tree_t tree = (binary_search_tree_t) malloc ( bytes );

    if (tree == NULL) { return NULL; }

    tree->root = NULL;

    return tree;
}

void
binary_search_tree_destroy_node(binary_search_node_t node) {

    if (node != NULL) {

        binary_search_tree_destroy_node(binary_search_node_left (node));
        binary_search_tree_destroy_node(binary_search_node_right(node));
        binary_search_node_destroy(&node);
    }
}

void
binary_search_tree_destroy(binary_search_tree_t* tree_ptr) {

    if (tree_ptr == NULL) { return; }

    binary_search_tree_t tree = *tree_ptr;

    if (tree == NULL) { return; }

    binary_search_tree_destroy_node(tree->root); free(tree);

    *tree_ptr = NULL;
}

int
binary_search_tree_add(binary_search_tree_t tree, void* data) {

    int child;
    int key = binary_search_tree_key(data);

    binary_search_node_t prev = NULL;
    binary_search_node_t curr = tree->root;

    while (curr != NULL) {

        void* cdata = binary_search_node_data(curr);
        int   ckey  = binary_search_tree_key(cdata);

        prev = curr;

        if (key == ckey) { return 0; }
        if (key <  ckey) { child = 1; curr = binary_search_node_left(curr);  }
        else             { child = 0; curr = binary_search_node_right(curr); }
    }
    
    binary_search_node_t node = binary_search_node_create(data);

    if (node == NULL) { return 0; }

    if (prev != NULL) {

        if (child) { binary_search_node_set_left (prev, node); }
        else       { binary_search_node_set_right(prev, node); }

    } else { tree->root = node; }

    return 1;
}

void*
binary_search_tree_retrieve(binary_search_tree_t tree, int key) {

    binary_search_node_t node = tree->root;

    while (node != NULL) {

        void* data = binary_search_node_data(node);
        int   nkey = binary_search_tree_key (data);

        if (key == nkey) { return data; }
        if (key <  nkey) { node = binary_search_node_left(node);  }
        else             { node = binary_search_node_right(node); }
    }
    return node;
}

binary_search_node_t
binary_search_tree_delete_node(binary_search_node_t node) {
    // -- node tem um filho a direita ou nenhum filho
    if (binary_search_node_left(node) == NULL) {

        binary_search_node_t right = binary_search_node_right(node);
        binary_search_node_destroy(&node);
        return right;
    }
    // -- node tem um filha a esquerda
    if (binary_search_node_right(node) == NULL) {

        binary_search_node_t left = binary_search_node_right(node);
        binary_search_node_destroy(&node);
        return left;
    }
    // -- node tem 2 filhos
    binary_search_node_t pred = binary_search_tree_predecessor(node);

    if (pred != binary_search_node_left(node)) {
        /* 
            se o predecessor for o filho a esquerda de node, 
            entao nao eh necessario atualizar o filho direito do pai de pred 
            nem atualizar o filho esquerdo de pred
        */
        binary_search_node_t parent = binary_search_node_parent(pred);

        binary_search_node_set_right(parent, binary_search_node_left(pred));
        binary_search_node_set_left (pred  , binary_search_node_left(node));
	}

    binary_search_node_set_right(pred, binary_search_node_right(node));
    binary_search_node_destroy(&node);

    return pred;
}

int
binary_search_tree_delete(binary_search_tree_t tree, int key) {

    binary_search_node_t prev = NULL;
    binary_search_node_t curr = tree->root;

    while (curr != NULL) {

        void* data = binary_search_node_data(curr);
        int   nkey = binary_search_tree_key (data);

        int was_left_child;

        if (key == nkey) {

            binary_search_node_t node = binary_search_tree_delete_node(curr);

            if (prev != NULL) {

                if (was_left_child) { binary_search_node_set_left (prev, node); }
                else                { binary_search_node_set_right(prev, node); }

            } else { binary_search_node_set_parent_null(node); tree->root = node; }

            return 1;
        }

        prev = curr;

        if (key < nkey) { was_left_child = 1; curr = binary_search_node_left (curr); }
        else            { was_left_child = 0; curr = binary_search_node_right(curr); }
    }
    return 0;
}

void
print_line_begin(int level, const char* pattern, const char* end_pattern) {

    for (int i = 0; i < level; ++i) { printf("%s", pattern); }
    printf("%s", end_pattern); 
}

void
binary_search_tree_print_rec(binary_search_node_t node, int level) {

	if (node) {

        void* data = binary_search_node_data(node);
        int   dkey = binary_search_tree_key (data);

        printf("%05d {\n", dkey);
        print_line_begin(level + 1, ".  ", ". l: ");
        binary_search_tree_print_rec (binary_search_node_left(node), level + 1);
        print_line_begin(level + 1, ".  ", ". r: ");
        binary_search_tree_print_rec (binary_search_node_right(node), level + 1);
        print_line_begin(level, ".  ", "}\n");

	} else { printf("<nil>\n"); }
}

void
binary_search_tree_print(binary_search_tree_t tree) {

    binary_search_tree_print_rec (tree->root, 0);
}

void
binary_search_tree_println(binary_search_tree_t tree) {

    binary_search_tree_print(tree); putchar('\n');
}
