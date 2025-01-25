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

//Alterar a matriz de resultados
void Jogador::AddResultados(char jogo, int resultado){
    int jogoIndex;
    
    //Recebe o char correspondente ao jogo e transforma em um indice correspondente na matriz
    switch (jogo) {
        case 'R':{
            jogoIndex = 0; 
            break;
        }case 'L': {
            jogoIndex = 1;
            break;
        }case 'V': {
            jogoIndex = 2; 
            break;
        }case 'D': {
            jogoIndex = 3; 
            break;
        }case 'O': {
            jogoIndex = 4; 
            break;
        }default:
            cout << "Jogo inválido!" << endl;
            return;
    }

    //Adiciona na matriz de resultados de acordo com o valor informado correspondente ao resultado da partida
    if (resultado == VITORIA_INDICE) {
        resultados[jogoIndex][0]++;
        return;
    } else if (resultado == EMPATE_INDICE) {
        resultados[jogoIndex][1]++;
        return;
    } else if (resultado == DERROTA_INDICE) {
        resultados[jogoIndex][2]++;
        return;
    } else {
        cout << "Resultado inválido!" << endl;
        return;
    }

    return;

};


const char* nomes[5] = {
    "REVERSI",
    "LIG4   ",
    "VELHA  ",
    "DAMAS  ",
    "RAPOSA ",
};

int Jogador::getResultados(char jogo, int resultado) const {
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