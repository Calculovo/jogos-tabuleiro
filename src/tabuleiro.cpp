#include "tabuleiro.hpp"

#include <iostream>
#include <map>

Coord::Coord(int x, int y) : x(x), y(y){};

Coord::Coord(std::string entrada) {
    int coluna = entrada[0]-'A';
    int linha = entrada[1]-'0';
    if (entrada.size() > 4 or coluna < 0 or coluna > 25 or linha < 0 or linha > 9) {
        x = INVALID;
        y = INVALID;
        return;
    }
    entrada[0] = '0';
    linha = std::stoi(entrada);
    if (linha == 0) {
        x = INVALID;
        y = INVALID;
        return;
    }
    x = coluna;
    y = linha-1;
};

int Coord::getX() {return x;};

int Coord::getY() {return y;};

Coord Coord::operator +(Coord p) {
    return Coord(this->x + p.getX(), this->y + p.getY());
};

Coord Coord::operator -(Coord p) {
    return Coord(this->x - p.getX(), this->y - p.getY());
};

Coord Coord::operator *(int p) {
    return Coord(this->x * p, this->y*p);
};

Tabuleiro::Tabuleiro(Coord coord) :
    t_largura(coord.getX()), 
    t_altura(coord.getY()) {
    if (t_altura > 26 or t_largura > 26 or t_altura < 1 or t_largura < 1) {
        std::cerr << "Tabuleiros devem ter dimensao entre 1x1 e 26x26." << std::endl;
        exit(1);
    }
    t_matriz = new char[t_altura*t_largura];
    for (int i = 0; i < t_largura*t_altura; i++) {
        t_matriz[i] = VAZIO;
    }
}

Tabuleiro::~Tabuleiro() {
    delete[] t_matriz;
}

void Tabuleiro::linhaHorizontal() {
    if (t_altura >= 10)
        std::cout << "-";
    std::cout << "-+";
    for (int j = 0; j < t_largura; j++) {
        std::cout << "---+";
    }
    std::cout << std::endl;
}

void Tabuleiro::imprimirTabuleiro() {
    if (t_altura >= 10)
        std::cout << " ";
    std::cout << " |";
    for (int j = 0; j < t_largura; j++) {
        std::cout << ' ' << (char) ('A'+j) << ' ' << '|';
    }
    std::cout << std::endl;
    linhaHorizontal();
    for (int i = 0; i < t_altura; i++) {
        if (i+1 < 10 and t_altura >= 10)
            std::cout << " ";
        std::cout << (i+1) << '|';
        for (int j = 0; j < t_largura; j++) {
            std::cout << ' ' << this->lerPeca(j, i) << ' ' << '|';
        }
        std::cout << std::endl;
        linhaHorizontal();
    }
}

bool Tabuleiro::posicaoValida(Coord coord) {
    int x = coord.getX();
    int y = coord.getY();
    return (0 <= x and x < t_largura and 0 <= y and y < t_altura);
}

bool Tabuleiro::colocarPeca(Coord coord, char peca) {
    if (not this->posicaoValida(coord)) return false;
    int indice = coord.getY()*t_largura + coord.getX();
    if (t_matriz[indice] == peca) return false;
    t_matriz[indice] = peca;
    return true;
}

char Tabuleiro::lerPeca(Coord coord) {
    if (not this->posicaoValida(coord)) return INVALID;
    int indice = coord.getY()*t_largura + coord.getX();
    return t_matriz[indice];
}

int Tabuleiro::getAltura() {
    return this->t_altura;
}

int Tabuleiro::getLargura() {
    return this->t_largura;
}

Tabuleiro::Tabuleiro(int x, int y) : Tabuleiro(Coord(x,y)) {};

bool Tabuleiro::posicaoValida(int x, int y) {
    return posicaoValida(Coord(x,y));
};

bool Tabuleiro::colocarPeca(int x, int y, char peca) {
    return colocarPeca(Coord(x,y), peca);
};

char Tabuleiro::lerPeca(int x, int y) {
    return lerPeca(Coord(x,y));
};