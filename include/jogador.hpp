#ifndef JOGADOR_I
#define JOGADOR 1

#define REVERSI 0
#define LIG4 1
#define VELHA 2
#define DAMAS 3
#define RAPOSA 4

#define VITORIA_INDICE 0
#define EMPATE_INDICE 1
#define DERROTA_INDICE 2

#include <string>

using namespace std;

class Jogador {
    private:
        string nome;
        string apelido;
        int resultados[5][3];
    public:
        Jogador(string nome, string apelido);
        int AddResultados(int jogo, int resultado);
        
        int GetResultados() const;
        void imprimir() const;
        string getNome() const;
        string getApelido() const;
};

#endif