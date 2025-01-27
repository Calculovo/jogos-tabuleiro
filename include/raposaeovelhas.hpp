#ifndef RAPOSA_E_OVELHAS
#define RAPOSA_E_OVELHAS

#include "jogobase.hpp"

//! Classe responsável pela implementação do jogo Raposa e Ovelhas. 
//! A classe RaposaeOvelhas herda de JogoBase e define as regras e a lógica do jogo Raposa e Ovelhas.

class RaposaeOvelhas : public JogoBase {
    public:
        //! Construtor padrão do RaposaeOvelhas, inicializa o tabuleiro 8x8 com as peças nas posições iniciais.
        RaposaeOvelhas();

        //! Valida a jogada do jogador atual.
        /*!
            Recebe o input de onde o jogador deseja mover a peça.
            Esse método verifica se a jogada inserida pelo jogador é válida, e se for,
            move a peça para a posição dada como entrada e alterna o turno.
           
            Se a jogada não é válida por erro de sintaxe do a entrada, retorna SYNTAX_ERROR.
            Se a jogada não é válida pois o destino não é um espaço em branco, ou a origem do jogador2 não contém uma ovelha, retorna LOGIC_ERROR.
            Nesses casos, imprime uma mensagem recomendando digitar uma jogada válida.
            Se a jogada é válida até então, retorna o método RealizarJogada.
        */
        char validarJogada(std::string input) override;

        //! Verifica o resultado do jogo.
        /*!
            Checa as condições de vitória do Raposa e Ovelha.
            Se não houver mais ovelhas posicionadas nas linhas acima da raposa, o jogador 1 ganhou e o método retorna PLAYER_1;
            Se não houver mais para onde a raposa se mover, o jogador 2 ganhou e o método retorna PLAYER_2;
            Se nenhumas das condições se cumprir, retorna INDEFINIDO e o jogo continua.
        */
        int testarVitoria() override;

        //! Imprime o tabuleiro de acordo com as jogadas atuais
        void imprimirTabuleiro() override;
    private:

        //! Realiza a jogada recebendo a coordenada de origem e destino
        /*! 
            Chama o método moverRaposa, se for o turno for do jogador 1, e moverOvelha, se o turno for do jogador 2;
            Se o método chamado retornar true, retorna VALID_PLAY;
            Caso contrário, imprime uma mensagem explicando as regras de movimento e retorna LOGIC_ERROR;
        */
        char realizarJogada(Coord origem, Coord destino);

        //! Move a peça da Raposa
        /*!
            Chama o método movimentoValido;
            Se ele retornar true, realiza o movimento da raposa de acordo com as coordenadas passadas como parâmetro;
            Caso contrário, retorna false.
        */
        bool moverRaposa(Coord origem, Coord destino);

        //! Move a peça da Ovelha
        /*!
            Chama o método movimentoValido;
            Se ele retornar true e a coordenada destino estiver abaixo da de origem, realiza o movimento da ovelha de acordo com as coordenadas passadas como parâmetro;
            Caso contrário, retorna false.
        */
        bool moverOvelha(Coord origem, Coord destino);

        //! Verifica se o movimento é diagonal com um quadrado de distância, e se as coordenadas de origem e destino existem no tabuleiro;
        /*! 
            Caso positivo, retorna true;
            Ao contrário, retorna false.
        */
        bool movimentoValido(Coord origem, Coord destino);
};
#endif