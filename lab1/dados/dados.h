/**
 @file dados.h
 Definição do estado e das funções que o manipulam
 */


#ifndef LAB1_DADOS_H
#define LAB1_DADOS_H

#endif //LAB1_DADOS_H

#define LINE_SIZE 8

/**
 * @brief Tipos de dados para casas.
 *
 * Branca corresponde ao '*' .
 * Preta corresponde ao '#' .
 * Vazio corresponde '.' .
 */
typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;


/**
 * @brief Tipos de dados para coordenada
 *
 * a coordenada é constituída por um inteiro que corresponde à linha e um inteiro que corresponde à coluna.
 */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;


/**
 * @brief Tipos de dados para a  jogada
 *
 *  coordenada do jogador1
 *  coordenada do jogador2
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;


/**
 * @brief Tipos de dados para as  jogadas
 *
 */
typedef JOGADA JOGADAS[32];


/**
 * @brief Tipos de dados para casa
 *
 *  coordenada do jogador1
 *  coordenada do jogador2
 */
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int num_jogadas_totais;
    int num_jogadas_jogador1;
    int num_jogadas_jogador2;
    int jogador_atual;
    int num_comandos;
} ESTADO;


/**
* @brief Função que apresenta a inicialização do estado.
*
* Com esta função observamos  que é o jogador 1 que começa a jogar,  iniciando o tabuleiro com 0 jogadas, pois ele é o primeiro a jogar.
* A coordenada incial do estado branca vai ser alterada, pois o jogo vai começar, ou seja o tabuleiro vai inicializar.
* @return  O estado.
*/
ESTADO *inicializar_estado();


/**
* @brief Função que muda o estado.
*
* @param  Estado  Esta funçao recebe um Estado ( Branco ou  Preta).
* @param  Coordenada Esta funçao recebe uma cordenada ( linha e coluna).
* Esta função é contituída por uma coordenada, onde está a última jogada com o Estado branca.
* Quando fazemos uma nova jogada, essa coordenada fica com o Estado branca e a última jogada passa ao estado preta.
* Sempre que fazemos que nova joagda o número de jogadas aumenta 1.
* Se o jogador atual for o jogador1,  o seu  número de jogada aumenta 1 e o seguinte jogador será o jogador2.
* Se o jogador atual for o jogador2,  o seu  número de jogada aumenta 1 e o seguinte jogador será o jogador1.
* @return  O novo estado.
*/
int mudar_estado(ESTADO *e, COORDENADA c);


int obter_jogador_atual(ESTADO *estado);


int obter_numero_de_jogadas(ESTADO *estado);


int obter_numero_de_jogadas_do_jogador_atual(ESTADO *estado);


int obter_numero_de_comandos(ESTADO *estado);

void incrementar_numero_de_comandos(ESTADO *estado);

int retomar_tabuleiro_na_jogada(ESTADO *e, int x);

int testa_livre(ESTADO *e, int linha, int coluna);
