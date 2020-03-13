#include <stdio.h>
#include "interface/interface.h"

int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    interpretador(e);
    return 0;
}
