#include "reversi.hpp"
#include <iostream>
#include <vector>
#include <sstream>

#define TAM_TABULEIRO 8

Reversi::Reversi() : JogoBase(TAM_TABULEIRO) {
        tabuleiro->colocarPeca(Coord(3, 3), 'X');
        tabuleiro->colocarPeca(Coord(4, 4), 'X');
        tabuleiro->colocarPeca(Coord(3, 4), 'O');
        tabuleiro->colocarPeca(Coord(4, 3), 'O');

        turno = PLAYER_1;
};


bool Reversi::conferirDirecoes(Coord coord){
        char oponente = (turno == PLAYER_1) ? PLAYER_2 : PLAYER_1;

        int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (auto& direcao : direcoes) {
                int dx = direcao[0];
                int dy = direcao[1];
                int newx = coord.getX() + dx;
                int newy = coord.getY() + dy;
                bool encontrouOponente = false;


                while (tabuleiro->posicaoValida(newx, newy) && tabuleiro->lerPeca(newx, newy) == oponente) {
                        newx += dx;
                        newy += dy;
                        encontrouOponente = true;
                }

                if (encontrouOponente && tabuleiro->posicaoValida(newx, newy) && tabuleiro->lerPeca(newx, newy) == turno) {
                        return true;
                        break; 
                }
        }

        return false;
}


char Reversi::existeJogadaLegal() {
        for (char x = 'A'; x <= 'H'; ++x) {
                for (int y = 0; y < TAM_TABULEIRO; ++y) {
                        Coord coordenada(x - 'A', y);

                        if (tabuleiro->lerPeca(coordenada) != VAZIO) {
                                continue;
                        }

                        bool jogadaValida = conferirDirecoes(coordenada);

                        if (jogadaValida) {
                                return VALID_PLAY;
                        }
                }
        }

        std::cout << "Fim de jogo: Não há mais jogadas válidas!" << std::endl;
        return INVALID_PLAY;
}


char Reversi::checarJogadaLegal(std::string input) {
        try{
                if (input.size() != 2) {
                        throw std::invalid_argument("Entrada inválida.");
                }

                int x = input[0] - 'A';
                int y = input[1] - '1';

                if (x < 0 || x >= TAM_TABULEIRO || y < 0 || y >= TAM_TABULEIRO) {
                        throw std::out_of_range("Coordenada fora dos limites do tabuleiro.");
                }


                Coord colocar(x,y);

                if(tabuleiro->lerPeca(colocar) != VAZIO){
                        throw std::logic_error("Essa coordenada já possui uma peça");
                }
                
                bool jogadaValida = conferirDirecoes(colocar);


                return jogadaValida ? VALID_PLAY : INVALID_PLAY;
        }catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                return SYNTAX_ERROR;
        } catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
                return LOGIC_ERROR;
        } catch (const std::logic_error& e) {
                std::cout << e.what() << std::endl;
                return LOGIC_ERROR;
        } catch (...) {
                std::cout << "Erro desconhecido na checagem da jogada." << std::endl;
                return INVALID_PLAY;
        }
};


char Reversi::validarJogada(std::string input){
        try{
                if (existeJogadaLegal() == INVALID_PLAY) {
                        throw std::runtime_error("Fim de jogo. Não há mais jogadas válidas!");
                }

                if (checarJogadaLegal(input) == VALID_PLAY) {
                        int x = input[0] - 'A';
                        int y = input[1] - '1';
                        Coord colocar(x, y);


                        tabuleiro->colocarPeca(colocar, turno);
                        inverterPecas(colocar); 
                        switchTurno();
                        return VALID_PLAY;
                } else {
                        std::cout << "Digite uma coordenada válida. Exemplo: A1." << std::endl;
                        return INVALID_PLAY;
                }
        }catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
                return INVALID_PLAY;
        } catch (...) {
                std::cout << "Erro desconhecido ao validar a jogada." << std::endl;
                return INVALID_PLAY;
        }
};


int Reversi::testarVitoria(){
        if (existeJogadaLegal() == VALID_PLAY){
                return INDEFINIDO;
        }
        int countX = 0, countO = 0;
        for (int i = 0; i < TAM_TABULEIRO; i++) {
                for (int j = 0; j < TAM_TABULEIRO; j++) {
                char peca = tabuleiro->lerPeca(i, j);
                if (peca == PLAYER_1) countX++;
                if (peca == PLAYER_2) countO++;
                }
        }

        std::cout << "peças x: " << countX << std::endl;
        std::cout << "peças O: " << countO << std::endl;

        if (countO > countX) {
                return PLAYER_2;
        }
        if (countX > countO) {
                return PLAYER_1;
        }
        if (countX == countO) {
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
                std::vector<Coord> pecasInverter;
        
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