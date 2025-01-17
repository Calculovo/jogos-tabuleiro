#ifndef RAPOSA_E_OVELHAS
#define RAPOSA_E_OVELHAS

#include "jogobase.hpp"

class RaposaeOvelhas : public JogoBase {
    public:
        //! Construtor.
        RaposaeOvelhas();
        char validarJogada(std::string input) override;
        int testarVitoria() override;
        void imprimirTabuleiro() override;
    private:
        //! Move a raposa da origem para o destino.
        bool moverRaposa(Coord origem, Coord destino);
        //! Move uma ovelha da origem para o destino.
        bool moverOvelha(Coord origem, Coord destino);
        //! Verifica se um movimento da origem para o destino é válido.
        bool movimentoValido(Coord origem, Coord destino);
};
#endif