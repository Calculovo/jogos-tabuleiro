#ifndef LIGUE4_HPP
#define LIGUE4_HPP

#include "jogobase.hpp"

class Ligue4 : public JogoBase {
public:
    Ligue4(); // Construtor para inicializar o tabuleiro 7x6
    char validarJogada(std::string input) override; // Valida uma jogada
    int testarVitoria() override; // Verifica se há um vencedor
    void imprimirTabuleiro() override; // Exibe o tabuleiro
private:
    bool verificarSequencia(Coord inicio, Coord direcao, char peca); // Verifica sequência de 4 peças
};

#endif

