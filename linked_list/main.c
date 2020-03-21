#include "linked_node.h"
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int*
new_int(int number) {

    int* data = (int*) malloc(sizeof(int)); *data = number;
    return data;
}

linked_node_t
new_int_node(int number) {

    return linked_node_create(new_int(number));
}

void
destruir_um_node_atribui_NULL_a_variavel(void) {

    linked_node_t node = new_int_node(42);
    linked_node_destroy(&node);    
    assert(node == NULL);
}

void
consultar_o_dado_do_node_retorna_o_dado(void) {

    linked_node_t node = new_int_node(42);
    int data = *(int*) linked_node_data(node);
    assert(data == 42);
}

void
comparar_um_node_com_ele_mesmo_retorna_0(void) {

    linked_node_t node = new_int_node(42);
    assert(linked_node_compare(node, node, sizeof(int)) == 0);
    linked_node_destroy(&node);
}

void
comparar_nodes_diferentes_retorna_um_valor_diferente_de_0(void) {

    linked_node_t node = new_int_node(42);
    linked_node_t other = new_int_node(16);
    
    assert(linked_node_compare(node, other, sizeof(int)) != 0);

    linked_node_destroy(&node);
    linked_node_destroy(&other);
}

void
criar_um_node_NULL_eh_possivel(void) {

    linked_node_t node = linked_node_create(NULL);
    assert(linked_node_data(node) == NULL);
    linked_node_destroy(&node);
}

void
o_next_de_um_node_recem_criado_eh_NULL(void) {
    linked_node_t node = linked_node_create(NULL);
    assert(linked_node_next(node) == NULL);
    linked_node_destroy(&node);
}

void
linkar_o_node_2_no_node_1_torna_o_next_de_node_1_igual_ao_node_2(void) {

    linked_node_t node1 = new_int_node(42);
    linked_node_t node2 = new_int_node(16);

    linked_node_link(node1, node2);
    
    assert(linked_node_next(node1) == node2);

    linked_node_destroy(&node1);
    linked_node_destroy(&node2);
}
// -- list
void
criar_uma_linked_list_retorna_uma_lista_vazia(void) {

    linked_list_t list = linked_list_create();

    assert(linked_list_compare(list, list, 1) == 0);
    linked_list_destroy(&list);
}

void
uma_linked_list_vazia_tem_tamanho_0(void) {

    linked_list_t list = linked_list_create();
    assert(linked_list_length(list) == 0);
    linked_list_destroy(&list);
}

void
linked_list_isempty_retorna_1_se_a_list_for_vazia(void) {

    linked_list_t list = linked_list_create();
    assert(linked_list_isempty(list) == 1);
    linked_list_destroy(&list);
}

void
adicionar_um_dado_a_list_vazia_altera_o_tamanho_da_lista_para_1(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(42));
    
    assert(linked_list_compare(list,list, sizeof(int)) == 0);
    assert(linked_list_length(list) == 1);
    linked_list_destroy(&list);
}

void
adicionar_3_2_1_em_uma_list_vazia_altera_o_tamanho_da_lista_para_3(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));
    
    assert(linked_list_compare(list,list, sizeof(int)) == 0);
    assert(linked_list_length(list) == 3);
    linked_list_destroy(&list);
}

void
remover_o_item_da_posicao_1_de_uma_list_1_2_3_altera_o_tamanho_da_lista_para_2(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    linked_list_t test = linked_list_create();

    linked_list_add(test, 0, new_int(3));
    linked_list_add(test, 0, new_int(1));

    linked_list_delete(list, 1);
    
    assert(linked_list_compare(list,test, sizeof(int)) == 0);
    assert(linked_list_length(list) == 2);
    linked_list_destroy(&list);
    linked_list_destroy(&test);
}

void
consultar_uma_posicao_negativa_da_lista_1_2_3_returna_NULL(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    assert(linked_list_retrive(list, -1) == NULL);
    linked_list_destroy(&list);
}

void
consultar_o_primeiro_elemento_da_lista_1_2_3_4_5_returna_1(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(5));
    linked_list_add(list, 0, new_int(4));
    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    int data = *(int*) linked_list_retrive(list,0);
    assert(data == 1);
    linked_list_destroy(&list);
}

void
consultar_a_posicao_2_da_lista_1_2_3_4_5_returna_3(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(5));
    linked_list_add(list, 0, new_int(4));
    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    int data = *(int*) linked_list_retrive(list, 2);

    assert(data == 3);
    linked_list_destroy(&list);
}

void
consultar_o_ultimo_elemento_da_lista_1_2_3_4_5_returna_5(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(5));
    linked_list_add(list, 0, new_int(4));
    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    int data = *(int*) linked_list_retrive(list,linked_list_length(list)-1);
    assert(data == 5);
    linked_list_destroy(&list);
}

void
consultar_a_posicao_3_da_lista_1_2_3_returna_NULL(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    assert(linked_list_retrive(list, 3) == NULL);
    linked_list_destroy(&list);
}

void
linked_list_println(linked_list_t list) {

    long int length = linked_list_length(list);

    putchar('[');

    for (int pos = 0; pos < length; ++pos) {

        printf(" %d", *(int*)linked_list_retrive(list, pos));
    }
    printf(" ]\n");
}

void
print_uma_lista_vazia(void) {

    linked_list_t list = linked_list_create();
    linked_list_println(list);
    linked_list_destroy(&list);
}

void
print_lista_1_2_3_4_5(void) {

    linked_list_t list = linked_list_create();

    linked_list_add(list, 0, new_int(5));
    linked_list_add(list, 0, new_int(4));
    linked_list_add(list, 0, new_int(3));
    linked_list_add(list, 0, new_int(2));
    linked_list_add(list, 0, new_int(1));

    linked_list_println(list);
    linked_list_destroy(&list);
}

int
main (int argc, char const *argv[]) {

    destruir_um_node_atribui_NULL_a_variavel();

    consultar_o_dado_do_node_retorna_o_dado();

    comparar_um_node_com_ele_mesmo_retorna_0();
    comparar_nodes_diferentes_retorna_um_valor_diferente_de_0();

    criar_um_node_NULL_eh_possivel();

    o_next_de_um_node_recem_criado_eh_NULL();

    linkar_o_node_2_no_node_1_torna_o_next_de_node_1_igual_ao_node_2();

    // -- list
    criar_uma_linked_list_retorna_uma_lista_vazia();
    
    uma_linked_list_vazia_tem_tamanho_0();

    linked_list_isempty_retorna_1_se_a_list_for_vazia();

    adicionar_um_dado_a_list_vazia_altera_o_tamanho_da_lista_para_1();
    adicionar_3_2_1_em_uma_list_vazia_altera_o_tamanho_da_lista_para_3();

    remover_o_item_da_posicao_1_de_uma_list_1_2_3_altera_o_tamanho_da_lista_para_2();

    consultar_uma_posicao_negativa_da_lista_1_2_3_returna_NULL();
    consultar_o_primeiro_elemento_da_lista_1_2_3_4_5_returna_1();
    consultar_a_posicao_2_da_lista_1_2_3_4_5_returna_3();
    consultar_o_ultimo_elemento_da_lista_1_2_3_4_5_returna_5();
    consultar_a_posicao_3_da_lista_1_2_3_returna_NULL();

    print_uma_lista_vazia();
    print_lista_1_2_3_4_5();

    return 0;
}
