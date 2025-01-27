#ifndef JOGADOR_I
#define JOGADOR_I

//!  Definição da classe Jogador, que gerencia o nome, apelido e os resultados de partidas de um jogador.
/*!
    Essa classe permite registrar e consultar resultados de diferentes jogos, 
    como Reversi, Lig4, Velha, Damas e Raposa.
*/

//! Define cada jogo com um identificador, nesse caso um char, correspondente.
#define cREVERSI 'R'
#define cLIG4 'L'
#define cVELHA 'V'
#define cDAMAS 'D'
#define cRAPOSA 'O'

//! Define cada jogo com um índice, nesse caso um int, correspondente.
#define REVERSI 0
#define LIG4 1
#define VELHA 2
#define DAMAS 3
#define RAPOSA 4
//! Define a quantidade de jogos registrados no sistema.
#define N_DE_JOGOS 5

//! Define o índice que representa cada resultado possível.
#define VITORIA_INDICE 0
#define EMPATE_INDICE 1
#define DERROTA_INDICE 2

//! Define a quantidade de resultados possíveis para cada jogo.
#define N_DE_RESULTADOS 3

#include <string>

using namespace std;

//! Classe que define o jogador
/*! Representa um jogador com nome, apelido e os resultados de suas partidas, 
    permite armazenar esses atributos, registrar os resultados de seus jogos e exibir esses resultados.
*/

class Jogador {
    private:
        //! Nome completo do jogador.
        string nome;
        //! Apelido do jogador.
        string apelido;
        //! Matriz que armazena o número de vitórias, empates e derrotas para cada jogo.
        int resultados[N_DE_JOGOS][N_DE_RESULTADOS];
    public:

        //! Construtor da classe jogador.
        /*!
            Recebe o nome e o apelido do jogador.
            Inicializa o nome e apelido do jogador, e inicializa a matriz 
            de resultados com 0 para todas as posições.
        */
        Jogador(string nome, string apelido);

        //! Construtor da classe Jogador com resultados passados.
        /*!
            Recebe o nome, o apelido e a matriz de resultados prévios do jogador.
            Inicializa o nome e apelido do jogador, e inicializa a matriz 
            de resultados com os valores fornecidos.
        */
        Jogador(string nome, string apelido, int valores[5][3]);

        //! Altera a matriz de resultados do jogador para algum jogo específico.
        /*!
            Recebe um char que representa um jogo e um inteiro que representa o resultado.
            Transforma o char do jogo em um int correspondente e utiliza esse valor e o valor do 
            resultado para adicionar 1 na posição correspondente da matriz.
        */
        void addResultados(char jogo, int resultado);


        //! Informa os resultados para um jogo específico.
        /*!
            Recebe um int correspondente ao jogo e um int correspondente ao resultado
            A função get retorna a quantidade de um tipo específico de resultado 
            (Vitória, Empate, Derrota) para um jogo específico.
            Retorna um int correspondente ao número de resultados.
        */
        int getResultados(int jogo, int resultado) const;

        //! Imprime as informações do jogador, incluindo nome, apelido e resultados.
        /*! 
            Exibe o nome e apelido do jogador, bem como os "stats", ou resultados de 
            cada jogo (Vitórias, Empates e Derrotas).
        */
        void imprimir() const;

        //! Informa/Retorna o nome completo do jogador.
        string getNome() const;

        //! Informa/Retorna o apelido do jogador.
        string getApelido() const;
};

#endif