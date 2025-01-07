#include "jogobase.hpp"

JogoBase::JogoBase(int largura, int altura) : largura(largura), altura(altura), turno(PLAYER_1){
    tabuleiro = new Tabuleiro(largura, altura);
    tabuleiro->adicionarLegenda(VAZIO, ' ');
    tabuleiro->adicionarLegenda(PLAYER_1, 'X');
    tabuleiro->adicionarLegenda(PLAYER_2, 'O');
};

JogoBase::JogoBase(int tamanho) : JogoBase(tamanho, tamanho){
};

JogoBase::~JogoBase() {
    delete tabuleiro;
};

void JogoBase::imprimirTabuleiro() {
    tabuleiro->imprimirTabuleiro();
};