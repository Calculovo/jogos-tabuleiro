#include "ligue4.hpp"
#include <iostream>

Ligue4::Ligue4() : JogoBase(7, 6) {
    
}

char Ligue4::validarJogada(std::string input) {
    int coluna = input[0] - 'A'; //! Converte a entrada para o índice da coluna
    if (coluna < 0 || coluna >= tabuleiro->getLargura()) {
        std::cout << "Coluna inválida. Escolha entre A e " << (char)('A' + tabuleiro->getLargura() - 1) << "." << std::endl;
        return SYNTAX_ERROR;
    }

    //! Encontra a primeira posição disponível na coluna
    for (int linha = tabuleiro->getAltura() - 1; linha >= 0; --linha) {
        Coord posicao(coluna, linha);
        if (tabuleiro->lerPeca(posicao) == VAZIO) {
            tabuleiro->colocarPeca(posicao, turno);
            this->switchTurno();
            return VALID_PLAY;
        }
    }

    std::cout << "Coluna cheia. Tente outra." << std::endl;
    return LOGIC_ERROR;
}

bool Ligue4::verificarSequencia(Coord inicio, Coord direcao, char peca) {
    for (int i = 1; i < 4; ++i) {
        Coord proxima = inicio + direcao * i;
        if (!tabuleiro->posicaoValida(proxima) || tabuleiro->lerPeca(proxima) != peca) {
            return false;
        }
    }
    return true;
}

int Ligue4::testarVitoria() {
    //! Verifica linhas, colunas e diagonais
    for (int y = 0; y < tabuleiro->getAltura(); ++y) {
        for (int x = 0; x < tabuleiro->getLargura(); ++x) {
            char peca = tabuleiro->lerPeca(Coord(x, y));
            if (peca == VAZIO) continue;

            if (verificarSequencia(Coord(x, y), Coord(1, 0), peca) || // Horizontal
                verificarSequencia(Coord(x, y), Coord(0, 1), peca) || // Vertical
                verificarSequencia(Coord(x, y), Coord(1, 1), peca) || // Diagonal principal
                verificarSequencia(Coord(x, y), Coord(1, -1), peca))  // Diagonal secundária
            {
                return peca == 'X' ? PLAYER_1 : PLAYER_2;
            }
        }
    }

    //! Verifica empate
    for (int x = 0; x < tabuleiro->getLargura(); ++x) {
        if (tabuleiro->lerPeca(Coord(x, 0)) == VAZIO) return INDEFINIDO;
    }

    return EMPATE;
}

void Ligue4::imprimirTabuleiro() {
    tabuleiro->imprimirTabuleiro();
}
