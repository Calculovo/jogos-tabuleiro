#ifndef TABULEIRO_I
#define TABULEIRO_I 1

#include <string>

//! Representa o primeiro jogador.
#define PLAYER_1 'X'
//! Representa o segundo jogador.
#define PLAYER_2 'O'
//! Representa uma célula vazia.
#define VAZIO ' '
//! Representa um empate em um jogo.
#define EMPATE 0
//! Representa um jogo em um estado indecisivo.
#define INDEFINIDO -64

//! Classe que representa uma coordenada no tabuleiro.
class Coord {
    private:
        //! Coordenada horizontal.
        int x;
        //! Coordenada vertical.
        int y;
    public:
        //! Constroi uma coordenada (x,y).
        Coord(int x, int y);
        //! Traduz uma string no formato "A1" para uma Coord.
        /*
            Joga std::invalid_argument se a string não está no formato.
        */
        Coord(std::string entrada);
        //! Retorna a coordenada x.
        int getX();
        //! Retorna a coordenada y.
        int getY();
        //! Implementa a soma de coordenadas.
        Coord operator +(Coord p);
        //! Implementa a diferença de coordenadas.
        Coord operator -(Coord p);
        //! Implementa a multiplicação de uma coordenada por um escalar.
        Coord operator *(float p);
        //! Implementa a divisão de uma coordenada por um escalar.
        Coord operator /(float p);
        //! Implementa a comparação entre duas coordenadas.
        bool operator ==(Coord p);
};

//! Classe que representa o tabuleiro de um jogo.
class Tabuleiro {
    private:
        //! Largura do tabuleiro.
        int t_largura;
        //! Altura do tabuleiro.
        int t_altura;
        //! Ponteiro para uma matriz de char que representa os conteúdos do tabuleiro.
        char* t_matriz;
        //! Imprime uma linha horizontal da largura do tabuleiro.
        void linhaHorizontal();
    public:
        //! Cria um tabuleiro com altura e largura especificadas por uma coordenada.
        /*!
            Tabuleiros são criados inicialmente com todas as células iguais a VAZIO (espaço). 
        */
        Tabuleiro(Coord coord);
        //! Destroi um tabuleiro.
        /*!
            Regra de Três sugere que um contrutor de cópia e uma sobrecarga de atribuição,
            mas essas funções nunca são feitas com um tabuleiro, então não foram implementadas.
        */
        ~Tabuleiro();
        //! Retorna a largura do tabuleiro.
        int getLargura();
        //! Retorna a altura do tabuleiro.
        int getAltura();
        //! Verifica se uma coordenada está dentro do tabuleiro.
        bool posicaoValida(Coord coord);
        //! Coloca uma peça em uma coordenada dada.
        /*!
            Retorna true se a peça foi colocada com sucesso,
            retorna false se a peça já estava na posição,
            e joga std::out_of_range se a coordenada dada não está no tabuleiro.
        */
        bool colocarPeca(Coord coord, char peca);
        //! Retorna a peça atualmente na coordenada dada.
        /*!
            Se a coordenada dada não está no tabuleiro, joga std::out_of_range.
        */
        char lerPeca(Coord coord);
        //! Imprime o tabuleiro atual no terminal.
        void imprimirTabuleiro();

        //! Transforma um par de inteiros em Coord, e chama o outro construtor.
        Tabuleiro(int largura, int altura);
        //! Transforma um par de inteiros em Coord, e chama posiçãoValida(Coord).
        bool posicaoValida(int x, int y);
        //! Transforma um par de inteiros em Coord, e chama colocarPeca(Coord, char).
        bool colocarPeca(int x, int y, char peca);
        //! Transforma um par de inteiros em Coord, e chama lerPeca(coord).
        char lerPeca(int x, int y);
};

#endif