#include "damas.hpp"
#include <iostream>
#include <cctype>

Damas::Damas() : JogoBase(8) {
    for (int j = 1; j <= 7; j += 2) {
        tabuleiro->colocarPeca(Coord(j, 0), 'X');
        tabuleiro->colocarPeca(Coord(j, 2), 'X');
        tabuleiro->colocarPeca(Coord(j, 6), 'O');
    }
    for (int j = 0; j <= 6; j += 2) {
        tabuleiro->colocarPeca(Coord(j, 1), 'X');
        tabuleiro->colocarPeca(Coord(j, 5), 'O');
        tabuleiro->colocarPeca(Coord(j, 7), 'O');
    }
};

char Damas::validarJogada(std::string input) {

    if (input.size() != 4) {
        std::cout << "As coordenadas devem ser digitadas sem espaço, sendo do formato ORIGEMDESTINO. Exemplo: 'B3A4', para ir da casa B3 a A4." 
        << std::endl;
        return SYNTAX_ERROR;
    }

    Coord origem = input.substr(0, 2);
    Coord destino = input.substr(2, 2);

    char peca = tabuleiro->lerPeca(origem);

    if (tolower(peca) != tolower(getTurno())) {
        std::cout << "A coordenada de origem não possui uma peça do jogador da vez." << std::endl;
        return LOGIC_ERROR;
    }
    if (not tabuleiro->posicaoValida(origem) || not tabuleiro->posicaoValida(destino)) {
        std::cout << "A coordenada de origem ou de destino não existe no tabuleiro." << std::endl;
        return LOGIC_ERROR;
    }

    int dx = destino.getX() - origem.getX();
    int dy = destino.getY() - origem.getY();

    if (destino == origem) {
        std::cout << "A peça não pode se mover para a casa de origem." << std::endl;
        return LOGIC_ERROR;
    }
    
    if (tabuleiro->lerPeca(destino) != VAZIO) {
        std::cout << "Há uma peça nessa casa." << std::endl;
        return LOGIC_ERROR;
    }

    if (destino.getX() == origem.getX() || abs(dx) != abs(dy)) {
        std::cout << "Nesse caso, peça só se move na diagonal e a um quadrado de distância." << std::endl;
        return LOGIC_ERROR;
    }

    if (peca == 'x' || peca == 'o') {
        int stepX = dx > 0 ? 1 : -1;
        int stepY = dy > 0 ? 1 : -1;

        Coord atual = origem;
        Coord coordComida = Coord(0,0);
        unsigned short int capturas = 0;
        char pecaComida = VAZIO;

        if (abs(dx) == 1 && abs(dy) == 1 && tabuleiro->lerPeca(destino) == VAZIO) {
            realizarMovimento(origem, destino, peca);
            return VALID_PLAY;
        }

        while (!(atual == destino)) {
            atual = atual + Coord(stepX, stepY);
            char pecaAtual = tabuleiro->lerPeca(atual);

            if(pecaAtual != VAZIO) {
                if (tolower(tabuleiro->lerPeca(atual) == peca)) {
                    std::cout << "Você não pode saltar por sua própria peça." << std::endl;
                    return LOGIC_ERROR;
                }
                if (pecaComida != VAZIO) {
                    std::cout << "Você só pode comer uma peça por vez." << std::endl;
                    return LOGIC_ERROR;
                }
                coordComida = atual;
                capturas++;
                break;
            }
        }
        if (capturas == 1) {
            realizarMovimento(origem, destino, peca);
            tabuleiro->colocarPeca(coordComida, VAZIO);
            return VALID_PLAY;
        }
        else {
            std::cout << "Movimento inválido: nenhuma peça para capturar ou múltiplas peças no caminho." << std::endl;
            return LOGIC_ERROR;
        }
    }

    if (abs(dx) > 2 || abs(dy) > 2) {
        std::cout << "Esse movimento está fora do alcance." << std::endl;
        return LOGIC_ERROR;
    }

    if ((peca == PLAYER_1 && destino.getY() > origem.getY()) || (peca == PLAYER_2 && destino.getY() < origem.getY())) {
        if (abs(dx) == 1 && tabuleiro->lerPeca(destino) == VAZIO) {
            realizarMovimento(origem, destino, peca);
            return VALID_PLAY;
        }
        if (abs(dx) == 2 && abs(dy) == 2) {
            Coord comida = origem + ((destino - origem) * 0.5);
            char pecaComida = tabuleiro->lerPeca(Coord(comida));
            if ((peca == PLAYER_1 && pecaComida == PLAYER_2) || (peca == PLAYER_2 && pecaComida == PLAYER_1)) {
                realizarMovimento(origem, destino, peca);
                return VALID_PLAY;
            }
        }
        std::cout << "Você só pode se mover assim se existir uma peça a ser comida." << std::endl;
        return LOGIC_ERROR;
    }
    else {
        std::cout << "Uma peça normal só pode se mover para frente." << std::endl;
    }
    return INDEFINIDO;
}

void Damas::realizarMovimento (Coord origem, Coord destino, char peca) {

    tabuleiro->colocarPeca(Coord(origem), VAZIO);
    tabuleiro->colocarPeca(Coord(destino), peca);

    Coord comida = origem + (destino - origem) * 0.5;
    tabuleiro->colocarPeca(Coord(comida), VAZIO);

    if (peca == PLAYER_1 && destino.getY() == 7) tabuleiro->colocarPeca(destino, 'x');
    if (peca == PLAYER_2 && destino.getY() == 0) tabuleiro->colocarPeca(destino, 'o');

    switchTurno();
    return;
}

bool Damas::jogoTrancado() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char peca = tabuleiro->lerPeca(Coord(x, y));
            if (peca == VAZIO) continue;
            if (temMovimentosValidos(Coord(x, y), peca)) {
                return false;
            }
        }
    }
    return true;
}

bool Damas::temMovimentosValidos(Coord posicao, char peca) {
    if (peca == 'x' || peca =='o') return true;

    int direcoes[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto& d : direcoes) {
        Coord vizinho = posicao + Coord(d[0], d[1]);
        Coord possivelCaptura = vizinho + Coord(d[0], d[1]);

        if (tabuleiro->posicaoValida(vizinho) && tabuleiro->lerPeca(vizinho) == VAZIO) {
            return true;
        }

        if (tabuleiro->posicaoValida(possivelCaptura) && tabuleiro->lerPeca(possivelCaptura) == VAZIO) {
            char pecaVizinha = tabuleiro->lerPeca(vizinho);
            if (pecaVizinha != VAZIO && std::tolower(pecaVizinha) != std::tolower(peca)) {
                return true;
            }
        }
    }
    return false;
}

int Damas::testarVitoria () {
    if (jogoTrancado()) {
        std::cout << "O jogo está trancado." << std::endl;
        return EMPATE;
    }
    int countX = 0, countO = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char peca = tabuleiro->lerPeca(i, j);
            if (tolower(peca) == tolower(PLAYER_1)) countX++;
            if (tolower(peca) == tolower(PLAYER_2)) countO++;
        }
    }
    if (countX == 0) return PLAYER_2;
    if (countO == 0) return PLAYER_1;
    return INDEFINIDO;
}