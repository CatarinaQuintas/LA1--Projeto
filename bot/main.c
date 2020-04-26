#include "interface/interface.h"


int main(int argc, char** argv) {
    ESTADO *e = inicializar_estado();

    if (argc == 3){
        lerTabuleiro(e, argv[1]);

        fazer_jogada_euclidiana(e);

        imprimir_tabuleiro(e, argv[2]);
    }

    return 0;
}
