#ifndef JOGADOR_I
#define JOGADOR 1

#include <string>
#include <vector>

class Jogador {
    private:
        std::string nome;
        std::string apelido;
        int vitorias;
    public:
        Jogador(std::string nome, std::string apelido);
        bool operator < (Jogador outro);
};

#endif