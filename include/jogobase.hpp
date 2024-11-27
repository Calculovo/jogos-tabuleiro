#ifndef JOGO_BASE_I
#define JOGO_BASE_I 1

class JogoBase {
    private:
        int largura;
        int altura;
        int** tabuleiro;
    public:
        JogoBase(int largura, int altura);
        ~JogoBase();
        void imprimirTabuleiro();
        bool lerJogada();
        bool validarJogada();
        int testarVitoria();
};

#endif