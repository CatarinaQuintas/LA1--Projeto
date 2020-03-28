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

            putchar(e->tab[i][j]);

        }
        putchar('\n');
    }

    printf("%s\n", "  abcdefgh");

    int num_jogadas_totais = obter_numero_de_jogadas(e) * 2;

    if(e->jogador_atual == 2) {
        num_jogadas_totais--;
    }

    printf("# %i PL%i  ", num_jogadas_totais, obter_jogador_atual(e));

    printf("(%i)", obter_numero_de_jogadas_do_jogador_atual(e));

    printf(" > ");
}

void imprimir_movs(ESTADO *e){
    int num_jogadas = obter_numero_de_jogadas(e);

    for (int i = 0; i<num_jogadas; i++){
        printf("%02d: ", i + 1);
        JOGADA jogada = e->jogadas[i];
        printf("%c%c ",jogada.jogador1.coluna + 'a', jogada.jogador1.linha + '1');

        if ( i != num_jogadas - 1 || e->jogador_atual == 1) {
            printf("%c%c ",jogada.jogador2.coluna + 'a', jogada.jogador2.linha + '1');
        }

        putchar('\n');
    }
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
            imprimir_tabuleiro(e);
        }

        if (strcmp(linha, "ler\n") == 0) {
            lerTabuleiro(e);

            mostrar_tabuleiro(e, -1);
        }

        if (strcmp(linha, "movs\n") == 0){
            imprimir_movs(e);

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
