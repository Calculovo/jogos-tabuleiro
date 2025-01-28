#include "doctest.h"
#include "jogodavelha.hpp"

//! Teste para a validação das jogadas
TEST_CASE("Testando a validação da jogada") {
    JogoDaVelha jogo;
    
    //! Testa jogada válida
    CHECK(jogo.validarJogada("A1") == VALID_PLAY);
    
    //! Testa jogada inválida (já ocupada)
    CHECK(jogo.validarJogada("A1") == LOGIC_ERROR);
    
    //! Testa jogada inválida (coordenada errada)
    CHECK(jogo.validarJogada("Z9") == SYNTAX_ERROR);
}

//! Teste para a lógica de vitória
TEST_CASE("Testando a vitória") {
    JogoDaVelha jogo;
    
    //! Simula um jogo onde o jogador 1 vence
    jogo.validarJogada("A1");
    jogo.validarJogada("B1");
    jogo.validarJogada("A2");
    jogo.validarJogada("B2");
    jogo.validarJogada("A3");

    //! Verifica se o jogador 1 venceu
    CHECK(jogo.testarVitoria() == 'X');  //! Supondo que 'X' representa o jogador 1
}

//! Teste para verificar empate
TEST_CASE("Testando o empate") {
    JogoDaVelha jogo;

    //! Simula um jogo onde há empate
    jogo.validarJogada("A1");
    jogo.validarJogada("A2");
    jogo.validarJogada("B1");
    jogo.validarJogada("B2");
    jogo.validarJogada("C1");
    jogo.validarJogada("C3");
    jogo.validarJogada("A3");
    jogo.validarJogada("B3");
    jogo.validarJogada("C2");

    //! Verifica se houve empate
    CHECK(jogo.testarVitoria() == EMPATE);
}

//! Função main para rodar os testes
int main(int argc, char** argv) {
    doctest::Context context;
    context.setOption("no-color", true);
    return context.run();  //! Roda os testes
}
