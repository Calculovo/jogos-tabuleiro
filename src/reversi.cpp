#include "reversi.hpp"
#include <iostream>
#include <vector>

using namespace std;

#define preto 'O'
#define branco 'X'
#define TAM_TABULEIRO 8


// x branca, o preta
Reversi::Reversi() : JogoBase(TAM_TABULEIRO) {
        tabuleiro->colocarPeca(Coord(4, 4), 'branco');
        tabuleiro->colocarPeca(Coord(5, 5), 'branco');
        tabuleiro->colocarPeca(Coord(4, 5), 'preto');
        tabuleiro->colocarPeca(Coord(5, 4), 'preto');

        turno = PLAYER_1;
};


char Reversi::existeJogadaLegal() {
        for (int x = 0; x < TAM_TABULEIRO; ++x) {
                for (int y = 0; y < TAM_TABULEIRO; ++y) {
            
            


                }
        }
        cout << "Fim de jogo: Não há mais jogadas válidas!" << endl;
        testarVitoria();
        return INVALID;
}


char Reversi::validarJogada(string input) {
        Coord colocarPeca (input);

        char oponente = (turno == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        bool jogadaValida = false;

        char peca = tabuleiro->lerPeca(colocarPeca);

        if (peca != tabuleiro->posicaoValida(colocarPeca)) {
                cout << "A coordenada não existe no tabuleiro" << endl;
                return LOGIC_ERROR;
        }
        if(tabuleiro->lerPeca(colocarPeca) != VAZIO){
                cout << "Essa coordenada já possui uma peça" << endl;
                return LOGIC_ERROR;
        }

        int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (auto& direcao : direcoes) {
                int dx = direcao[0];
                int dy = direcao[1];
                int x = colocarPeca.getX() + dx;
                int y = colocarPeca.getY() + dy;
                bool encontrouOponente = false;
        
                while (tabuleiro->posicaoValida(x, y) && tabuleiro->lerPeca(x, y) == oponente) {
                        x += dx;
                        y += dy;
                        encontrouOponente = true;
                }

                if (encontrouOponente && tabuleiro->posicaoValida(x, y) && tabuleiro->lerPeca(x, y) == turno) {
                        jogadaValida = true;
                }
        }

        return jogadaValida ? VALID_PLAY : INVALID;
};


void Reversi::colocarPeca(string input){
        Coord colocar(input);
        if (validarJogada(input) == VALID_PLAY) {
                tabuleiro->colocarPeca(colocar, turno);
        
                inverterPecas(colocar); 
                switchTurno();
        } else {
                cout << "Digite uma coordenada válida. Exemplos: A1." << endl;
        }
};


int Reversi::testarVitoria(){
        int countX, countO;
        for (int i = 0; i < TAM_TABULEIRO; i++) {
                for (int j = 0; j < TAM_TABULEIRO; j++) {
                char peca = tabuleiro->lerPeca(i, j);
                if (peca == PLAYER_1) countX++;
                if (peca == PLAYER_2) countO++;
                }
        }
        if (countO > countX) {
                cout << "Jogador 2 venceu." << endl;
                return PLAYER_2;
        }
        if (countX > countO) {
                cout << "Jogador 1 venceu." << endl;
                return PLAYER_1;
        }
        if (countX == countO) {
                cout << "Empate." << endl;
                return EMPATE;
        }
        return INDEFINIDO;

};


void Reversi::inverterPecas(Coord coord){
        char oponente = (turno == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (auto& direcao : direcoes) {
                int dx = direcao[0];
                int dy = direcao[1];
                int x = coord.getX() + dx;
                int y = coord.getY() + dy;
                bool encontrouOponente = false;
                vector<Coord> pecasInverter;
        
                while (tabuleiro->posicaoValida(x, y) && tabuleiro->lerPeca(x, y) == oponente) {
                        pecasInverter.push_back(Coord(x, y));
                        x += dx;
                        y += dy;
                        encontrouOponente = true;
                }

                if (encontrouOponente && tabuleiro->posicaoValida(x, y) && tabuleiro->lerPeca(x, y) == turno) {
                        for (auto& peca : pecasInverter) {
                        tabuleiro->colocarPeca(peca, turno);
                }
                }
        }
        return;

};