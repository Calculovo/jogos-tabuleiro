#ifndef LIGUE4_HPP
#define LIGUE4_HPP

#include "jogobase.hpp"

class Ligue4 : public JogoBase {
public:
    //! Construtor para inicializar o tabuleiro 7x6
    Ligue4(); 
    //! Valida uma jogada
    char validarJogada(std::string input) override;
    //! Verifica se há um vencedor
    int testarVitoria() override;
    //! Exibe o tabuleiro
    void imprimirTabuleiro() override; 
private:
    //! Verifica sequência de 4 peças
    bool verificarSequencia(Coord inicio, Coord direcao, char peca); 
};

#endif

