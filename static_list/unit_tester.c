#include "static_list.h"

#include <stdlib.h>
#include <assert.h>

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
    
    criar_uma_lista_de_tamanho_0_retorna_NULL();
    criar_uma_lista_de_tamanho_negativo_retorna_NULL();
    criar_uma_lista_de_tamanho_positivo_retorna_ponteiro();

    deletar_uma_lista_igual_a_NULL_nao_acontece_nada();
    deletar_uma_lista_vazia_a_lista_e_liberada_e_armazena_NULL();
    deletar_uma_lista_nao_vazia_a_lista_e_os_itens_da_lista_sao_liberados_e_a_lista_armazena_NULL();

    return 0;
}
