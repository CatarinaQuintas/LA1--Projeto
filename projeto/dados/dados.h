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
 * @brief Tipos de dados para coordenada.
 *
 * a coordenada é constituída por um inteiro que corresponde à linha e um inteiro que corresponde à coluna.
 */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;


/**
 * @brief Tipos de dados para a  jogada.
 *
 *  coordenada do jogador1.
 *  coordenada do jogador2.
 */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;


/**
 * @brief Tipos de dados para as  jogadas.
 *
 */
typedef JOGADA JOGADAS[32];


/**
 * @brief Tipos de dados para estado.
 *
 *  coordenada do jogador1.
 *  coordenada do jogador2.
 *  número de jogadas.
 *  número de jogadas totais.
 *  número de jogadas jogador1.
 *  número de jogadas jogador 2.
 *  jogador atual.
 *  número de comandos.
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
* Sempre que fazemos que nova jogada o número de jogadas aumenta 1.
* Se o jogador atual for o jogador1,  o seu  número de jogada aumenta 1 e o seguinte jogador será o jogador2.
* Se o jogador atual for o jogador2,  o seu  número de jogada aumenta 1 e o seguinte jogador será o jogador1.
* @return  O novo estado.
*/
int mudar_estado(ESTADO *e, COORDENADA c);

/**
 *@brief Função que obtem o jogador atual.
 *
 * @param Estado  Esta funçao recebe um Estado.
 *
 * Esta funçao  é contituida por um estado.
 * Se o jogador atual  é o jogador1, returna 1.Se o jogador atual  é o jogador2, returna 2.
 * @return um inteiro
 */
int obter_jogador_atual(ESTADO *estado);

/**
 *@brief Função que obtem o número de jogadas.
 *
 *@param  Estado  Esta funçao recebe um Estado.
 *
 * Esta função  é contituida por um estado.
 * Apos cada jogador ter jogado uma vez, o numero de jogadas aumenta  1.
 * @return um inteiro
 */
int obter_numero_de_jogadas(ESTADO *estado);

/**
 *@brief Função que obtem o número de jogadas do jogador atual.
 *
 *@param  Estado  Esta funçao recebe um Estado.
 *
 * Esta função  é contituida por um estado.
 * Cada vez que um jogador joga, o número de jogadas  por jogador aumenta 1.
 * @return um inteiro.
 */
int obter_numero_de_jogadas_do_jogador_atual(ESTADO *estado);

/**
 *@brief Função que obtem o número de comandos.
 *
 *@param  Estado  Esta funçao recebe um Estado
 *
 * Esta função  é contituída por um estado.
 * A Finalidade é a contabilização de comandos utilizados durante o jogo.
 * @return um inteiro.
 */
int obter_numero_de_comandos(ESTADO *estado);

/**
 *@brief Função que incrementa o numero de comandos.
 *
 *@param  Estado  Esta funçao recebe um Estado.
 *
 * Esta função  é contituida por um estado.
 * Cada vez que um comando é utilizado,  o numero de comandos aumenta 1.
 * @return um inteiro.
 */
void incrementar_numero_de_comandos(ESTADO *estado);

/**
 *@brief Função que retoma o tabuleiro numa jogada.
 *
 *@param Estado  Esta funçao recebe um Estado.
 *@param Estado Esta funçao recebe um inteiro.
 *A finalidade desta função é poder voltar trás no jogo e recomeçar o jogo a partir jogada  pretendida.
 * @return um inteiro.
 */
int retomar_tabuleiro_na_jogada(ESTADO *e, int x);

/**
 *@brief Funão que testa uma casa livre.
 *
 *@param Estado  Esta funçao recebe um Estado.
 *@param Estado Esta funçao recebe uma linha.
 *@param Estado Esta funçao recebe uma coluna
 *
 * A função testa livre verifica qual e o estado de uma casa, se a mesma estiver VAZIO; 1 ou 2, é considerada como livre.
 *@return um inteiro.
 */
int testa_livre(ESTADO *e, int linha, int coluna);
