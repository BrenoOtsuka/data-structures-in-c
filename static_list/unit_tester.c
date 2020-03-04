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

int
main (int argc, char** argv) {
    
    criar_uma_lista_de_tamanho_0_retorna_NULL();
    criar_uma_lista_de_tamanho_negativo_retorna_NULL();
    criar_uma_lista_de_tamanho_positivo_retorna_ponteiro();

    return 0;
}
