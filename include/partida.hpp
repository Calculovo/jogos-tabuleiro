#ifndef PARTIDA_I
#define PARTIDA_I 1

#include "jogobase.hpp"
#include "jogador.hpp"

class Partida {
    private:
        JogoBase* jogo;
        Jogador* jogador1;
        Jogador* jogador2;
    public:
        Partida();
        void jogar();
};

#endif