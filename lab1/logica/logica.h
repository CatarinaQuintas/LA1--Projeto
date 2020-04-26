/**
 @file logica.h
 */


#include "../dados/dados.h"
#include "../listas/listas.h"

#ifndef LAB1_LOGICA_H
#define LAB1_LOGICA_H

#endif //LAB1_LOGICA_H

/**
 * @brief Função jogar
 * @param Estado  Esta funçao recebe um Estado ( Branca, Preta ou Vazio).
 * @param Coordenada Esta funçao recebe uma cordenada ( linha e coluna).
 * Utiliza a função mudar estado.
 */
int jogar(ESTADO *estado, COORDENADA c);


/**
* @brief Função que verifica a validade da jogada.
*
* @param  Estado  Esta funçao recebe um Estado ( Branca, Preta ou Vazio).
* @param  Coordenada Esta funçao recebe uma cordenada ( linha e coluna).
* @return 1 se a jogada for válida  e  0 se a jogada for inválida.
*
*
* Inicialmente o tabuleiro é constituído por '1', '2',  Estado Vazia  e um estado Branca.
* Verifica se o estado esta ocupado por Vazio, Preta ou branca.
* Se tiver ocupado, returna o 0.
* Verifica a distância entre a linha da última jogada e a  linha da coordenada atual.
* Se nao estiver nas posiçoes vizinhas, retorna 0.
* Verifica a distância entre a coluna da última jogada e a  coluna da coordenada atual.
* Se nao estiver nas posiçoes vizinhas, retorna 0.
* Verifica o comprimento da linha e da coluna. Se for superior a 7, retorna 0.
* Se nenhum dos casos anteriores forem aceites, retorna 1.
*/
int jogadaValida(ESTADO * estado, COORDENADA c);


/**
* @brief Função que apresenta o jogador vencedor.
*
* @param  Estado  Esta funçao recebe um Estado (Branca).
* Verifica se o estado 'Branca' está na coordenada (linha, coluna).
* Se a coordenada (7,0) estiver ocupada pelo estado branca, o vencedor é o jogador 1.
* Se a coordenada (0,7) estiver ocupada pelo estado branca, o vencedor é o jogador 2.
*
* @return Jogador vencedor.
*/
int jogadorVencedor (ESTADO *estado);

int imprimir_tabuleiro (ESTADO *estado, char* file_name);

void lerTabuleiro (ESTADO *estado, char* file_name);

LISTA coordenadas_vizinhas_livres(ESTADO *e);

void jogar_aleatorio(ESTADO *e);

void jogar_euclidiana(ESTADO *e);
