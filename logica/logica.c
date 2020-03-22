#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jogar(ESTADO *e, COORDENADA c) {
    mudar_estado(e,c);
    return 1;
}

int jogadaValida(ESTADO * estado, COORDENADA c) {
    if (estado->tab[c.linha][c.coluna] != VAZIO && estado->tab[c.linha][c.coluna] != '1' && estado->tab[c.linha][c.coluna] != '2') {
        return 0;
    } else if (abs(c.linha - estado->ultima_jogada.linha) > 1) {
        return 0;
    } else if (abs(c.coluna - estado->ultima_jogada.coluna) > 1) {
        return 0;
    } else if (c.coluna > 7 || c.linha > 7 || c.coluna < 0 || c.linha < 0) {
        return 0;
    } else {
        return 1;
    }
}

int jogadorVencedor (ESTADO *estado){
    if (estado->tab[7][0] == BRANCA) {
        return 1;
    } else if (estado->tab[0][7] == BRANCA){
        return 2;
    } else {
        return -1;
    }
}

int imprimirTabuleiro (ESTADO *estado) {
    FILE *fp;

    fp = fopen("tabuleiro.txt", "w");

    for(int i=0; i < LINE_SIZE; i++) {
        for(int j=0; j < LINE_SIZE; j++) {
            if (i==0 && j==7) {
                fputs("2", fp);
            }
            else if (i==7 && j==0) {
                fputs("1", fp);
            }
            else if (estado->tab[i][j] == VAZIO) {
                fputs(".", fp);
            }
            else if (estado->tab[i][j] == BRANCA) {
                fputs("*", fp);
            }
            else{
                fputs("#", fp);
            }
        }

        fputs("\n", fp);
    }

    fclose(fp);

    return 1;
}

int lerTabuleiro (ESTADO *estado) {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file;
    file = fopen("tabuleiro.txt", "r");

    int q = 0;

    if (file) {
        while ((read = getline(&line, &len, file)) != -1) {
            for (int i = 0; i < strlen(line); i++) {
                if (line[i] == '.') {
                    estado->tab[q][i] = VAZIO;
                } else if (line[i] == '*') {
                    estado->tab[q][i] = BRANCA;

                    COORDENADA coord = {i, q};
                    estado->ultima_jogada = coord;
                } else if (line[i] == '#') {
                    estado->tab[q][i] = PRETA;
                } else if (line[i] == '2') {
                    estado->tab[q][i] = '2';
                } else if (line[i] == '1') {
                    estado->tab[q][i] = '1';
                }
            }

            q = q+1;
        }

        fclose(file);
    }
}