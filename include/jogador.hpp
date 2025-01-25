#ifndef JOGADOR_I
#define JOGADOR 1

#define cREVERSI 'R'
#define cLIG4 'L'
#define cVELHA 'V'
#define cDAMAS 'D'
#define cRAPOSA 'O'

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
        string nome;
        string apelido;
        int resultados[N_DE_JOGOS][N_DE_RESULTADOS];
    public:
        Jogador(string nome, string apelido);
        Jogador(string nome, string apelido, int valores[5][3]);
        void addResultados(char jogo, int resultado);

        int getResultados(char jogo, int resultado) const;
        void imprimir() const;
        string getNome() const;
        string getApelido() const;
};

#endif