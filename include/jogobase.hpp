#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

#include "tabuleiro.hpp"
#include <string>
#define VALID_PLAY 100 //! Representa uma jogada válida.
#define LOGIC_ERROR 101 //! Representa uma jogada potencialmente válida, mas no momento não permitida.
#define SYNTAX_ERROR 102 //! Representa uma jogada que não respeita a formatação de input.

class JogoBase {
    protected:
        //! Tabuleiro no qual os jogos são jogados.
        Tabuleiro* tabuleiro;
        //! Variável que conta de quem é a vez de jogar.
        char turno;
    public:
        //! Inicializa um JogoBase com tabuleiro de altura e largura especificados.
        JogoBase(int largura, int altura);
        //! Inicializa um JogoBase com tabuleiro quadrado de lado especificado.
        JogoBase(int tamanho);
        //! Destrutor.
        ~JogoBase();
        //! Retorna a largura do tabuleiro.
        int getLargura();
        //! Retorna a altura do tabuleiro.
        int getAltura();
        //! Retorna qual jogador deve jogar neste momento. 
        char getTurno();
        //! Alterna a vez entre o Jogador 1 e o Jogador 2.
        char switchTurno();
        //! Imprime o tabuleiro no terminal.
        void virtual imprimirTabuleiro();
        //! Função virtual para validar uma string de jogada.
        /*!
            Classes filhas devem sobrescrever essa função
            para interpretar uma string como uma jogada e,
            se a jogada for válida, executá-la.
        */
        char virtual validarJogada(std::string input) = 0;
        //! Função virtual para verificar o vencedor de um jogo.
        /*!
            Classes filhas devem sobrescrever essa função
            para ler o tabuleiro e interpretar se algum dos jogadores já ganhou.
        */
        int virtual testarVitoria() = 0;
};

#endif