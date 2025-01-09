#ifndef TABULEIRO_I
#define TABULEIRO_I 1

#include <string>

#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define VAZIO ' '
#define EMPATE 0
#define INDEFINIDO -64
#define INVALID -128

class Coord {
    private:
        int x;
        int y;
    public:
        Coord(int x, int y);
        Coord(std::string entrada); //traduz strings como A1 ou C3 para coords
        int getX();
        int getY();
        Coord operator +(Coord p);
        Coord operator *(int p);
};

class Tabuleiro {
    private:
        int t_largura;
        int t_altura;
        char* t_matriz;
    public:
        Tabuleiro(Coord coord);
        ~Tabuleiro();
        int getLargura(); //obvio
        int getAltura(); //obvio
        bool posicaoValida(Coord coord); //verifica se a coordenada esta dentro do tabuleiro
        bool colocarPeca(Coord coord, char peca); //obvio
        char lerPeca(Coord coord); //obvio
        void imprimirTabuleiro(); //obvio
        //evite usar
        Tabuleiro(int largura, int altura);
        bool posicaoValida(int x, int y);
        bool colocarPeca(int x, int y, char peca);
        char lerPeca(int x, int y);
};

#endif