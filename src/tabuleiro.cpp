#include "tabuleiro.hpp"

#include <iostream>
#include <map>

Tabuleiro::Tabuleiro(int largura, int altura) :
    t_largura(largura), 
    t_altura(altura) {
    t_legenda = new Legenda;
    (*t_legenda)[0] = ' ';
    t_matriz = new char[largura*altura];
    for (int i = 0; i < largura*altura; i++) {
        t_matriz[i] = 0;
    }
}

Tabuleiro::~Tabuleiro() {
    delete t_legenda;
    delete[] t_matriz;
}

void Tabuleiro::imprimirTabuleiro() {
    for (int i = 0; i < t_altura; i++) {
        for (int j = 0; j < t_largura; j++) {
            if (t_legenda->find(this->lerPeca(j, i)) == t_legenda->end()) {
                std::cout << "ERRO: Tabuleiro tem peca desconhecida." << std::endl;
                return;
            }
        }
    }
    std::cout << " |";
    for (int j = 0; j < t_largura; j++) {
        std::cout << (char) ('A'+j) << '|';
    }
    std::cout << std::endl;
    for (int j = 0; j < t_largura+1; j++) {
        std::cout << "-+";
    }
    std::cout << std::endl;
    for (int i = 0; i < t_altura; i++) {
        std::cout << (char) ('1'+i) << '|';
        for (int j = 0; j < t_largura; j++) {
            std::cout << (*t_legenda)[this->lerPeca(j, i)] << '|';
        }
        std::cout << std::endl;
        for (int j = 0; j < t_largura+1; j++) {
            std::cout << "-+";
        }
        std::cout << std::endl;
    }
}

bool Tabuleiro::posicaoValida(int x, int y) {
    return (0 <= x and x < t_largura and 0 <= y and y <= t_altura);
}

bool Tabuleiro::colocarPeca(int x, int y, char peca) {
    if (not this->posicaoValida(x,y)) return false;
    int indice = y*t_largura + x;
    if (t_matriz[indice] == peca) return false;
    t_matriz[indice] = peca;
    return true;
}

char Tabuleiro::lerPeca(int x, int y) {
    if (not this->posicaoValida(x,y)) return INVALID;
    int indice = y*t_largura + x;
    return t_matriz[indice];
}

void Tabuleiro::adicionarLegenda(char chave, char valor) {
    (*t_legenda)[chave] = valor;
}