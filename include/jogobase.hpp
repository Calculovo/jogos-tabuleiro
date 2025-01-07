#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

#include "tabuleiro.hpp"
#include <string>
#define VALID_PLAY 100
#define LOGIC_ERROR 101
#define SYNTAX_ERROR 102

class JogoBase {
    protected:
        int largura;
        int altura;
        Tabuleiro* tabuleiro;
        char turno;
    public:
        JogoBase(int largura, int altura);
        JogoBase(int tamanho);
        ~JogoBase();
        char getTurno();
        char switchTurno();
        void virtual imprimirTabuleiro();
        char virtual validarJogada(std::string input) = 0;
        int virtual testarVitoria() = 0;
};

#endif