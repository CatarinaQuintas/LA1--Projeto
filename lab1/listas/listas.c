#include "listas.h"
#include <stdlib.h>

LISTA criar_lista(){
    return NULL;
}

LISTA insere_cabeca(LISTA L, void *valor){
    NODO * node = malloc(sizeof(NODO));
    node->valor = valor;
    node->cauda = L;
    return node;
}

void * devolve_cabeca(LISTA L){
    return (L->valor);
}

LISTA proximo(LISTA L){
    LISTA proxima;

    if (L!= NULL){
        proxima = L->cauda;
    } else{
        proxima = NULL;
    }

    return proxima;
}

LISTA remove_cabeca(LISTA L){
    if (L == NULL){
        return NULL;
    }

    LISTA temp = L;
    L = L->cauda;

    free(temp);

    return L;
}


int lista_esta_vazia(LISTA L){
    return (L == NULL);
}
