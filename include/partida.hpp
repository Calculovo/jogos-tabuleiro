#ifndef PARTIDA_I
#define PARTIDA_I 

#include "jogobase.hpp"
#include <memory>
#include "damas.hpp"
#include "jogodavelha.hpp"
#include "ligue4.hpp"
#include "reversi.hpp"
#include "raposaeovelhas.hpp"
#include "jogador.hpp"

class Partida {
    private:
        unique_ptr<JogoBase> jogo;
        Jogador* jogador1;
        Jogador* jogador2;
        char comandoJogo;
    public:
        Partida(char comandoJogo, Jogador* jogador1, Jogador* jogador2);
        void jogar();
};

#endif