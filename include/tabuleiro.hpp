#ifndef TABULEIRO_I
#define TABULEIRO_I 1

#include <map>
#include <string>
typedef std::map<char, char> Legenda;

#define PLAYER_1 1
#define PLAYER_2 -1
#define VAZIO 0
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
        Legenda* t_legenda;
    public:
        Tabuleiro(Coord coord);
        ~Tabuleiro();
        int getLargura(); //obvio
        int getAltura(); //obvio
        bool posicaoValida(Coord coord); //verifica se a coordenada esta dentro do tabuleiro
        bool colocarPeca(Coord coord, char peca); //obvio
        char lerPeca(Coord coord); //obvio
        char traduzir(char input); //o tabuleiro eh uma matriz de char, mas por versatilidade eu implementei uma legenda que traduz os numeros da matriz para codigos ascii
        void adicionarLegenda(char chave, char valor); //adiciona um par (numero da matriz, codigo ascii) para a legenda
        void imprimirTabuleiro(); //obvio
        //evite usar
        Tabuleiro(int largura, int altura);
        bool posicaoValida(int x, int y);
        bool colocarPeca(int x, int y, char peca);
        char lerPeca(int x, int y);
};

#endif