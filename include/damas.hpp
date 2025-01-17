#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogobase.hpp"

/*!
    Implementação do jogo de damas.
*/

class Damas : public JogoBase {
    public:
        //! Construtor.
        /*!
            Inicializa o tabuleiro com peças nas posições iniciais.
        */
        Damas();
        //! Lê um movimento em formato "A1B2", e executa o movimento.
        void realizarMovimento(std::string input); 
        //! Verifica se uma string representa um movimento válido.
        /*!
            Lê uma string. Se não estiver em formato "A1B2", retorna SYNTAX_ERROR.
            Se estiver no formato, mas o movimento for ilegal, retorna LOGIC_ERROR.
            Se estiver no formato, e o movimento for legal, retorna VALID_PLAY.
        */
        char validarJogada(std::string input) override;
        //! Verifica se um dos jogadores venceu.
        int testarVitoria() override;
};

#endif