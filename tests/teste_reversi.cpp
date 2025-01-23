#include <reversi.hpp>
#include <iostream>
using namespace std;

int main() {
    Reversi j;
    string entrada;
    while (j.testarVitoria() == INDEFINIDO) {
        j.imprimirTabuleiro();
        cout << "Vez do jogador ";
        cout << (j.getTurno() == PLAYER_1 ? "1" : "2") << ":" << endl;
        getline(cin, entrada);
        if (entrada == "Y"){
            return 0;
        }
        j.validarJogada(entrada);
    }
    j.imprimirTabuleiro();
    cout << "Player " << (j.testarVitoria() == PLAYER_1 ? "1" : "2") << " ganhou!" << endl;
    return 0;
}