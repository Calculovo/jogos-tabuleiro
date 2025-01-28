#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

#include "tabuleiro.hpp"
#include <string>
//! Representa uma jogada válida.
#define VALID_PLAY 100 
//! Representa uma jogada potencialmente válida, mas no momento não permitida.
#define LOGIC_ERROR 101 
//! Representa uma jogada que não respeita a formatação de input.
#define SYNTAX_ERROR 102 

//! Classe pai para a criação de jogos.
class JogoBase {
    protected:
        //! Ponteiro para o tabuleiro do jogo.
        Tabuleiro* tabuleiro;
        //! Variável que conta qual jogador deve jogar no momento.
        char turno;
    public: 
        //! Constroi um jogo de tamanho arbitrario.
        /*!
            Constroi um jogo com um ponteiro para um tabuleiro
            com a altura e a largura especificada.
        */
        JogoBase(int largura, int altura);
        //! Constroi um jogo de tabuleiro quadrado.
        /*!
            Chama o primeiro construtor, mas usando o tamanho como altura e largura.
        */
        JogoBase(int tamanho);
        //! Destrutor de jogo.
        ~JogoBase();
        //! Retorna a largura do tabuleiro.
        int getLargura();
        //! Retorna a altura do tabuleiro.
        int getAltura();
        //! Retorna o índice do jogador que deve jogar agora.
        char getTurno();
        //! Alterna o turno de jogador 1 para jogador 2 ou vice-versa.
        char switchTurno();
        //! Exibe o tabuleiro do jogo.
        void virtual imprimirTabuleiro();
        //! Valida e executa uma jogada representada por uma string.
        /*!
            Se a string não faz sentido como uma jogada, deve retornar SYNTAX_ERROR.
            Se a string pode ser interpretada como uma jogada, mas não é uma jogada válida no momento,
            deve retornar LOGIC_ERROR.
            Do contrário, deve retornar VALID_PLAY.
        */
        char virtual validarJogada(std::string input) = 0;
        //! Verifica se um dos jogadores já atingiu a condição de vitória.
        /*!
            Se um dos jogadores já atingiu a condição de vitória, retorna
            o respectivo JOGADOR_1 ou JOGADOR_2.
            Se o jogo empatou, retorna EMPATE.
            Se nenhum jogador atingiu a condição de vitória, e o jogo ainda
            não acabou, retorna INDEFINIDO.
        */
        int virtual testarVitoria() = 0;
};

#endif