#include "interface.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    for (int i = 0; i < LINE_SIZE; i++) {
        for (int j = 0; j < LINE_SIZE; j++) {
            if (i==0 && j==7) {
                putchar('2');
            }
            else if (i==7 && j==0) {
                putchar('1');
            }
            else if (e->tab[i][j] == VAZIO) {
                putchar('.');
            }
            else if (e->tab[i][j] == BRANCA) {
                putchar('*');
            }
            else{
                putchar('#');
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '0'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    } return 1;
}
