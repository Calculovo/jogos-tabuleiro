#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

#include "tabuleiro.hpp"

class JogoBase {
    private:
        int largura;
        int altura;
        Tabuleiro* tabuleiro;
    public:
        JogoBase(int largura, int altura);
        ~JogoBase();
        void imprimirTabuleiro();
        bool lerJogada();
        bool validarJogada();
        int testarVitoria();
};

#endif