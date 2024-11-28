//a fazer: aprender a usar doctest em vez deste teste maluco
#include "tabuleiro.hpp"
#include <iostream>

int main() {
    Tabuleiro t(3,3);
    std::cout << "Isto deve imprimir um tabuleiro 3x3 vazio." << std::endl;
    t.imprimirTabuleiro();
    t.colocarPeca(1, 2, PLAYER_1);
    std::cout << "Isto deve dar erro." << std::endl;
    t.imprimirTabuleiro();
    t.adicionarLegenda(PLAYER_1, 'X');
    t.adicionarLegenda(PLAYER_2, 'O');
    std::cout << "Segunda coluna, terceira linha deve ter um X." << std::endl;
    t.imprimirTabuleiro();
    t.colocarPeca(1, 1, PLAYER_1);
    t.colocarPeca(1, 0, PLAYER_1);
    t.colocarPeca(0, 0, PLAYER_2);
    t.colocarPeca(2, 0, PLAYER_2);
    t.colocarPeca(0, 2, PLAYER_2);
    std::cout << "X ganhara o jogo da velha." << std::endl;
    t.imprimirTabuleiro();
    std::cout << "Isso deve imprimir o valor de cada celula." << std::endl;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            std::cout << (int) t.lerPeca(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

