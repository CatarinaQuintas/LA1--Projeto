/**
 @file dados.c
 */
#include "dados.h"
#include <stdlib.h>


void inicializar_tabuleiro(ESTADO *e){
    for (int i=0; i<LINE_SIZE; i++){
        for (int j=0; j<LINE_SIZE; j++){
                e->tab[i][j] = VAZIO;
        }
    }
}

void inicializar_branca(ESTADO *e){
    e->tab[4][4] = BRANCA;
    COORDENADA coord = {4,4};
    e->ultima_jogada = coord;
}

void inicializar_jogadores(ESTADO *e){
    e->tab[7][7] = DOIS;
    e->tab[0][0] = UM;
}

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_jogadas_totais = 0;
    e->num_comandos = 1;
    e->num_jogadas_jogador1 = 1;
    e->num_jogadas_jogador2 = 1;
    inicializar_tabuleiro(e);
    inicializar_jogadores(e);
    inicializar_branca(e);
    return e;
}

int mudar_estado(ESTADO *e, COORDENADA c){

    int col_branca = e->ultima_jogada.coluna;
    int lin_branca = e->ultima_jogada.linha;

    e->tab[lin_branca][col_branca] = PRETA;

    e->tab[c.linha][c.coluna] = BRANCA;

    if (e->jogador_atual == 1){

        e->jogador_atual = 2;

        e->num_jogadas_jogador1 = e->num_jogadas_jogador1 + 1;

        e->jogadas[e->num_jogadas].jogador1 = c;
    }
    else{
        e->jogador_atual = 1;

        e->num_jogadas_jogador2 = e->num_jogadas_jogador2 + 1;

        e->jogadas[e->num_jogadas].jogador2 = c;

        e->num_jogadas = e->num_jogadas + 1;

    }

    e->num_jogadas_totais = e->num_jogadas;

    e->ultima_jogada = c;

    return 0;
}

int obter_jogador_atual(ESTADO *e){
    return e->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *e){
    return e->num_jogadas;
}

int obter_numero_de_jogadas_do_jogador_atual(ESTADO *e){
    if (e->jogador_atual == 1) return e->num_jogadas_jogador1;
    else return e->num_jogadas_jogador2;
}

int obter_numero_de_comandos(ESTADO *e){
    return e->num_comandos;
}

void incrementar_numero_de_comandos(ESTADO *e){
     e->num_comandos++;
}

int retomar_tabuleiro_na_jogada(ESTADO *e, int x){

    int result;
    if (x > e->num_jogadas_totais){
        result = 1;
    }
    else{
        e->jogador_atual = 1;
        e->num_jogadas = x;

        inicializar_tabuleiro(e);
        inicializar_branca(e);

        for (int j=0; j<x; j++){
            int col_branca = e->ultima_jogada.coluna;
            int lin_branca = e->ultima_jogada.linha;

            e->tab[lin_branca][col_branca] = PRETA;
            e->tab[e->jogadas[j].jogador1.linha][e->jogadas[j].jogador1.coluna] = PRETA;
            e->tab[e->jogadas[j].jogador2.linha][e->jogadas[j].jogador2.coluna] = BRANCA;

            e->ultima_jogada = e->jogadas[j].jogador2;
        }
        result = 0;
    }
    return result;
}

int testa_livre(ESTADO *e, int linha, int coluna){
    CASA casa = e->tab[linha][coluna];

    return (casa == VAZIO || casa == UM || casa == DOIS);
}








