#ifndef RAPOSA_E_OVELHAS
#define RAPOSA_E_OVELHAS

#include "jogobase.hpp"

class RaposaeOvelhas : public JogoBase {
    public:
        RaposaeOvelhas();
        char validarJogada(std::string input) override;
        int testarVitoria() override;
        void imprimirTabuleiro() override;
    private:
        char realizarJogada(Coord origem, Coord destino);
        bool moverRaposa(Coord origem, Coord destino);
        bool moverOvelha(Coord origem, Coord destino);
        bool movimentoValido(Coord origem, Coord destino);
};
#endif