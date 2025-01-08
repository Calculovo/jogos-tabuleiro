#include "tabuleiro.hpp"
#include <iostream>

using namespace std;

void verificar(string s, int x, int y) {
    Coord c(s);
    if (c.getX() == x and c.getY() == y) cout << "OK" << endl;
    else cout << "Erro:" << s << " " << c.getX() << "," << c.getY() << endl;
}

int main() {
    verificar("A1", 0, 0);
    verificar("B6", 1, 5);
    verificar("I9", 8, 8);
    verificar("Z26", 25, 25);
    verificar("PP", INVALID, INVALID);
    verificar("A0", INVALID, INVALID);
    verificar("a1", INVALID, INVALID);
    verificar("A", INVALID, INVALID);
    verificar(";", INVALID, INVALID);
    verificar("200", INVALID, INVALID);
    return 0;
}