#include "reversi.hpp"
#include <iostream>

using namespace std;


// x branca, o preta
Reversi::Reversi() : JogoBase(8) {
        tabuleiro->colocarPeca(Coord(4, 4), 'x');
        tabuleiro->colocarPeca(Coord(5, 5), 'x');
        tabuleiro->colocarPeca(Coord(4, 5), 'o');
        tabuleiro->colocarPeca(Coord(5, 4), 'o');
};