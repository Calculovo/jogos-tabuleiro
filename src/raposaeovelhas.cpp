#include "raposaeovelhas.hpp"
#include <iostream>

RaposaeOvelhas::RaposaeOvelhas(): JogoBase(8, 8){
    tabuleiro->colocarPeca(Coord(0,2), 'R');
    tabuleiro->colocarPeca(Coord(5,1), 'O');
    for (int i=1; i<8; i+=2){
        tabuleiro->colocarPeca(Coord(i,0), 'O');
    }
};

char RaposaeOvelhas::validarJogada(std::string input) {
    Coord destino(1, 1), origem(2,2);
    if (turno == PLAYER_1) { 
        destino = Coord(input);
        if (!tabuleiro->posicaoValida(destino)) {
        std::cout << "Digite uma coordenada válida e sem espaco. Exemplos: A1, C3" << std::endl;
        return SYNTAX_ERROR;
        }
        if (tabuleiro->lerPeca(destino) != ' ') {
        std::cout << "Digite as coordenadas de um espaco em branco." << std::endl;
        return LOGIC_ERROR;
        }
        for (int x = 0; x < tabuleiro->getLargura(); ++x) {
            for (int y = 0; y < tabuleiro->getAltura(); ++y) {
                if (tabuleiro->lerPeca(Coord(x, y)) == 'R') {
                    origem = Coord(x, y);
                    break;
                }
            }
        }
    }
    else{
        if (input.size()<4) return LOGIC_ERROR;
        origem = Coord(input.substr(0, 2));
        destino = Coord (input.substr(2, 2));
        if (!tabuleiro->posicaoValida(origem) || !tabuleiro->posicaoValida(destino)) {
        std::cout << "As coordenadas atuais da ovelha e de seu destino devem ser válidas e digitadas sem espaço. Exemplo: B2C3" << std::endl;
        return SYNTAX_ERROR;
        }
        if (tabuleiro->lerPeca(origem) != 'O' || tabuleiro->lerPeca(destino) != ' ') {
        std::cout << "Digite as coordenadas de um espaço onde há uma ovelha e, em seguida, as de um espaço em branco" << std::endl;
        return LOGIC_ERROR;
        }
    }

    if (turno == PLAYER_1){
        if (moverRaposa(origem, destino)) {
            this->switchTurno();
            return VALID_PLAY;
        }
        else{
            std::cout << "A raposa so se movimenta diagonalmente, em um quadrado de distancia" << std::endl;
        }
    } 
    
    else if (turno == PLAYER_2) {
        if (moverOvelha(origem, destino)) {
            this->switchTurno();
            return VALID_PLAY;
        }
        else{
            std::cout << "A ovelha só se movimenta diagonalmente e para frente, em um quadrado de distância" << std::endl;
        }
    }
    return LOGIC_ERROR;

}

int RaposaeOvelhas::testarVitoria() {
    std::cout<<"testando vitoria"<<std::endl;
    int i = 0, j = 0;

    while (i<8){
        if (j==7){
            j=0;
            i++;
        }
        if (tabuleiro->lerPeca(Coord(j, i)) == 'O') {
            break;
        }
        else if (tabuleiro->lerPeca(Coord(j, i)) == 'R') {
            return PLAYER_1;
        }
        j++;
    }

    bool raposapodemover=0;
    for (i=0; i < 8; i++) {
        for (j=0; j < 8; j++){
           if (tabuleiro->lerPeca(Coord(i, j)) == 'R'){
                Coord posraposa = Coord(i, j);
                std::cout<<"raposa encontrada"<<std::endl;
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

bool RaposaeOvelhas::moverRaposa(Coord origem, Coord destino) {
    if (movimentoValido(origem, destino) && tabuleiro->lerPeca(destino) == ' '){
        tabuleiro->colocarPeca(destino, 'R');
        tabuleiro->colocarPeca(origem, ' ');
        return true;
    }
    return false;
};

bool RaposaeOvelhas::moverOvelha(Coord origem, Coord destino) {
    if (movimentoValido(origem, destino) && tabuleiro->lerPeca(destino) == ' ' && destino.getY()>origem.getY()){
        tabuleiro->colocarPeca(destino, 'O');
        tabuleiro->colocarPeca(origem, ' ');
        return true;
    }
    return false;
};

bool RaposaeOvelhas::movimentoValido(Coord origem, Coord destino){
    if (!tabuleiro->posicaoValida(destino) || !tabuleiro->posicaoValida(origem)) {
        std::cout << "Movimento inválido: origem(" << origem.getX() << ", " << origem.getY() 
                  << ") destino(" << destino.getX() << ", " << destino.getY() << ")" << std::endl;
        return false;
    }
    int dx = destino.getX() - origem.getX();
    int dy = destino.getY() - origem.getY();
    return (abs(dx) == 1 && abs(dy) == 1);
}