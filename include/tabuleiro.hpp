#ifndef TABULEIRO_I
#define TABULEIRO_I 1

#include <map>
typedef std::map<char, char> Legenda;

#define PLAYER_1 1
#define PLAYER_2 -1

class Tabuleiro {
    private:
        int t_largura;
        int t_altura;
        char* t_matriz;
        Legenda* t_legenda;
    public:
        Tabuleiro(int largura, int altura);
        ~Tabuleiro();
        void imprimirTabuleiro();
        bool colocarPeca(int x, int y, char peca);
        char lerPeca(int x, int y);
        void adicionarLegenda(char chave, char valor);
};

#endif