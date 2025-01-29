#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tabuleiro.hpp"

TEST_CASE("Testando a criação de Tabuleiro") {
    SUBCASE("Dimensões válidas") {
        Tabuleiro tab(3, 3); // Tabuleiro 3x3
        CHECK(tab.getAltura() == 3);
        CHECK(tab.getLargura() == 3);
    }

    SUBCASE("Dimensões inválidas") {
        CHECK_THROWS_AS(Tabuleiro(27, 27), std::exception); // Acima do limite 26x26
        CHECK_THROWS_AS(Tabuleiro(0, 0), std::exception);   // Abaixo do limite 1x1
    }
}

TEST_CASE("Testando posições no tabuleiro") {
    Tabuleiro tab(3, 3); // Tabuleiro 3x3

    SUBCASE("Posições válidas") {
        CHECK(tab.posicaoValida(Coord(0, 0)) == true); // (0, 0)
        CHECK(tab.posicaoValida(Coord(2, 2)) == true); // (2, 2)
    }

    SUBCASE("Posições inválidas") {
        CHECK(tab.posicaoValida(Coord(-1, -1)) == false); // Fora do limite negativo
        CHECK(tab.posicaoValida(Coord(3, 3)) == false);   // Fora do limite positivo
    }
}

TEST_CASE("Testando peças no tabuleiro") {
    Tabuleiro tab(3, 3); // Tabuleiro 3x3

    SUBCASE("Colocar e ler peças válidas") {
        CHECK(tab.colocarPeca(Coord(1, 1), 'X') == true);  // Colocar peça 'X'
        CHECK(tab.lerPeca(Coord(1, 1)) == 'X');            // Ler a mesma peça
    }

    SUBCASE("Colocar peça em posição inválida") {
        CHECK(tab.colocarPeca(Coord(-1, -1), 'O') == false); // Fora do limite
    }

    SUBCASE("Sobrescrever peça na mesma posição") {
        CHECK(tab.colocarPeca(Coord(1, 1), 'X') == true);  // Colocar 'X'
        CHECK(tab.colocarPeca(Coord(1, 1), 'O') == false); // Tentar substituir por 'O'
    }
}
