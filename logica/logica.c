#include "logica.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    mudar_estado(e,c);
    return 1;
}
