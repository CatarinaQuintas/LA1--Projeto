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
    e->tab[3][4] = BRANCA;
    COORDENADA coord = {4,3};
    e->ultima_jogada = coord;
}

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    inicializar_tabuleiro(e);
    inicializar_branca(e);
    return e;
}

int mudar_estado(ESTADO *e, COORDENADA c){
    int col_branca = e->ultima_jogada.coluna;
    int lin_branca = e->ultima_jogada.linha;

    e->tab[lin_branca][col_branca] = PRETA;

    e->ultima_jogada = c;

    e->tab[c.linha][c.coluna] = BRANCA;

    e->num_jogadas = e->num_jogadas + 1;

    if (e->jogador_atual == 1){
        e->jogador_atual = 2;

        e->num_jogadas_jogador1 = e->num_jogadas_jogador1 + 1;
    }
    else{
        e->jogador_atual = 1;

        e->num_jogadas_jogador2 = e->num_jogadas_jogador2 + 1;
    }

    return 1;
}
