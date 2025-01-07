#ifndef JOGO_DA_VELHA_I
#define JOGO_DA_VELHA_I 1

#include "jogobase.hpp"

class JogoDaVelha : public JogoBase {
    public:
        JogoDaVelha();
        JogoDaVelha(int tamanho);
        char validarJogada(std::string input) override;
        int testarVitoria() override;
};

#endif