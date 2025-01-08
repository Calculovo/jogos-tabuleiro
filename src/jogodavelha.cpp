#include "jogodavelha.hpp"
#include <iostream>

JogoDaVelha::JogoDaVelha() : JogoDaVelha(3){};

JogoDaVelha::JogoDaVelha(int tamanho) : JogoBase(tamanho){};

char JogoDaVelha::validarJogada(std::string input) {
    Coord coord(input);
    if (not tabuleiro->posicaoValida(coord)) {
        std::cout << "Digite as coordenadas sem espaco. Exemplos: A1, C3" << std::endl;
        return SYNTAX_ERROR;
    }
    if (tabuleiro->lerPeca(coord) != VAZIO) {
        std::cout << "Digite as coordenadas de um espaco em branco." << std::endl;
        return LOGIC_ERROR;
    }
    tabuleiro->colocarPeca(coord, this->getTurno());
    this->switchTurno();
    return VALID_PLAY;
};

int JogoDaVelha::testarReta(Coord inicial, Coord direcao, int tamanho) {
    char meta = tabuleiro->lerPeca(inicial);
    if (meta == VAZIO) return INDEFINIDO;
    for (int i = 1; i < tabuleiro->getAltura(); i++) {
        if (tabuleiro->lerPeca(inicial + direcao*i) == meta)
            continue;
        return INDEFINIDO;
    }
    return meta;
}; 

int JogoDaVelha::testarVitoria() {
    char temp;
    //verificar verticais
    for (int i = 0; i < tabuleiro->getLargura(); i++) {
        temp = testarReta(Coord(i,0), Coord(0,1), tabuleiro->getAltura());
        if (temp == INDEFINIDO)
            continue;
        return temp;
    }
    //verificar horizontais
    for (int i = 0; i < tabuleiro->getAltura(); i++) {
        temp = testarReta(Coord(0,i), Coord(1,0), tabuleiro->getLargura());
        if (temp == INDEFINIDO)
            continue;
        return temp;
    }
    //verificar diagonais
    temp = testarReta(Coord(0,0), Coord(1,1), tabuleiro->getAltura());
    if (temp != INDEFINIDO) return temp;
    temp = testarReta(Coord(0,tabuleiro->getAltura()-1), Coord(1,-1), tabuleiro->getAltura());
    if (temp != INDEFINIDO) return temp;
    //verificar se ainda eh possivel jogar
    for (int i = 0; i < tabuleiro->getLargura(); i++) {
        for (int j = 0; j < tabuleiro->getAltura(); j++) {
            if (tabuleiro->lerPeca(Coord(i,j)) == VAZIO) return INDEFINIDO;
        }
    }
    return EMPATE;
}