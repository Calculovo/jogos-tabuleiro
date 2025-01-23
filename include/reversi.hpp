#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogobase.hpp"

class Reversi : public JogoBase {
    public:
        Reversi();
        bool conferirDirecoes(Coord coord);
        char validarJogada(std::string input) override;
        char existeJogadaLegal();
        void colocarPeca(std::string input);
        int testarVitoria() override;
        void inverterPecas(Coord coord);
};

#endif