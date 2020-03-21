#include "doubly_linked_node.h"
#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int*
new_int(int number) {

    int* data = (int*) malloc(sizeof(int)); *data = number;
    return data;
}

doubly_linked_node_t
new_int_node(int number) {

    return doubly_linked_node_create(new_int(number));
}

void
destruir_um_node_atribui_NULL_a_variavel(void) {

    doubly_linked_node_t node = new_int_node(42);
    doubly_linked_node_destroy(&node);    
    assert(node == NULL);
}

void
consultar_o_dado_do_node_retorna_o_dado(void) {

    doubly_linked_node_t node = new_int_node(42);
    int data = *(int*) doubly_linked_node_data(node);
    assert(data == 42);
    doubly_linked_node_destroy(&node);
}

void
comparar_um_node_com_ele_mesmo_retorna_0(void) {

    doubly_linked_node_t node = new_int_node(42);
    assert(doubly_linked_node_compare(node, node, sizeof(int)) == 0);
    doubly_linked_node_destroy(&node);
}

void
comparar_nodes_diferentes_retorna_um_valor_diferente_de_0(void) {

    doubly_linked_node_t node = new_int_node(42);
    doubly_linked_node_t other = new_int_node(16);
    
    assert(doubly_linked_node_compare(node, other, sizeof(int)) != 0);

    doubly_linked_node_destroy(&node);
    doubly_linked_node_destroy(&other);
}

void
criar_um_node_NULL_eh_possivel(void) {

    doubly_linked_node_t node = doubly_linked_node_create(NULL);
    assert(doubly_linked_node_data(node) == NULL);
    doubly_linked_node_destroy(&node);
}

void
o_next_de_um_node_recem_criado_eh_NULL(void) {
    doubly_linked_node_t node = doubly_linked_node_create(NULL);
    assert(doubly_linked_node_next(node) == NULL);
    doubly_linked_node_destroy(&node);
}

void
linkar_o_node_2_no_node_1_torna_o_next_de_node_1_igual_ao_node_2(void) {

    doubly_linked_node_t node1 = new_int_node(42);
    doubly_linked_node_t node2 = new_int_node(16);

    doubly_linked_node_link(node1, node2);
    
    assert(doubly_linked_node_next(node1) == node2);

    doubly_linked_node_destroy(&node1);
    doubly_linked_node_destroy(&node2);
}

// -- list
void
comparar_NULL_com_NULL(void) {

    assert(doubly_linked_list_compare(NULL, NULL, 1) == 0);
}

void
comparar_doubly_linked_list_com_NULL(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    assert(doubly_linked_list_compare(list, NULL, 1) != 0);
    doubly_linked_list_destroy(&list);
}

void
criar_uma_doubly_linked_list_retorna_uma_lista_vazia(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    assert(doubly_linked_list_compare(list, list, 1) == 0);
    doubly_linked_list_destroy(&list);
}

void
uma_doubly_linked_list_vazia_tem_tamanho_0(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    assert(doubly_linked_list_length(list) == 0);
    doubly_linked_list_destroy(&list);
}

void
doubly_linked_list_isempty_retorna_1_se_a_list_for_vazia(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    assert(doubly_linked_list_isempty(list) == 1);
    doubly_linked_list_destroy(&list);
}

void
adicionar_um_dado_a_list_vazia_altera_o_tamanho_da_lista_para_1(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    
    doubly_linked_list_add(list, 0, new_int(42));
    
    assert(doubly_linked_list_compare(list,list, sizeof(int)) == 0);
    assert(doubly_linked_list_length(list) == 1);
    doubly_linked_list_destroy(&list);
}

void
adicionar_3_2_1_em_uma_list_vazia_altera_o_tamanho_da_lista_para_3(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));
    
    assert(doubly_linked_list_compare(list,list, sizeof(int)) == 0);
    assert(doubly_linked_list_length(list) == 3);
    doubly_linked_list_destroy(&list);
}

void
remover_o_item_da_posicao_1_de_uma_list_1_2_3_altera_o_tamanho_da_lista_para_2(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    doubly_linked_list_t test = doubly_linked_list_create();

    doubly_linked_list_add(test, 0, new_int(3));
    doubly_linked_list_add(test, 0, new_int(1));

    doubly_linked_list_delete(list, 1);
    
    assert(doubly_linked_list_compare(list,test, sizeof(int)) == 0);
    assert(doubly_linked_list_length(list) == 2);

    doubly_linked_list_destroy(&list);
    doubly_linked_list_destroy(&test);
}

void
consultar_uma_posicao_negativa_da_lista_1_2_3_returna_NULL(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    assert(doubly_linked_list_retrive(list, -1) == NULL);
    doubly_linked_list_destroy(&list);
}

void
consultar_o_primeiro_elemento_da_lista_1_2_3_4_5_returna_1(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(5));
    doubly_linked_list_add(list, 0, new_int(4));
    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    int data = *(int*) doubly_linked_list_retrive(list,0);
    assert(data == 1);
    doubly_linked_list_destroy(&list);
}

void
consultar_a_posicao_2_da_lista_1_2_3_4_5_returna_3(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(5));
    doubly_linked_list_add(list, 0, new_int(4));
    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    int data = *(int*) doubly_linked_list_retrive(list, 2);

    assert(data == 3);
    doubly_linked_list_destroy(&list);
}

void
consultar_o_ultimo_elemento_da_lista_1_2_3_4_5_returna_5(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(5));
    doubly_linked_list_add(list, 0, new_int(4));
    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    int data = *(int*) doubly_linked_list_retrive(list, doubly_linked_list_length(list)-1);
    assert(data == 5);
    doubly_linked_list_destroy(&list);
}

void
consultar_a_posicao_3_da_lista_1_2_3_returna_NULL(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    assert(doubly_linked_list_retrive(list, 3) == NULL);
    doubly_linked_list_destroy(&list);
}

void
doubly_linked_list_println(doubly_linked_list_t list) {

    long int length = doubly_linked_list_length(list);

    putchar('[');

    for (int pos = 0; pos < length; ++pos) {

        printf(" %d", *(int*) doubly_linked_list_retrive(list, pos));
    }
    printf(" ]\n");
}

void
print_uma_lista_vazia(void) {

    doubly_linked_list_t list = doubly_linked_list_create();
    doubly_linked_list_println(list);
    doubly_linked_list_destroy(&list);
}

void
print_lista_1_2_3_4_5(void) {

    doubly_linked_list_t list = doubly_linked_list_create();

    doubly_linked_list_add(list, 0, new_int(5));
    doubly_linked_list_add(list, 0, new_int(4));
    doubly_linked_list_add(list, 0, new_int(3));
    doubly_linked_list_add(list, 0, new_int(2));
    doubly_linked_list_add(list, 0, new_int(1));

    doubly_linked_list_println(list);
    doubly_linked_list_destroy(&list);
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
    comparar_NULL_com_NULL();
    comparar_doubly_linked_list_com_NULL();

    criar_uma_doubly_linked_list_retorna_uma_lista_vazia();

    uma_doubly_linked_list_vazia_tem_tamanho_0();
    doubly_linked_list_isempty_retorna_1_se_a_list_for_vazia();

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
