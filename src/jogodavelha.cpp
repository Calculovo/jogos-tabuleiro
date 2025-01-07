#include "jogodavelha.hpp"
#include <iostream>

JogoDaVelha::JogoDaVelha() : JogoDaVelha(3){};

JogoDaVelha::JogoDaVelha(int tamanho) : JogoBase(tamanho){};

char JogoDaVelha::validarJogada(std::string input) {
    int coluna = input[0]-'A';
    int linha = input[1]-'1';
    if (0 > coluna or coluna >= largura or 0 > linha or linha >= altura) {
        std::cout << "Digite as coordenadas sem espaco. Exemplos: A1, C3" << std::endl;
        return SYNTAX_ERROR;
    }
    if (tabuleiro->lerPeca(coluna, linha) != VAZIO) {
        std::cout << "Digite as coordenadas de um espaco em branco." << std::endl;
        return LOGIC_ERROR;
    }
    tabuleiro->colocarPeca(coluna, linha, this->getTurno());
    this->switchTurno();
    return VALID_PLAY;
};

int JogoDaVelha::testarVitoria() {
    //testar verticais
    bool broke;
    for (int i = 0; i < largura; i++) {
        broke = false;
        for (int j = 1; j < altura; j++) {
            if (tabuleiro->lerPeca(i,j) == tabuleiro->lerPeca(i,0)) continue;
            broke = true;
            break;
        }
        if (not broke and tabuleiro->lerPeca(i,0) != VAZIO)
            return tabuleiro->lerPeca(i,0);
    }
    //testar horizontais
    for (int j = 0; j < altura; j++) {
        broke = false;
        for (int i = 1; i < largura; i++) {
            if (tabuleiro->lerPeca(i,j) == tabuleiro->lerPeca(0,j)) continue;
            broke = true;
            break;
        }
        if (not broke and tabuleiro->lerPeca(0,j) != VAZIO)
            return tabuleiro->lerPeca(0,j);
    }
    //testar diagonais
    broke = false;
    for (int j = 1; j < altura; j++) {
        if (tabuleiro->lerPeca(j,j) == tabuleiro->lerPeca(0,0)) continue;
        broke = true;
        break;
    }
    if (not broke and tabuleiro->lerPeca(0,0) != VAZIO)
        return tabuleiro->lerPeca(0,0);
    broke = false;
    for (int j = 1; j < altura; j++) {
        if (tabuleiro->lerPeca(j,altura-j-1) == tabuleiro->lerPeca(0,altura-1)) continue;
        broke = true;
        break;
    }
    if (not broke and tabuleiro->lerPeca(0,altura-1) != VAZIO)
        return tabuleiro->lerPeca(0,altura-1);
    //verificar se ainda eh possivel jogar
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            if (tabuleiro->lerPeca(i,j) == VAZIO) return INDEFINIDO;
        }
    }
    return EMPATE;
}