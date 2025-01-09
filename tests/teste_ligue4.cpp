#include "ligue4.hpp"
#include <iostream>
using namespace std;

int main() {
    Ligue4 jogo;
    string entrada;

    while (jogo.testarVitoria() == INDEFINIDO) {
        jogo.imprimirTabuleiro();
        cout << "Vez do jogador " << (jogo.getTurno() == PLAYER_1 ? "1 (X)" : "2 (O)") << ":" << endl;
        getline(cin, entrada);

        if (jogo.validarJogada(entrada) != VALID_PLAY) {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
    }

    jogo.imprimirTabuleiro();
    int vencedor = jogo.testarVitoria();
    if (vencedor == EMPATE) {
        cout << "Empatou!" << endl;
    } else {
        cout << "Jogador " << (vencedor == PLAYER_1 ? "1 (X)" : "2 (O)") << " ganhou!" << endl;
    }

    return 0;
}

