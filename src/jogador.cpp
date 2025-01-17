#include <jogador.hpp>
#include <iostream>

using namespace std;

// Construtor
Jogador::Jogador(string nome, string apelido) {
    this->nome = nome;
    this->apelido = apelido;

    // Inicializa a matriz de vitórias com valores 0 (nenhuma vitória registrada inicialmente)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            resultados[i][j] = 0;
        }
    }
}

const char* nomes[5] = {
    "REVERSI",
    "LIG4   ",
    "VELHA  ",
    "DAMAS  ",
    "RAPOSA ",
};

void Jogador::imprimir() const {
    cout << apelido << " " << nome << endl;
    for (int i = 0; i < 5; i++) {
        cout << nomes[i] << " - \t";
        cout << "V: " << resultados[i][VITORIA_INDICE] << "\t";
        cout << "E: " << resultados[i][EMPATE_INDICE] << "\t";
        cout << "D: " << resultados[i][DERROTA_INDICE] << endl;
    }
}

string Jogador::getApelido() const {
    return apelido;
}

string Jogador::getNome() const {
    return nome;
}