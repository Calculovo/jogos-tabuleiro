#ifndef JOGO_DA_VELHA_I
#define JOGO_DA_VELHA_I 1

#include "jogobase.hpp"

class JogoDaVelha : public JogoBase {
    public:
        //! Construtor padrão. Inicializa um Jogo Da Velha 3x3.
        JogoDaVelha();
        //! Construtor. Inicializa um Jogo Da Velha de tamanho arbitrário.
        JogoDaVelha(int tamanho);
        //! Verifica se uma jogada é válida, e se for, a executa.
        /*!
            Se a string não está no formato "A1", imprime uma mensagem
            e retorna SYNTAX_ERROR.
            Se a string está no formato correto, mas não aponta para uma célula
            vazia do tabuleiro, retorna LOGIC_ERROR.
            Se a string está no formato correto e apponta para uma célula vazia,
            retorna VALID_PLAY.
        */
        char validarJogada(std::string input) override;
        //! Verifica se uma sequência de células tem o mesmo conteúdo.
        /*!
            Verifica se [tamanho] células, iniciando em [inicial]
            e seguindo na direção [direcao], têm todas o mesmo valor não-vazio.
            Se sim, retorna esse valor. Se não, retorna INDEFINIDO.
        */
        int testarReta(Coord inicial, Coord direcao, int tamanho);
        //! Verifica se um dos dois jogadores ganhou o jogo.
        /*!
            Verifica se um dos dois jogadores tem
            uma coluna, linha ou diagonal composta somente de suas células.
            Se um dos jogadores tem uma fila completa,
            retorna o código desse jogador.
            Se nenhum dos dois tem uma fila, mas ainda há espaço em branco,
            retorna INDEFINIDO.
            Se não há células em branco, retorna EMPATE.
        */
        int testarVitoria() override;
};

#endif