
/**
 @file interface.h
 */


#include "../logica/logica.h"

#ifndef LAB1_INTERFACE_H
#define LAB1_INTERFACE_H

#endif //LAB1_INTERFACE_H

/**
* @brief Função mostra o tabuleiro.
*
* @param  Estado  Esta funçao recebe um Estado ( Branca, Preta ou Vazio).
*
* Se o estado é vazio, o tabuleiro mostra '.' .
* Se o estado é branca,  o tabuleiro mostra '*' .
* Se o estado é preta,  o tabuleiro mostra '#' .
* Na coordenada (0,7), o jogador vencedor é o 2 e assim  o estado muda para branca, senao mostra '2'.
* Na coordenada (7,0), o jogador vencedor é o 1 e assim  o estado muda para branca, senao mostra '1'.
*/
void mostrar_tabuleiro(ESTADO *estado);



/**
* @brief Função interpretador.
*
* Nesta função são utilizados 6 comandos: gr, ler e Q, movs, pos,jog, jog02 .
* O comando gr grava o tabuleiro num ficheiro.
* O comando ler vai buscar o ficheiro guardado pelo comando gr e assim o jogo tem continuidade.
* O comando Q termina o jogo.
 * O comando movs apresenta os movimentos atá ao momento.
 * O comando pos utilizado para regressar a uma jogada pretendida.
 * O comando jog faz uma jogada aleatoria.
 * O comando jog02 faz uma jogada usando a heurística euclidiana.
*/
int interpretador(ESTADO *e);

/**
* @brief Função que joga euclidiana
*
* @param  Estado  Esta funcão recebe um estado.
* Dependendo do jogador atual, escolhe a coordenada mais próxima do 1 ou do 2 para vencer o jogo.
* Se o jogador atual for o 1, irá ser escolhida a cooordenada mais próxima do numero 1.
* Se o jogador atual for o 2, irá ser escolhida a cooordenada mais próxima do numero 2.
*/
void fazer_jogada_euclidiana(ESTADO *e);
