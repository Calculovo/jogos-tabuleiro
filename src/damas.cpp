#include "damas.hpp"
#include <iostream>

Damas::Damas() : JogoBase(8) {
    for (int j = 1; j <= 7; j += 2) {
        tabuleiro->colocarPeca(Coord(0, j), PLAYER_1);
        tabuleiro->colocarPeca(Coord(2, j), PLAYER_1);
        tabuleiro->colocarPeca(Coord(6, j), PLAYER_2);
    }
    for (int j = 0; j <= 6; j += 2) {
        tabuleiro->colocarPeca(Coord(1, j), PLAYER_1);
        tabuleiro->colocarPeca(Coord(5, j), PLAYER_2);
        tabuleiro->colocarPeca(Coord(7, j), PLAYER_2);
    }
};

char Damas::validarJogada(std::string input) {
    Coord origem = input.substr(0, 2);
    Coord destino = input.substr(2, 2);

    char peca = tabuleiro->lerPeca(origem);

    if (peca != getTurno()) {
        std::cout << "A coordenada de origem não possui uma peça do jogador da vez." << std::endl;
        return LOGIC_ERROR;
    }
    if (peca != tabuleiro->posicaoValida(origem)) {
        std::cout << "A coordenada de origem não existe no tabuleiro" << std::endl;
        return SYNTAX_ERROR;
    }

    int dx = abs(destino.getX() - origem.getX());
    int dy = destino.getY() - origem.getY();

    if ((peca == PLAYER_1 && dy != 1) || (peca == PLAYER_2 && dy != -1)) {
        std::cout << "A coordenada de destino está fora do alcance" << std::endl;
        return LOGIC_ERROR;
    }

    if (dx == 1 && tabuleiro->lerPeca(destino) == VAZIO) return VALID_PLAY;
    if (dx == 2) {
        Coord comida = origem + (destino - origem) * 0.5;
        char pecaComida = tabuleiro->lerPeca(Coord(comida));
        if ((peca == PLAYER_1 && pecaComida == PLAYER_2) || (peca == PLAYER_2 && pecaComida == PLAYER_1)) return VALID_PLAY;
        else {
            std::cout << "Você não pode realizar esse movimento pois não há nenhuma peça inimiga na diagonal." << std::endl;
            return LOGIC_ERROR;
        } 
    }
    return INDEFINIDO;
}

void Damas::realizarMovimento (std::string input) {
    if (not validarJogada(input)) return;
    Coord origem = input.substr(0, 2);
    Coord destino = input.substr(2, 2);
    
    char peca = tabuleiro->lerPeca(origem);

    tabuleiro->colocarPeca(Coord(origem), VAZIO);
    tabuleiro->colocarPeca(Coord(destino), peca);

    int dx = abs(destino.getX() - origem.getY());
    if (dx == 2) {
        Coord comida = origem + (destino - origem) * 0.5;
        tabuleiro->colocarPeca(Coord(comida), VAZIO);
    }
    switchTurno();
    return;
} 

int Damas::testarVitoria () {
    int countX, countO;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char peca = tabuleiro->lerPeca(i, j);
            if (peca == PLAYER_1) countX++;
            if (peca == PLAYER_2) countO++;
        }
    }
    if (countX == 0) {
        std::cout << "Jogador 2 venceu." << std::endl;
        return PLAYER_2;
    }
    if (countO == 0) {
        std::cout << "Jogador 1 venceu." << std::endl;
        return PLAYER_1;
    }
    return INDEFINIDO;
}