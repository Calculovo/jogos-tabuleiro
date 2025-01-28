#ifndef PLACAR_I
#define PLACAR_I

#include "jogador.hpp"
#include <list>
#include <string>

class Placar {
    private:
        //! Lista de jogadores registrados.
        std::list<Jogador> jogadores;
    public:
        //! Inicializa o placar.
        /*!
            Se o arquivo stats.tsv é encontrado, lê esse arquivo para recuperar estatísticas.
            Se o arquivo não é encontrado, o placar é inicializado em branco.
        */
        Placar();
        //! Destrutor. Garante que as estatísticas não serão perdidas
        /*!
            Para garantir que as estatísticas não serão perdidas, chama escreverArquivo().
        */
        ~Placar();
        //! Escreve as estatísticas no arquivo stats.tsv.
        /*!
            O arquivo lista apelido e nome de cada jogador, seguido de linhas de três valores (vitórias, empates e derrotas) em cada jogo.
        */
        void escreverArquivo() const;
        //! Adiciona um jogador quando dado seu nome e apelido.
        /*!
            Se um jogador já usa o apelido dado, imprime uma mensagem de erro.
            Do contrário, constrói e adiciona o jogador no final da lista.
        */
        void adicionarJogador(std::string apelido, std::string nome);
        //! Remove um jogador quando dado seu apelido.
        /*!
            Se nenhum jogador usa o apelido dado, imprime uma mensagem de erro.
            Do contrário, constrói e adiciona o jogador no final da lista.
        */
        void removerJogador(std::string apelido);
        //! Ordena os jogadores por nome ou apelido e imprime suas informações.
        /*!
            Se modo é 'A', usa o apelido para ordenar os jogadores.
            Se modo é 'N', usa o nome para ordenar os jogadores.
            Se modo é qualquer outro char, joga uma exceção.
            Após ordenar a lista, imprime nome, apelido e estatísticas de cada jogador.
        */
        void listarJogadores(char modo);
        //! Da um ponteiro para o jogador com o ID dado.
        /*!
            Se o jogador nao existe, retorna nullptr.
        */
        Jogador* buscarJogador(std::string apelido);
        //! Retorna a quantidade de jogadores registrados.
        unsigned int numeroDeJogadores();
};

#endif