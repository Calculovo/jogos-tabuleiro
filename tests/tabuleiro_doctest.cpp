#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/tabuleiro.cpp"
#include "tabuleiro.hpp"
#define INVALID_PLAY  -1 

TEST_CASE("Teste de criação do tabuleiro") {
    Tabuleiro tab(3, 3);
    CHECK(tab.getLargura() == 3);
    CHECK(tab.getAltura() == 3);
}

TEST_CASE("Teste de posição válida") {
    Tabuleiro tab(3, 3);
    CHECK(tab.posicaoValida(0, 0) == true);
    CHECK(tab.posicaoValida(2, 2) == true);
    CHECK(tab.posicaoValida(3, 3) == false);
    CHECK(tab.posicaoValida(-1, 0) == false);
}

TEST_CASE("Teste de colocar peça") {
    Tabuleiro tab(3, 3);
    CHECK(tab.colocarPeca(0, 0, 'X') == true);
    CHECK(tab.lerPeca(0, 0) == 'X');
    CHECK_THROWS_AS(tab.colocarPeca(3, 3, 'O'), std::out_of_range);
    CHECK_THROWS_AS(tab.lerPeca(3, 3), std::out_of_range );
}