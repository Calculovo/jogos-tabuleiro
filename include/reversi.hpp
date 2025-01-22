#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogobase.hpp"

using namespace std;

class Reversi : public JogoBase {
    public:
        Reversi();
        char validarJogada(string input) override;
        char existeJogadaLegal();
        void colocarPeca(string input);
        int testarVitoria() override;
        void inverterPecas(Coord coord);
};

#endif