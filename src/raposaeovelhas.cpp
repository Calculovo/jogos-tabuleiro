#include "raposaeovelhas.hpp"
#include <iostream>

RaposaeOvelhas::RaposaeOvelhas(): JogoBase(8, 8){
    tabuleiro->colocarPeca(Coord(4,7), 'X');
    for (int i=1; i<8; i+=2){
        tabuleiro->colocarPeca(Coord(i,0), 'O');
    }
};

char RaposaeOvelhas::validarJogada(std::string input) {
    try {
        Coord destino(1, 1), origem(2, 2);

        if (turno == PLAYER_1) {
            if (input.size() != 2) {
                throw std::invalid_argument("Digite uma coordenada válida e sem espaço. Exemplos: A1, C3.");
            }

            destino = Coord(input);

            if (!tabuleiro->posicaoValida(destino)) {
                throw std::invalid_argument("Digite uma coordenada válida. Exemplos: A1, C3.");
            }

            if (tabuleiro->lerPeca(destino) != ' ') {
                throw std::logic_error("Digite as coordenadas de um espaço em branco.");
            }

            for (int x = 0; x < tabuleiro->getLargura(); ++x) {
                for (int y = 0; y < tabuleiro->getAltura(); ++y) {
                    if (tabuleiro->lerPeca(Coord(x, y)) == 'X') {
                        origem = Coord(x, y);
                        break;
                    }
                }
            }
        } else {
            if (input.size() != 4) {
                throw std::invalid_argument("As coordenadas atuais da ovelha e de seu destino devem ser válidas e digitadas sem espaço. Exemplo: B2C3.");
            }

            origem = Coord(input.substr(0, 2));
            destino = Coord(input.substr(2, 2));

            if (!tabuleiro->posicaoValida(origem) || !tabuleiro->posicaoValida(destino)) {
                throw std::invalid_argument("As coordenadas atuais da ovelha e de seu destino devem ser válidas. Exemplo: B2C3.");
            }

            if (tabuleiro->lerPeca(origem) != 'O' || tabuleiro->lerPeca(destino) != ' ') {
                throw std::logic_error("Digite as coordenadas de um espaço onde há uma ovelha e, em seguida, as de um espaço em branco.");
            }
        }

        return realizarJogada(origem, destino);
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return SYNTAX_ERROR;
    } catch (const std::logic_error &e) {
        std::cout << e.what() << std::endl;
        return LOGIC_ERROR;
    } catch (...) {
        std::cout << "Ocorreu um erro inesperado." << std::endl;
        return LOGIC_ERROR;
    }
}

int RaposaeOvelhas::testarVitoria() {
    int i = 0, j = 0;

    while (i<8){
        if (j==7){
            j=0;
            i++;
        }
        if (tabuleiro->lerPeca(Coord(j, i)) == 'O') {
            for(int k=j; k<8; k++){
                if (tabuleiro->lerPeca(Coord(k, i)) == 'X'){
                    return PLAYER_1;
                }
            }
            break;
        }
        else if (tabuleiro->lerPeca(Coord(j, i)) == 'X') {
            return PLAYER_1;
        }
        j++;
    }

    for (i=0; i < 8; i++) {
        for (j=0; j < 8; j++){
           if (tabuleiro->lerPeca(Coord(i, j)) == 'X'){
                Coord posraposa = Coord(i, j);
                if (!movimentoValido(posraposa, Coord (i+1, j+1)) && !movimentoValido(posraposa, Coord (i-1, j+1))
                && !movimentoValido(posraposa, Coord (i-1, j-1)) && !movimentoValido(posraposa, Coord (i+1, j-1))){
                return PLAYER_2;
                }
           }
        }
    }

    return INDEFINIDO;
}

void RaposaeOvelhas::imprimirTabuleiro() {
    tabuleiro->imprimirTabuleiro();
}

char RaposaeOvelhas::realizarJogada(Coord origem, Coord destino) {
    try {
        if (turno == PLAYER_1) {
            if (!moverRaposa(origem, destino)) {
                throw std::logic_error("A raposa só se movimenta diagonalmente, em um quadrado de distância.");
            }
        } else if (turno == PLAYER_2) {
            if (!moverOvelha(origem, destino)) {
                throw std::logic_error("A ovelha só se movimenta diagonalmente e para frente, em um quadrado de distância.");
            }
        } else {
            throw std::logic_error("Turno inválido.");
        }

        this->switchTurno();
        return VALID_PLAY;
    } catch (const std::logic_error &e) {
        std::cout << e.what() << std::endl;
        return LOGIC_ERROR;
    } catch (...) {
        std::cout << "Ocorreu um erro inesperado durante a jogada." << std::endl;
        return LOGIC_ERROR;
    }

}


bool RaposaeOvelhas::moverRaposa(Coord origem, Coord destino) {
    if (movimentoValido(origem, destino)){
        tabuleiro->colocarPeca(destino, 'X');
        tabuleiro->colocarPeca(origem, ' ');
        return true;
    }
    return false;
};

bool RaposaeOvelhas::moverOvelha(Coord origem, Coord destino) {
    if (movimentoValido(origem, destino) && destino.getY()>origem.getY()){
        tabuleiro->colocarPeca(destino, 'O');
        tabuleiro->colocarPeca(origem, ' ');
        return true;
    }
    return false;
};

bool RaposaeOvelhas::movimentoValido(Coord origem, Coord destino){
    if (!tabuleiro->posicaoValida(destino) || !tabuleiro->posicaoValida(origem)) return false;
    if (tabuleiro->lerPeca(destino) != ' ') return false;
    int dx = destino.getX() - origem.getX();
    int dy = destino.getY() - origem.getY();
    return (abs(dx) == 1 && abs(dy) == 1);
}