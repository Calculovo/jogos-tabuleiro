#ifndef LIGUE4_HPP
#define LIGUE4_HPP

#include "jogobase.hpp"

/*!
 * \class Ligue4
 * \brief Classe que representa o jogo Ligue 4.
 *
 * A classe `Ligue4` herda de `JogoBase` e implementa as regras específicas do jogo Ligue 4.
 * Isso inclui a validação de jogadas, verificação de vitórias, e a lógica para alternância
 * entre turnos dos jogadores.
 */
class Ligue4 : public JogoBase {
public:
    //! Construtor da classe Ligue4.
    /*!
     * Inicializa o tabuleiro padrão do jogo com 7 colunas e 6 linhas.
     */
    Ligue4();

    //! Valida uma jogada realizada no jogo.
    /*!
     * \param input String representando a jogada (ex.: "A", "B", etc.).
     * \return Um código que indica o status da jogada:
     *         - `VALID_PLAY`: Jogada válida.
     *         - `SYNTAX_ERROR`: Entrada inválida.
     *         - `LOGIC_ERROR`: Jogada não permitida.
     */
    char validarJogada(std::string input) override;

    //! Testa se há uma condição de vitória no jogo.
    /*!
     * Verifica se um jogador conseguiu alinhar 4 peças consecutivas horizontalmente,
     * verticalmente ou diagonalmente. Também verifica se o jogo terminou em empate.
     * \return Um inteiro representando o estado do jogo:
     *         - `PLAYER_1`: Jogador 1 venceu.
     *         - `PLAYER_2`: Jogador 2 venceu.
     *         - `EMPATE`: O jogo terminou empatado.
     *         - `INDEFINIDO`: O jogo continua.
     */
    int testarVitoria() override;

    //! Imprime o estado atual do tabuleiro no console.
    /*!
     * Exibe uma representação visual do tabuleiro com as jogadas realizadas
     * pelos jogadores até o momento.
     */
    void imprimirTabuleiro() override;

private:
    //! Verifica uma sequência de peças no tabuleiro.
    /*!
     * \param inicio Coordenada inicial da sequência.
     * \param direcao Direção do movimento (horizontal, vertical ou diagonal).
     * \param peca Identificador da peça a ser verificada.
     * \return `true` se houver 4 peças consecutivas; caso contrário, `false`.
     */
    bool verificarSequencia(Coord inicio, Coord direcao, char peca);
};

#endif

