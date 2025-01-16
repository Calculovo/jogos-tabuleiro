#ifndef JOGADOR_I
#define JOGADOR 1

#include <string>
#include <vector>

using namespace std;

class Jogador {
    private:
        string nome;
        string apelido;
        int resultados[3][5];
    public:
        Jogador(string nome, string apelido);
        bool operator < (Jogador outro);
        int AddResultados(int jogo, int resultado);
        
        int GetResultados() const;
};

#endif