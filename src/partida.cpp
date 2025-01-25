#include <iostream>
#include "partida.hpp"

Partida::Partida(char comandoJogo, Jogador* jogador1, Jogador* jogador2) : comandoJogo(comandoJogo), jogador1(jogador1), jogador2(jogador2) {

    switch (comandoJogo) {
        case cVELHA:
            jogo = std::make_unique<JogoDaVelha>();
            break;
        case cREVERSI:
            jogo = std::make_unique<Reversi>();
            break;
        case cLIG4:
            jogo = std::make_unique<Ligue4>();
            break;
        case cRAPOSA:
            jogo = std::make_unique<RaposaeOvelhas>();
            break;
        case cDAMAS:
            jogo = std::make_unique<Damas>();
            break;
        default:
            throw invalid_argument("Jogo nao reconhecido.");
            break;
    }
};

void Partida::jogar() {
    string input;
    while (jogo->testarVitoria() == INDEFINIDO) {
        jogo->imprimirTabuleiro();
        std::cout << "Vez do jogador ";
        std::cout << (jogo->getTurno() == PLAYER_1 ? "1" : "2") << ":" << std::endl;
        getline(cin, input);
        if (input == "ENCERRAR") return;
        jogo->validarJogada(input);
    }
    jogo->imprimirTabuleiro();
    if (jogo->testarVitoria() == EMPATE) {
        std::cout << "Empate." << std::endl;
        jogador1->addResultados(comandoJogo, EMPATE_INDICE);
        jogador2->addResultados(comandoJogo, EMPATE_INDICE);
        return;
    }
    else if (jogo->testarVitoria() == PLAYER_1) {
        std::cout << "Jogador 1 ganhou!" << std::endl;
        jogador1->addResultados(comandoJogo, VITORIA_INDICE);
        jogador2->addResultados(comandoJogo, DERROTA_INDICE);
    }
    else if (jogo->testarVitoria() == PLAYER_2) {
        std::cout << "Jogador 2 ganhou!" << std::endl;
        jogador2->addResultados(comandoJogo, VITORIA_INDICE);
        jogador1->addResultados(comandoJogo, DERROTA_INDICE);
    }
}