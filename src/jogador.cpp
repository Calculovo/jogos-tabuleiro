#include <jogador.hpp>
#include <iostream>

using namespace std;

// Construtor
Jogador::Jogador(string nome, string apelido) {
    this->nome = nome;
    this->apelido = apelido;

    // Inicializa a matriz de vitórias com valores 0 (nenhuma vitória registrada inicialmente)
    for (int i = 0; i < N_DE_JOGOS; i++) {
        for (int j = 0; j < N_DE_RESULTADOS; j++) {
            resultados[i][j] = 0;
        }
    }
}

Jogador::Jogador(string nome, string apelido, int valor[5][3]) : Jogador(nome,apelido) {
    // Inicializa a matriz de vitórias com valores antigos
    for (int i = 0; i < N_DE_JOGOS; i++) {
        for (int j = 0; j < N_DE_RESULTADOS; j++) {
            resultados[i][j] = valor[i][j];
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

int Jogador::getResultados(int jogo, int resultado) const {
    return resultados[jogo][resultado];
}

void Jogador::imprimir() const {
    cout << apelido << " " << nome << endl;
    for (int i = 0; i < N_DE_JOGOS; i++) {
        cout << nomes[i] << " - \t";
        cout << "V: " << getResultados(i, VITORIA_INDICE) << "\t";
        cout << "E: " << getResultados(i, EMPATE_INDICE) << "\t";
        cout << "D: " << getResultados(i, DERROTA_INDICE) << endl;
    }
}

string Jogador::getApelido() const {
    return apelido;
}

string Jogador::getNome() const {
    return nome;
}