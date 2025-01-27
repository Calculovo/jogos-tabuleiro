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
    //! Recebe o comando correspondente ao jogo e dois ponteiros de jogadores, criando um spart pointer para o jogo selecionado.
        unique_ptr<JogoBase> jogo;
        Jogador* jogador1;
        Jogador* jogador2;
        char comandoJogo;
    public:
    //! Construtor da partida. Cria o jogo selecionado com os jogadores passados no construtor.
        Partida(char comandoJogo, Jogador* jogador1, Jogador* jogador2);
    //! Imprime o tabuleiro e troca os turnos até que uma condição de vitória para o jogo seja alcançada.
        void jogar();
};

#endif