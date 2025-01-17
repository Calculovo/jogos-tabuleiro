#ifndef PARTIDA_I
#define PARTIDA_I 1

#include "jogobase.hpp"
#include "jogador.hpp"

class Partida {
    private:
        //! Ponteiro para o jogo.
        JogoBase* jogo;
        //! Ponteiro para o primeiro jogador.
        Jogador* jogador1;
        //! Ponteiro para o segundo jogador.
        Jogador* jogador2;
    public:
        //! Inicializa uma partida.
        Partida();
        //! ???
        void jogar();
};

#endif