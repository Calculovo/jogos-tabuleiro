#include "jogobase.hpp"

JogoBase::JogoBase(int largura, int altura) : turno(PLAYER_1){
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

char JogoBase::getTurno() {
    return turno;
};

char JogoBase::switchTurno() {
    if (turno == PLAYER_1) turno = PLAYER_2;
    else turno = PLAYER_1;
    return turno;
}

int JogoBase::getAltura() {
    return tabuleiro->getAltura();
}

int JogoBase::getLargura() {
    return tabuleiro->getLargura();
}