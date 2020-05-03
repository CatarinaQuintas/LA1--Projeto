
/**
 @file listas.h
 */

#ifndef LAB1_LISTA_H
#define LAB1_LISTA_H

#endif //LAB1_LISTA_H


typedef struct nodo{
    void * valor;
    struct nodo * cauda;
} *LISTA, NODO;

/**
* @brief Lista cria uma lista.
* Esta função cria uma lista vazia.
*/
LISTA criar_lista();

/**
* @brief  Lista insere cabeça.
*
* @param  Estado  Esta função recebe uma lista.
* @param  Estado  Esta função recebe um valor.
*
* Esta função insere um valor na cabeça da lista.
*/
LISTA insere_cabeca(LISTA L, void *valor);


/**
* @brief Lista deveolve_cabeça.
*
* @param  Estado  Esta função recebe uma lista.
*
* Esta função devolve a cabeça da lista.
*/
void *devolve_cabeca(LISTA L);


/**
* @brief  Lista proximo
*
* @param  Estado  Esta funçao recebe uma lista.
*
* Esta função devolve a cauda da lista.
*/
LISTA proximo(LISTA L);

/**
* @brief  Lista remove cabeça
*
* @param  Estado  Esta funçao recebe uma lista.
*
* Esta função remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
*/
LISTA remove_cabeca(LISTA L);

/**
* @brief  Lista esta vazia
*
* @param  Estado  Esta funçao recebe uma lista.
*
* Esta função devolve verdadeiro se a lista é vazia.
*/
int lista_esta_vazia(LISTA L);
