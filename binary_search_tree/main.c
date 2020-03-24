#include "binary_search_node.h"
#include "binary_search_tree.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int*
new_int(int number) {

    int* data = (int*) malloc(sizeof(int)); *data = number;
    return data;
}

binary_search_node_t
new_int_node(int number) {

    return binary_search_node_create( new_int(number) );
}
// -- node
void
destruir_um_node_atribui_NULL_a_variavel(void) {

    binary_search_node_t node = new_int_node(42);
    binary_search_node_destroy(&node);    
    assert(node == NULL);
}

void
consultar_o_dado_do_node_retorna_o_dado(void) {

    binary_search_node_t node = new_int_node(42);
    int data = *(int*) binary_search_node_data(node);
    assert(data == 42);
    binary_search_node_destroy(&node);
}

void
criar_um_node_NULL_eh_possivel(void) {

    binary_search_node_t node = binary_search_node_create(NULL);
    assert(binary_search_node_data(node) == NULL);
    binary_search_node_destroy(&node);
}

void
o_left_de_um_node_recem_criado_eh_NULL(void) {
    binary_search_node_t node = binary_search_node_create(NULL);
    assert(binary_search_node_left(node) == NULL);
    binary_search_node_destroy(&node);
}

void
linkar_o_node_2_no_node_1_torna_o_next_de_node_1_igual_ao_node_2(void) {

    binary_search_node_t node1 = new_int_node(42);
    binary_search_node_t node2 = new_int_node(16);

    binary_search_node_set_left(node1, node2);
    
    assert(binary_search_node_left(node1) == node2);

    binary_search_node_destroy(&node1);
    binary_search_node_destroy(&node2);
}

int
main (int argc, char const *argv[]) {

    destruir_um_node_atribui_NULL_a_variavel();
    consultar_o_dado_do_node_retorna_o_dado();

    criar_um_node_NULL_eh_possivel();

    o_left_de_um_node_recem_criado_eh_NULL();
    linkar_o_node_2_no_node_1_torna_o_next_de_node_1_igual_ao_node_2();

    binary_search_tree_t tree = binary_search_tree_create();

    binary_search_tree_add(tree, new_int( 5));
    binary_search_tree_add(tree, new_int( 9));
    binary_search_tree_add(tree, new_int( 6));
    binary_search_tree_add(tree, new_int( 7));
    binary_search_tree_add(tree, new_int( 4));
    binary_search_tree_add(tree, new_int( 3));
    binary_search_tree_add(tree, new_int( 2));
    
    binary_search_tree_add(tree, new_int(15));
    binary_search_tree_add(tree, new_int(19));
    binary_search_tree_add(tree, new_int(16));
    binary_search_tree_add(tree, new_int(17));
    binary_search_tree_add(tree, new_int(14));
    binary_search_tree_add(tree, new_int(13));
    binary_search_tree_add(tree, new_int(12));
    
    binary_search_tree_add(tree, new_int(25));
    binary_search_tree_add(tree, new_int(29));
    binary_search_tree_add(tree, new_int(26));
    binary_search_tree_add(tree, new_int(27));
    binary_search_tree_add(tree, new_int(24));
    binary_search_tree_add(tree, new_int(23));
    binary_search_tree_add(tree, new_int(22));
    
    binary_search_tree_add(tree, new_int(35));
    binary_search_tree_add(tree, new_int(39));
    binary_search_tree_add(tree, new_int(36));
    binary_search_tree_add(tree, new_int(37));
    binary_search_tree_add(tree, new_int(34));
    binary_search_tree_add(tree, new_int(33));
    binary_search_tree_add(tree, new_int(32));
    
    binary_search_tree_add(tree, new_int(45));
    binary_search_tree_add(tree, new_int(49));
    binary_search_tree_add(tree, new_int(46));
    binary_search_tree_add(tree, new_int(47));
    binary_search_tree_add(tree, new_int(44));
    binary_search_tree_add(tree, new_int(43));
    binary_search_tree_add(tree, new_int(42));
    
    binary_search_tree_add(tree, new_int(5));

    binary_search_tree_println(tree);

    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 5));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 9));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 6));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 7));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 4));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 3));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 2));
    printf("tree: %d\n", *(int*)binary_search_tree_retrieve(tree, 5));
    printf("tree: %s\n", binary_search_tree_retrieve(tree,-1) == NULL ? "NULL" : "fail");

    binary_search_tree_delete(tree, 2); binary_search_tree_println(tree); putchar('\n');
    binary_search_tree_delete(tree, 5); binary_search_tree_println(tree); putchar('\n');
    binary_search_tree_delete(tree, 4); binary_search_tree_println(tree); putchar('\n');
    binary_search_tree_delete(tree, 6); binary_search_tree_println(tree); putchar('\n');
    binary_search_tree_delete(tree, 7); binary_search_tree_println(tree); putchar('\n');

    binary_search_tree_destroy(&tree);

    return 0;
}
