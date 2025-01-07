#ifndef CADASTRO_I
#define CADASTRO 1

#include <vector>
#include "jogador.hpp"

class Cadastro {
    private:
        std::vector<Jogador> jogadores;
    public:
        bool cadastrarJogador(std::string apelido, std::string nome);
        bool removerJogador(std::string apelido);
        bool listarJogadoresApelido();
        bool listarJogadoresNome();
};

#endif