#ifndef PLACAR_I
#define PLACAR_I

#include "jogador.hpp"
#include <list>
#include <string>

class Placar {
    private:
        std::list<Jogador> jogadores;
    public:
        Placar();
        ~Placar();
        void escreverArquivo() const;
        void adicionarJogador(std::string apelido, std::string nome);
        void removerJogador(std::string apelido);
        void listarJogadores(char modo);
};

#endif