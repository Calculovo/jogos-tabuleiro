#ifndef JOGADOR_I
#define JOGADOR 1

#define REVERSI 0
#define LIG4 1
#define VELHA 2
#define DAMAS 3
#define RAPOSA 4
#define N_DE_JOGOS 5

#define VITORIA_INDICE 0
#define EMPATE_INDICE 1
#define DERROTA_INDICE 2
#define N_DE_RESULTADOS 3

#include <string>

using namespace std;

class Jogador {
    private:
        //! Visualmente reconhece um jogador.
        string nome;
        //! Identifica unicamente um jogador. Não pode ser repetido.
        string apelido;
        //! Armazena vitorias, empates e derrotas em cada um dos cinco jogos.
        int resultados[N_DE_JOGOS][N_DE_RESULTADOS];
    public:
        //! Construtor básico, que inicializa as estatísticas para zero.
        Jogador(string nome, string apelido);
        //! Construtor mais complexo, que inicializa as estatísticas para outros valores.
        Jogador(string nome, string apelido, int valores[5][3]);
        //! Adiciona uma vitória, empate, ou derrota em um jogo.
        int addResultados(int jogo, int resultado);
        //! Retorna o número de vitórias, empates, ou derrotas em um jogo.
        int getResultados(int jogo, int resultado) const;
        //! Imprime para o cout as informações do jogador.
        void imprimir() const;
        //! Retorna o nome do jogador.
        string getNome() const;
        //! Retorna o apelido do jogador.
        string getApelido() const;
};

#endif