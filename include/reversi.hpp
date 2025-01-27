#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "jogobase.hpp"


//! Classe responsável pela implementação do jogo Reversi. 
//! A classe Reversi herda de JogoBase e define as regras e a lógica do jogo Reversi.

class Reversi : public JogoBase {
    public:
        //! Construtor padrão do Reversi, inicializa o tabuleiro com as peças iniciais e define o primeiro turno.
        Reversi();

        //! Verifica se uma coordenada no tabuleiro tem uma direção válida de captura de peças.
        /*! 
            Este método percorre todas as direções possíveis (horizontal, vertical, diagonal) 
            para verificar se há peças do oponente que podem ser capturadas.
            cria-se uma matriz de direções que é percorrida para tentar encontrar linhas que serão capturadas
            retorna true se houver uma direção válida para capturar peças, caso contrário, false.
        */
        bool conferirDirecoes(Coord coord);

        //! Verifica se o jogo ainda tem jogadas válidas para qualquer jogador.
        /*! 
            Esse método verifica se ainda existem jogadas válidas disponíveis no tabuleiro.
            retorna VALID_PLAY se ainda existir uma jogada legal ou INVALID caso contrário.
        */
        char existeJogadaLegal();

        //! Verifica se existe alguma jogada legal disponível para o jogador atual.
        /*!
            Esse método percorre o tabuleiro e verifica se há alguma posição vazia onde o jogador pode
            realizar uma jogada legal, ou seja, se existe alguma peça do oponente que possa ser virada.
            Se a string não possui tamanho 2, imprime uma mensagem
            e retorna SYNTAX_ERROR.
            Se a string está no formato correto, mas aponta pra uma célula inexistente 
            no tabuleiro ou aponta para uma célula já ocupada do tabuleiro, retorna LOGIC_ERROR.
            Se a string está no formato correto e apponta para uma célula vazia,
            chama o método conferiDireções e retorna VALID_PLAY em caso de existir 
            uma jogada legal ou INVALID caso contrário.
        */
        char checarJogadaLegal(std::string input);
        
        //! Valida a jogada do jogador atual.
        /*!
            Recebe o input de onde o jogador deseja colocar uma peça.
            Esse método verifica se a jogada inserida pelo jogador é válida, e se for,
            coloca a peça no tabuleiro, inverte as peças do oponente e alterna o turno.
            Se não existem mais jogadas válidas, imprime uma mensagem
            e retorna INVALID.
            Se a jogada é válida realiza ela e retorna VALID_PLAY.
            Caso contrário, imprime uma mensagem para digitar uma coordenada
            válida e retorna INVALID.
        */
        char validarJogada(std::string input)override;

        //! Verifica so resultado do jogo.
        /*!
            Esse método conta as peças de cada jogador no tabuleiro e determina 
            se o jogo acabou, indicando o vencedor ou se houve empate.
            Testa se ainda há jogadas legais, caso positivo, o jogo
            ainda não acabou e retorna INDEFINIDO.
            Caso não há mais jogadas legais, conta as peças do tabuleiro
            e imprime as quantidades.
            Retorna o jogador vencedor ou EMPATE se houver empate.
        */
        int testarVitoria() override;

        //! Inverte as peças do oponente após uma jogada válida.
        /*!
            Recebe a coordenada onde a jogada foi realizada e 
            checa as direções onde as peças precisam ser invertidas.
            Após uma jogada válida, o método inverte todas as peças do 
            oponente nas direções que são capturadas pela jogada do jogador atual.
        */
        void inverterPecas(Coord coord);
};

#endif //REVERSI_HPP