#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

#include "tabuleiro.hpp"
#include <string>
#define VALID_PLAY 100
#define LOGIC_ERROR 101
#define SYNTAX_ERROR 102

class JogoBase {
    protected:
        Tabuleiro* tabuleiro;
        char turno;
    public:
        JogoBase(int largura, int altura);
        JogoBase(int tamanho);
        ~JogoBase();
        int getLargura(); //obvio
        int getAltura(); //obvio
        char getTurno(); //o Jogobase tem uma variavel que conta de quem eh a vez
        char switchTurno(); //alterna a vez entre Jogador 1 e Jogador 2
        void virtual imprimirTabuleiro(); //obvio
        char virtual validarJogada(std::string input) = 0; //input eh o que deve ser lido do terminal, output eh um valor que explica se a jogada eh valida (use o jogo da velha como exemplo)
        int virtual testarVitoria() = 0; //obvio eu espero
};

#endif