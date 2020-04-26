#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <time.h>


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
    if (estado->tab[0][0] == BRANCA) {
        return 1;
    } else if (estado->tab[7][7] == BRANCA){
        return 2;
    } else if (coordenadas_vizinhas_livres(estado) == NULL) {
        return 2/estado->jogador_atual;
    }
    else{
          return -1;
    }
}

int imprimir_tabuleiro (ESTADO *estado, char* file_name) {
    FILE *fp;

    fp = fopen(file_name, "w");

    for(int i=LINE_SIZE-1; i >= 0; i--) {
        for(int j=0; j < LINE_SIZE; j++) {
           if (i==7 && j==7) {
                fputs("2", fp);
            }
            else if (i==0 && j==0) {
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

    fputs("\n", fp);
    int num_jogadas = obter_numero_de_jogadas(estado);

    for (int i = 0; i<=num_jogadas; i++){

        JOGADA jogada = estado->jogadas[i];


        if (i != num_jogadas || estado->jogador_atual == 2) {
            fprintf(fp, "%02d: ", i + 1);
            fprintf(fp, "%c%c ", jogada.jogador1.coluna + 'a', jogada.jogador1.linha + '1');

        }
        if ( i != num_jogadas ) {
            fprintf(fp, "%c%c ",jogada.jogador2.coluna + 'a', jogada.jogador2.linha + '1');
        }


        if (i != num_jogadas || estado->jogador_atual == 2) {
            fputs("\n",fp);
        }
    }

    fclose(fp);

    return 1;
}

void lerTabuleiro (ESTADO *estado, char* file_name) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file;
    file = fopen(file_name, "r");
    int q = 7;
    if (file) {
        for ( int j= 0; j < LINE_SIZE; j++){
            if ((read = getline(&line, &len, file)) != -1){

                for (int i = 0; i < (int) len; i++) {
                    if (line[i] == '.') {
                        estado->tab[q][i] = VAZIO;
                    } else if (line[i] == '*') {
                        estado->tab[q][i] = BRANCA;

                        COORDENADA coord = {i, q};
                        estado->ultima_jogada = coord;
                    } else if (line[i] == '#') {
                        estado->tab[q][i] = PRETA;
                    } else if (line[i] == '2') {
                        estado->tab[q][i] = DOIS;
                    } else if (line[i] == '1') {
                        estado->tab[q][i] = UM;
                    }
                }
                q = q - 1;
            }
        }

        if((read = getline(&line, &len, file)) != -1 && strcmp(line, "\n") == 0){
            estado->num_jogadas_jogador1 = 1;
            estado->num_jogadas_jogador2 = 1;
            estado->num_jogadas = 0;
            estado->num_jogadas_totais = 0;
            estado->jogador_atual = 1;

            while((read = getline(&line, &len, file)) != -1 && strcmp(line, "\n") != 0){

                int nr_jogada;
                sscanf(line, "%02d: ", &nr_jogada);

                JOGADA *jogada = &(estado->jogadas[nr_jogada - 1]);

                char col[2], lin[2];
                if (sscanf(line + 4, "%[a-h]%[1-8]", col, lin ) == 2){
                    jogada->jogador1.coluna = *col - 'a';
                    jogada->jogador1.linha = *lin - '1';

                    estado->num_jogadas_jogador1++;
                    estado->jogador_atual = 2;
                }


                if (sscanf(line + 7, " %[a-h]%[1-8]",col, lin) == 2){
                    jogada->jogador2.coluna = *col - 'a';
                    jogada->jogador2.linha = *lin - '1';

                    estado->num_jogadas_jogador2++;
                    estado->num_jogadas++;
                    estado->num_jogadas_totais++;
                    estado->jogador_atual = 1;
                }

            }
        }

        fclose(file);
    }
}



LISTA adiciona_coordenada_lista(LISTA L, int linha, int coluna){
    COORDENADA * c =  malloc(sizeof(COORDENADA));
    c->linha = linha;
    c->coluna = coluna;
    return insere_cabeca(L, c);
}

LISTA coordenadas_vizinhas_livres(ESTADO *e){
    COORDENADA c = e->ultima_jogada;

    LISTA l = criar_lista();

    if(c.coluna - 1 >= 0){
        if (testa_livre(e, c.linha, c.coluna-1)){
            l = adiciona_coordenada_lista(l, c.linha, c.coluna-1);
        }

        if (c.linha -1 >= 0){
            if (testa_livre(e, c.linha-1, c.coluna-1)){
                l = adiciona_coordenada_lista(l, c.linha-1, c.coluna-1);
            }
        }

        if (c.linha + 1 <= 7){
            if (testa_livre(e, c.linha +1, c.coluna-1)){
                l = adiciona_coordenada_lista(l, c.linha+1, c.coluna-1);
            }
        }
    }

    if(c.coluna + 1 <=7){
        if (testa_livre(e, c.linha, c.coluna+1)){
            l = adiciona_coordenada_lista(l, c.linha, c.coluna+1);
        }

        if (c.linha - 1 >= 0){
            if (testa_livre(e, c.linha-1, c.coluna+1)){
                l = adiciona_coordenada_lista(l, c.linha-1, c.coluna+1);
            }
        }

        if (c.linha + 1 <= 7){
            if (testa_livre(e, c.linha+1, c.coluna+1)){
                l = adiciona_coordenada_lista(l, c.linha+1, c.coluna+1);
            }
        }
    }

    if (c.linha +1 <=7){
        if (testa_livre(e, c.linha +1, c.coluna)){
            l = adiciona_coordenada_lista(l, c.linha+1, c.coluna);
        }
    }

    if (c.linha -1 >=0){
        if (testa_livre(e, c.linha-1, c.coluna)){
            l = adiciona_coordenada_lista(l, c.linha-1, c.coluna);
        }
    }


    return l;
}

int distancia_coordenadas(COORDENADA c1, COORDENADA c2){
    int dist1 = (c1.coluna-c2.coluna);
    int dist2 = (c1.linha-c2.linha);
    int dist = dist1 * dist1 + dist2 * dist2;
    return dist;
}

void jogar_euclidiana(ESTADO *e){

    COORDENADA alvo;
    int i = obter_jogador_atual(e);
    if (i == 1){
         alvo = (COORDENADA) {0,0};
    }
    else {
         alvo  = (COORDENADA) {7,7};
    }

    LISTA L = coordenadas_vizinhas_livres(e);


    if (L != NULL) {
        COORDENADA *cabeca = devolve_cabeca(L);

        COORDENADA min_coordenada = {cabeca->coluna, cabeca->linha};

        int min_distancia = distancia_coordenadas(alvo, min_coordenada);

        free(cabeca);


        for(LISTA T = remove_cabeca(L); !lista_esta_vazia(T); T = remove_cabeca(T)) {
             cabeca = (COORDENADA*) devolve_cabeca(T);

            int distancia = distancia_coordenadas(alvo, *cabeca);


            if (distancia < min_distancia) {
                min_coordenada = (COORDENADA){cabeca->coluna, cabeca->linha};
                min_distancia = distancia;
            }

            free(cabeca);
        }

        jogar(e, min_coordenada);
    }

}

void jogar_aleatorio(ESTADO *e){
    LISTA L = coordenadas_vizinhas_livres(e);

    int comprimento = 0;

    for(LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        comprimento ++;
    }

    time_t t;
    srand((unsigned) time(&t));

    int escolha = rand() % comprimento;

    int percorrido = 0;
    for(LISTA T = L; !lista_esta_vazia(T); T = remove_cabeca(T)) {
        COORDENADA* cabeca = devolve_cabeca(T);

        if (escolha == percorrido){
            COORDENADA c = {cabeca->coluna, cabeca->linha};
            jogar(e, c);

        }

        free(cabeca);



        percorrido ++;
    }
}
