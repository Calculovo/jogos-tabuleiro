#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogobase.hpp"

class Damas : public JogoBase {
    public:
        Damas();
        void realizarMovimento(std::string input);
        char validarJogada(std::string input) override;
        int testarVitoria() override;
};

#endif