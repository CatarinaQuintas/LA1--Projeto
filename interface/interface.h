
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
* @param  JogadorVencedor Esta funçao recebe o jogador vencedor.
*
*
* Se o estado é vazio, o tabuleiro mostra '.' .
* Se o estado é branca,  o tabuleiro mostra '*' .
* Se o estado é preta,  o tabuleiro mostra '#' .
* Na coordenada (0,7), o jogador vencedor é o 2 e assim  o estado muda para branca, senao mostra '2'.
* Na coordenada (7,0), o jogador vencedor é o 1 e assim  o estado muda para branca, senao mostra '1'.
* @return Tabuleiro.
*/
void mostrar_tabuleiro(ESTADO *estado, int jogadorVencedor);



/**
* @brief Função interpretador.
*
* nesta função são utilizados 3 comandos: gr, ler e Q.
* O comando gr grava o tabuleiro num ficheiro.
* O comando ler vai buscar o ficheiro guardado pelo comando gr e assim o jogo tem continuidade.
* O comando Q termina o jogo.
*/
int interpretador(ESTADO *e);