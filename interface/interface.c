#include "interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <time.h>

#define BUF_SIZE 1024



void mostrar_tabuleiro(ESTADO *e, int jogadorVencedor ) {

for (int i = LINE_SIZE-1 ; i >= 0; i--) {
        for (int j = 0; j < LINE_SIZE; j++) {
            if (j == 0) {
                printf("%i", i + 1 );
                putchar(' ');
            }

            putchar(e->tab[i][j]);

        }
        putchar('\n');
    }

    printf("%s\n", "  abcdefgh");

    printf("# %02d PL%i  ", obter_numero_de_comandos(e), obter_jogador_atual(e));

    printf("(%i)", obter_numero_de_jogadas_do_jogador_atual(e));

    printf(" > ");


}


void imprimir_movs(ESTADO *e){
    int num_jogadas = obter_numero_de_jogadas(e);

    for (int i = 0; i<=num_jogadas; i++){

        JOGADA jogada = e->jogadas[i];

       
        if (i != num_jogadas || e->jogador_atual == 2) {
             printf("%02d: ", i + 1);
            printf("%c%c ", jogada.jogador1.coluna + 'a', jogada.jogador1.linha + '1');
            
        }
        if ( i != num_jogadas ) {
            printf("%c%c ",jogada.jogador2.coluna + 'a', jogada.jogador2.linha + '1');
        }

        putchar('\n');
    }

    printf("# %02d PL%i  ", obter_numero_de_comandos(e), obter_jogador_atual(e));

    printf("(%i)", obter_numero_de_jogadas_do_jogador_atual(e));

    printf(" > ");
}

 void jogadas_anteriores( ESTADO *e, int x ){

    int result = retomar_tabuleiro_na_jogada(e,x);

    if (result == 1){
        printf("Não é possível voltar a essa posição\n");
    }
}


LISTA jogadas_possiveis(ESTADO *e){
    LISTA L = coordenadas_vizinhas_livres(e);

    /*
    for(LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        // Vai buscar a cabeça da lista
        // Passa do tipo genérico void * para char *
        COORDENADA* cabeca =  devolve_cabeca(T);
        printf("%c%c ", cabeca->coluna + 'a',  cabeca->linha+ '1' );
    }*/

    return L;
}

void fazer_jogada_aleatoria(ESTADO *e){

    jogar_aleatorio(e);

    if (jogadorVencedor(e) == 1) {
        mostrar_tabuleiro(e, 1);
        printf("Jogador 1 venceu, parabéns!! \n");
    } else if (jogadorVencedor(e) == 2) {
        mostrar_tabuleiro(e, 2);

        printf("Jogador 2 venceu, parabéns!! \n");
    }

}

void fazer_jogada_euclidiana(ESTADO *e){

    jogar_euclidiana(e);

    if (jogadorVencedor(e) == 1) {
        mostrar_tabuleiro(e, 1);
        printf("Jogador 1 venceu, parabéns!! \n");
    } else if (jogadorVencedor(e) == 2) {
        mostrar_tabuleiro(e, 2);

        printf("Jogador 2 venceu, parabéns!! \n");
    }

}



int interpretador(ESTADO *e) {
    while (1) {
        char linha[BUF_SIZE];
        char col[2], lin[2];
        char pos[2];
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if (strcmp(linha, "Q\n") == 0) {
            incrementar_numero_de_comandos(e);
            break;
        }

        if  ( strcmp(linha, "jog\n") == 0){
            fazer_jogada_euclidiana(e);
            incrementar_numero_de_comandos(e);
            mostrar_tabuleiro(e, -1);

        }
        if (strcmp(linha, "gr\n") == 0) {
            incrementar_numero_de_comandos(e);

            imprimir_tabuleiro(e);

            mostrar_tabuleiro(e, -1);
        }

        if (strcmp(linha, "ler\n") == 0) {
            incrementar_numero_de_comandos(e);
            lerTabuleiro(e);


        }

        if (strcmp(linha, "movs\n") == 0){
            incrementar_numero_de_comandos(e);

            imprimir_movs(e);

        }

       if (sscanf(linha, "pos %[0-32]\n", pos) == 1){
           incrementar_numero_de_comandos(e);

           jogadas_anteriores(e, *pos - '0');
           //imprimir_tabuleiro(e);
           mostrar_tabuleiro(e, -1);
        }




        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            incrementar_numero_de_comandos(e);

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
