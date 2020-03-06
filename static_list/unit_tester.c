#include "static_list.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void
inicializar_uma_lista_com_content_size_negativo_retorna_NULL(void) {

    static_list list = static_list_init_sequential_list(-1, 0);
    assert( list == NULL);
    static_list_destroy(&list);
}

void
inicializar_uma_lista_com_sequence_length_negativo_retorna_NULL(void) {

    static_list list = static_list_init_sequential_list(1,-1);
    assert( list == NULL);
    static_list_destroy(&list);
}

void
comparar_uma_lista_com_ela_mesma_retorna_1(void) {

    static_list list = static_list_init_sequential_list(5, 3);
    assert(static_list_compare(list, list) == 1);
    static_list_destroy(&list);
}

void
comparar_duas_listas_vazias_retorna_1(void) {

    static_list xs = static_list_init_sequential_list(5, 0);
    static_list ys = static_list_init_sequential_list(5, 0);
    assert(static_list_compare(xs, ys) == 1);
    static_list_destroy(&xs);
    static_list_destroy(&ys);
}

void
comparar_duas_listas_iguais_retorna_1(void) {

    static_list xs = static_list_init_sequential_list(5, 3);
    static_list ys = static_list_init_sequential_list(5, 3);
    assert(static_list_compare(xs, ys) == 1);
    static_list_destroy(&xs);
    static_list_destroy(&ys);
}

void
comparar_duas_listas_diferentes_retorna_0(void) {

    static_list xs = static_list_init_sequential_list(5, 3);
    static_list ys = static_list_init_sequential_list(5, 4);
    assert(static_list_compare(xs, ys) == 0);
    static_list_destroy(&xs);
    static_list_destroy(&ys);
}

void
printing_an_empty_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 0);
    static_list_println(list);
    static_list_destroy(&list);
}

void
printing_an_not_full_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 3);
    static_list_println(list);
    static_list_destroy(&list);
}

void
printing_an_full_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 5);
    static_list_println(list);
    static_list_destroy(&list);
}

void
printing_some_list(void) {
    
    const int itens[] = { 1, 3, 4 };

    static_list list = static_list_init(5, 3, itens);
    static_list_println(list);
    static_list_destroy(&list);
}

void
criar_uma_lista_de_tamanho_0_retorna_NULL(void) {

    static_list list = static_list_create(0);
    assert(list == NULL);
    static_list_destroy(&list);
}

void
criar_uma_lista_de_tamanho_negativo_retorna_NULL(void) {

    static_list list = static_list_create(-5);
    assert(list == NULL);
    static_list_destroy(&list);
}

void
criar_uma_lista_de_tamanho_positivo_retorna_ponteiro(void) {

    static_list list = static_list_create(5);
    assert(list != NULL);
    static_list_destroy(&list);
}

void
deletar_uma_lista_igual_a_NULL_nao_acontece_nada(void) {
    
    static_list list = NULL;

    static_list_destroy(&list);
    assert(list == NULL);
}

void
deletar_uma_lista_vazia_a_lista_e_liberada_e_armazena_NULL(void) {

    static_list list = static_list_create(5);

    static_list_destroy(&list);
    assert(list == NULL);
}

void
deletar_uma_lista_nao_vazia_a_lista_e_os_itens_da_lista_sao_liberados_e_a_lista_armazena_NULL(void) {

    static_list list = static_list_create(5);

    static_list_destroy(&list);
    assert(list == NULL);
}

void
uma_lista_vazia_retorna_1(void) {

    static_list list = static_list_init_sequential_list(5, 0);    
    assert(static_list_isempty(list) == 1);
    static_list_destroy(&list);
}

void
uma_lista_nao_vazia_retorna_0(void) {

    static_list list = static_list_init_sequential_list(5, 3);
    assert(static_list_isempty(list) == 0);
    static_list_destroy(&list);
}

void
uma_lista_cheia_retorna_1(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    assert(static_list_isfull(list) == 1);
    static_list_destroy(&list);
}

void
uma_lista_nao_cheia_retorna_0(void) {

    static_list list = static_list_init_sequential_list(5, 4);
    assert(static_list_isfull(list) == 0);
    static_list_destroy(&list);
}

void
uma_lista_vazia_retorna_0(void) {

    static_list list = static_list_init_sequential_list(5, 0);
    assert(static_list_length(list) == 0);
    static_list_destroy(&list);
}

void
uma_lista_de_tamanho_n_retorna_n(void) {
    
    static_list list = static_list_init_sequential_list(5, 3);
    assert(static_list_length(list) == 3);
    static_list_destroy(&list);
}

void
inserir_um_item_em_uma_lista_vazia_altera_para_uma_lista_com_um_item(void) {

    static_list list = static_list_init_sequential_list(5, 0);
    static_list answer = static_list_init_sequential_list(1,1);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 1;

    static_list_insert(list, 0, item);

    assert( static_list_compare(list, answer) );
    assert( static_list_length(list) == 1 );
    static_list_destroy(&list);
    static_list_destroy(&answer);
}

void
inserir_3_na_lista_1_2_altera_a_lista_para_1_2_3(void) {

    static_list list = static_list_init_sequential_list(5, 2);
    static_list answer = static_list_init_sequential_list(3,3);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 3;

    static_list_insert(list, static_list_length(list), item);

    assert( static_list_compare(list, answer) );
    assert( static_list_length(list) == 3 );
    static_list_destroy(&answer);
    static_list_destroy(&list);
}

void
inserir_2_na_posicao_1_da_lista_1_3_4_altera_a_lista_para_1_2_3_4(void) {

    const int itens[] = { 1, 3, 4 };

    static_list list         = static_list_init(4, 3, itens);
    static_list correct_list = static_list_init_sequential_list(4, 4);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 2;

    static_list_insert(list, 1, item);

    assert( static_list_compare(list, correct_list) );
    assert( static_list_length(list) == 4 );
    static_list_destroy(&list);
    static_list_destroy(&correct_list);
}

void
inserir_1_no_inicio_da_lista_2_3_4_altera_a_lista_para_1_2_3_4(void) {

    const int itens[] = { 2, 3, 4 };

    static_list list         = static_list_init(4, 3, itens);
    static_list correct_list = static_list_init_sequential_list(4, 4);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 1;

    static_list_insert(list, 0, item);

    assert( static_list_compare(list, correct_list) );
    assert( static_list_length(list) == 4 );
    static_list_destroy(&list);
    static_list_destroy(&correct_list);
}

void
inserir_5_fora_do_limite_de_uma_lista_retorna_0(void) {

    static_list list = static_list_init_sequential_list(5, 3);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 5;

    assert( static_list_insert(list, 4, item) == 0 );
    assert( static_list_length(list) == 3 );
    static_list_destroy(&list);
}

void
inserir_5_na_posicao_menos_1_de_uma_lista_retorna_0(void) {

    static_list list = static_list_init_sequential_list(5, 3);
    
    int* item = (int*) malloc ( sizeof(int) ); *item = 5;

    assert( static_list_insert(list, -1, item) == 0 );
    assert( static_list_length(list) == 3 );
    static_list_destroy(&list);
}

void
localizar_o_item_1_na_lista_1_2_3_retorna_1_e_a_posicao_0(void) {

    position pos = -1;

    static_list list = static_list_init_sequential_list(3, 3);
    
    int* item = (int*) malloc(sizeof(int)); *item = 1;
    
    assert( static_list_contains(list, item, &pos ) == 1 );
    assert( pos == 0 );
    static_list_destroy(&list);
    free(item);
}

void
localizar_o_item_3_na_lista_1_2_3_retorna_1_e_a_posicao_2(void) {

    position pos = -1;

    static_list list = static_list_init_sequential_list(3, 3);

    int* item = (int*) malloc(sizeof(int)); *item = 3;
    
    assert( static_list_contains(list, item, &pos ) == 1 );
    assert( pos == 2 );
    static_list_destroy(&list);
    free(item);
}

void
localizar_o_item_5_na_lista_1_2_3_retorna_0(void) {

    position pos = -1;

    static_list list = static_list_init_sequential_list(3, 3);

    int* item = (int*) malloc(sizeof(int)); *item = 5;
    
    assert( static_list_contains(list, item, &pos ) == 0 );
    static_list_destroy(&list);
    free(item);
}

void
recuperar_o_item_da_lista_1_2_3_4_5_na_primeira_posicao_retorna_1(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    
    int* item = (int*) static_list_retrieve(list, 0);

    assert( *item == 1 );
    static_list_destroy(&list);
}

void
recuperar_o_item_da_lista_1_2_3_4_5_na_posicao_3_retorna_4(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    
    int* item = (int*) static_list_retrieve(list, 3);

    assert( *item == 4 );
    static_list_destroy(&list);
}

void
recuperar_o_item_da_lista_1_2_3_4_5_na_ultima_posicao_retorna_5(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    
    int* item = (int*) static_list_retrieve(list, 4);

    assert( *item == 5 );
    static_list_destroy(&list);
}

void
recuperar_um_item_da_lista_1_2_3_4_5_numa_posicao_negativa_retorna_NULL(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    
    int* item = (int*) static_list_retrieve(list, -1);

    assert( item == NULL );
    static_list_destroy(&list);
    free(item);
}

void
recuperar_um_item_da_lista_1_2_3_4_5_numa_posicao_fora_do_limite_da_lista_retorna_NULL(void) {

    static_list list = static_list_init_sequential_list(5, 5);
    
    int* item = (int*) static_list_retrieve(list, 5);

    assert( item == NULL );
    static_list_destroy(&list);
}

void
deletar_o_item_na_primeira_posicao_da_lista_1_2_3_altera_a_lista_para_2_3(void) {

    const int itens[] = { 2, 3 };
    static_list list = static_list_init_sequential_list(3, 3);
    static_list answer = static_list_init(2, 2, itens);
    
    assert( static_list_delete(list, 0) == 1 );
    assert( static_list_compare(list, answer) );
    assert( static_list_length(list) == 2 );
    static_list_destroy(&list);
    static_list_destroy(&answer);
}

void
deletar_o_item_na_posicao_1_da_lista_1_2_3_altera_a_lista_para_1_3(void) {

    const int itens[] = { 1, 3 };
    static_list list = static_list_init_sequential_list(3, 3);
    static_list answer = static_list_init(2, 2, itens);
    
    assert( static_list_delete(list, 1) == 1 );
    assert( static_list_compare(list, answer) );
    assert( static_list_length(list) == 2 );
    static_list_destroy(&list);
    static_list_destroy(&answer);
}

void
deletar_o_item_na_ultima_posicao_da_lista_1_2_3_altera_a_lista_para_1_2(void) {

    const int itens[] = { 1, 2 };
    static_list list = static_list_init_sequential_list(3, 3);
    static_list answer = static_list_init(2, 2, itens);
    
    assert( static_list_delete(list, 2) == 1 );
    assert( static_list_compare(list, answer) );
    assert( static_list_length(list) == 2 );
    static_list_destroy(&list);
    static_list_destroy(&answer);
}

void
deletar_o_item_numa_posicao_negativa_retorna_0(void) {

    static_list list = static_list_init_sequential_list(3, 3);
    
    assert( static_list_delete(list, -1) == 0 );
    assert( static_list_compare(list, list) );
    assert( static_list_length(list) == 3 );
    static_list_destroy(&list);
}

void
deletar_o_item_numa_posicao_fora_do_limite_da_lista_retorna_0(void) {

    static_list list = static_list_init_sequential_list(3, 3);
    
    assert( static_list_delete(list, 3) == 0 );
    assert( static_list_compare(list, list) );
    assert( static_list_length(list) == 3 );
    static_list_destroy(&list);
}

int
main (int argc, char** argv) {

    // printing_an_empty_list();
    // printing_an_not_full_list();
    // printing_an_full_list();
    // printing_some_list();

    inicializar_uma_lista_com_content_size_negativo_retorna_NULL();
    inicializar_uma_lista_com_sequence_length_negativo_retorna_NULL();

    comparar_uma_lista_com_ela_mesma_retorna_1();
    comparar_duas_listas_vazias_retorna_1();
    comparar_duas_listas_iguais_retorna_1();
    comparar_duas_listas_diferentes_retorna_0();

    uma_lista_vazia_retorna_1();
    uma_lista_nao_vazia_retorna_0();
    uma_lista_cheia_retorna_1();
    uma_lista_nao_cheia_retorna_0();
    uma_lista_vazia_retorna_0();
    uma_lista_de_tamanho_n_retorna_n();

    criar_uma_lista_de_tamanho_0_retorna_NULL();
    criar_uma_lista_de_tamanho_negativo_retorna_NULL();
    criar_uma_lista_de_tamanho_positivo_retorna_ponteiro();

    deletar_uma_lista_igual_a_NULL_nao_acontece_nada();
    deletar_uma_lista_vazia_a_lista_e_liberada_e_armazena_NULL();
    deletar_uma_lista_nao_vazia_a_lista_e_os_itens_da_lista_sao_liberados_e_a_lista_armazena_NULL();

    inserir_um_item_em_uma_lista_vazia_altera_para_uma_lista_com_um_item();
    inserir_3_na_lista_1_2_altera_a_lista_para_1_2_3();
    inserir_2_na_posicao_1_da_lista_1_3_4_altera_a_lista_para_1_2_3_4();
    inserir_1_no_inicio_da_lista_2_3_4_altera_a_lista_para_1_2_3_4();
    inserir_5_fora_do_limite_de_uma_lista_retorna_0();
    inserir_5_na_posicao_menos_1_de_uma_lista_retorna_0();

    localizar_o_item_3_na_lista_1_2_3_retorna_1_e_a_posicao_2();
    localizar_o_item_1_na_lista_1_2_3_retorna_1_e_a_posicao_0();
    localizar_o_item_5_na_lista_1_2_3_retorna_0();

    recuperar_o_item_da_lista_1_2_3_4_5_na_primeira_posicao_retorna_1();
    recuperar_o_item_da_lista_1_2_3_4_5_na_posicao_3_retorna_4();
    recuperar_o_item_da_lista_1_2_3_4_5_na_ultima_posicao_retorna_5();
    recuperar_um_item_da_lista_1_2_3_4_5_numa_posicao_negativa_retorna_NULL();
    recuperar_um_item_da_lista_1_2_3_4_5_numa_posicao_fora_do_limite_da_lista_retorna_NULL();

    deletar_o_item_na_primeira_posicao_da_lista_1_2_3_altera_a_lista_para_2_3();
    deletar_o_item_na_posicao_1_da_lista_1_2_3_altera_a_lista_para_1_3();
    deletar_o_item_na_ultima_posicao_da_lista_1_2_3_altera_a_lista_para_1_2();
    deletar_o_item_numa_posicao_negativa_retorna_0();
    deletar_o_item_numa_posicao_fora_do_limite_da_lista_retorna_0();

    return 0;
}

