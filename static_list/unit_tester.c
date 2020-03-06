#include "static_list.h"

#include <stdlib.h>
#include <assert.h>

void
comparar_uma_lista_com_ela_mesma_retorna_1(void) {

    static_list list = static_list_init_sequential_list(5, 3);
    assert(static_list_compare(list, list) == 1);
}

void
comparar_duas_listas_vazias_retorna_1(void) {

    static_list xs = static_list_init_sequential_list(5, 0);
    static_list ys = static_list_init_sequential_list(5, 0);
    assert(static_list_compare(xs, ys) == 1);
}

void
comparar_duas_listas_iguais_retorna_1(void) {

    static_list xs = static_list_init_sequential_list(5, 3);
    static_list ys = static_list_init_sequential_list(5, 3);
    assert(static_list_compare(xs, ys) == 1);
}

void
comparar_duas_listas_diferentes_retorna_0(void) {

    static_list xs = static_list_init_sequential_list(5, 3);
    static_list ys = static_list_init_sequential_list(5, 4);
    assert(static_list_compare(xs, ys) == 0);
}

void
printing_an_empty_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 0);
    static_list_println(list);
}

void
printing_an_not_full_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 3);
    static_list_println(list);
}

void
printing_an_full_list(void) {
    
    static_list list = static_list_init_sequential_list(5, 5);
    static_list_println(list);
}

void
criar_uma_lista_de_tamanho_0_retorna_NULL(void) {

    static_list list = static_list_create(0);
    assert(list == NULL);
}

void
criar_uma_lista_de_tamanho_negativo_retorna_NULL(void) {

    static_list list = static_list_create(-5);
    assert(list == NULL);
}

void
criar_uma_lista_de_tamanho_positivo_retorna_ponteiro(void) {

    static_list list = static_list_create(5);
    assert(list != NULL);
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
    
    // deveria haver uma forma de verificar se os itens estao sendo liberados mesmo

    static_list_destroy(&list);
    assert(list == NULL);
}

int
main (int argc, char** argv) {

    comparar_uma_lista_com_ela_mesma_retorna_1();
    comparar_duas_listas_vazias_retorna_1();
    comparar_duas_listas_iguais_retorna_1();
    comparar_duas_listas_diferentes_retorna_0();

    // printing_an_empty_list();
    // printing_an_not_full_list();
    // printing_an_full_list();
    
    criar_uma_lista_de_tamanho_0_retorna_NULL();
    criar_uma_lista_de_tamanho_negativo_retorna_NULL();
    criar_uma_lista_de_tamanho_positivo_retorna_ponteiro();

    deletar_uma_lista_igual_a_NULL_nao_acontece_nada();
    deletar_uma_lista_vazia_a_lista_e_liberada_e_armazena_NULL();
    deletar_uma_lista_nao_vazia_a_lista_e_os_itens_da_lista_sao_liberados_e_a_lista_armazena_NULL();

    return 0;
}
