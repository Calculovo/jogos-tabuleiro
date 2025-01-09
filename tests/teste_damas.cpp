#include "damas.hpp"
#include <iostream>
using namespace std;

int main() {
    Damas d;
    string input;
    while (d.testarVitoria() == INDEFINIDO) {
        d.imprimirTabuleiro();
        cout << "Vez do jogador ";
        cout << (d.getTurno() == PLAYER_1 ? "1" : "2") << ":" << endl;
        getline(cin, input);
        d.validarJogada(input);
    }

    d.imprimirTabuleiro();
    cout << "Player " << (d.testarVitoria() == PLAYER_1 ? "1" : "2") << " ganhou!" << endl;

    return 0;
}