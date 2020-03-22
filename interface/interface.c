#include "interface.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024



void mostrar_tabuleiro(ESTADO *e, int jogadorVencedor) {


for (int i = 0; i < LINE_SIZE; i++) {
        for (int j = 0; j < LINE_SIZE; j++) {
            if (j == 0) {
                printf("%i", i + 1);
                putchar(' ');
            }

            if (i==0 && j==7) {
                if (jogadorVencedor == 2) {
                    putchar('*');
                } else {
                    putchar('2');
                }
            }
            else if (i==7 && j==0) {
                if (jogadorVencedor == 1) {
                    putchar('*');
                } else {
                    putchar('1');
                }
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

    printf("%s\n", "  abcdefgh");

    printf("# %i PL%i  ", e->num_jogadas, e->jogador_atual);

    if (e->jogador_atual == 1) {
        printf("(%i)", e->num_jogadas_jogador1);
    } else {
        printf("(%i)", e->num_jogadas_jogador2);
    }

    putchar('\n');
}

int interpretador(ESTADO *e) {
    while (1) {
        char linha[BUF_SIZE];
        char col[2], lin[2];
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if (strcmp(linha, "Q\n") == 0) {
            break;
        }

        if (strcmp(linha, "gr\n") == 0) {
            imprimirTabuleiro(e);
        }

        if (strcmp(linha, "ler\n") == 0) {
            lerTabuleiro(e);

            mostrar_tabuleiro(e, -1);
        }

        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};

            if (jogadaValida(e, coord) == 0) {
                printf("Jogada inválida, tente novamente: \n");
                interpretador(e);
                return 1;
            }

            jogar(e, coord);

            if (jogadorVencedor(e) == 1) {
                mostrar_tabuleiro(e, 1);
                printf("Jogador 1 venceu, parabéns!! \n");
                break;
            } else if (jogadorVencedor(e) == 2) {
                mostrar_tabuleiro(e, 2);

                printf("Jogador 2 venceu, parabéns!! \n");
                break;
            }

            mostrar_tabuleiro(e, -1);
        }  else if(strlen(linha) == 2) {

        }
    }

    return 1;
}
