#include <jogador.hpp>
#include <iostream>

using namespace std;

// Construtor
Jogador::Jogador(string nome, string apelido) {
    this->nome = nome;
    this->apelido = apelido;

    // Inicializa a matriz de vitórias com valores 0 (nenhuma vitória registrada inicialmente)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            resultados[i][j] = 0;
        }
    }
}