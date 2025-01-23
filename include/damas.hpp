#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogobase.hpp"

class Damas : public JogoBase {
    public:
        Damas();
        void realizarMovimento(Coord origem, Coord destino,char peca);
        char validarJogada(std::string input) override;
        int testarVitoria() override;
        bool jogoTrancado();
        bool temMovimentosValidos(Coord posicao, char peca);
};

#endif