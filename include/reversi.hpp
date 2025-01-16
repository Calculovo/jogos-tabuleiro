#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogobase.hpp"

using namespace std;

class Reversi : public JogoBase {
    public:
        Reversi();
        void colocarPeca(string input);
        char existeJogadaLegal();
        char validarJogada(string input) override;
        int testarVitoria() override;
};

#endif