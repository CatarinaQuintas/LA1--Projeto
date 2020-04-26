
#ifndef LAB1_LISTA_H
#define LAB1_LISTA_H

#endif //LAB1_LISTA_H


typedef struct nodo{
    void * valor;
    struct nodo * cauda;
} *LISTA, NODO;


LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdadeiro se a lista é vazia
int lista_esta_vazia(LISTA L);
