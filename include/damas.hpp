#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "jogobase.hpp"

//! Classe responsável pela execução do jogo de damas.
//! A classe Damas herda de JogoBase e define as regras e a lógica do jogo Damas.

class Damas : public JogoBase {
    public:
        //! Construtor padrão do Reversi, inicializa o tabuleiro com as peças iniciais e define o primeiro turno.
        Damas();

        //! Realiza o movimento e a captura de peças da damas em caso de uma jogada válida.
        /*! 
            Esse método calcula a coordenada de captura a partir das coordenadas de origem e destino lidas.
            Além disso, passa o turno para o próximo jogador.
        */
        void realizarMovimento(Coord origem, Coord destino,char peca);

        //! Verifica se as coordenadas passadas pelo jogador resultam em uma jogada válida.
        /*! 
            O método trata as diferentes possibilidades de entradas que resultam em uma jogada inválida e retorna uma mensagem de erro em caso de erro.
            Em caso de uma jogada válida, ele chama o método realizar movimento.
        */
        char validarJogada(std::string input) override;

        //! Verifica se a condição de vitória do jogo foi alcançada.
        /*! 
            Esse método bruta o tabuleiro inteiro em busca de peças de cada jogador.
            Caso algum jogador tenha 0 peças sobrando, o outro jogador vence.
            Caso o jogo esteja trancado, é considerado um empate.
        */
        int testarVitoria() override;

       //! Verifica se o jogo está trancado fazendo uso do método que verifica se há movimentos válidos.
        bool jogoTrancado();

        //! Verifica se uma peça no tabuleiro tem uma direção válida de captura.
        /*! 
            Este método percorre todas as diagonais possíveis em busca de possíveis capturas para verificar se há peças do oponente que podem ser capturadas.
            Cria-se uma matriz de direções que é percorrida para tentar encontrar peças que podem ser capturadas.
            Retorna true se houver uma direção válida para capturar peças, caso contrário, false.
            Generaliza-se que uma peça coroa sempre tem uma jogada válida, pois um cenário onde não tem é extremamente improvável.
        */
        bool temMovimentosValidos(Coord posicao, char peca);
};

#endif