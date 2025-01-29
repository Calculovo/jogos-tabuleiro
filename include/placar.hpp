#ifndef PLACAR_I
#define PLACAR_I

#include "jogador.hpp"
#include <list>
#include <string>

//! Classe responsável por manter os jogadores e suas estatísticas.
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
            O arquivo lista apelido e nome de cada jogador,
            seguido de linhas de três valores (vitórias, empates e derrotas) em cada jogo.
        */
        void escreverArquivo() const;
        //! Verifica se uma string pode ser usada como apelido.
        /*!
            Apelidos somente podem utilizar letras minusculas, numerais, e underline('_').
            Ademais, eles devem ter pelo menos dois caracteres.
        */
        static bool validarApelido(std::string apelido);
        //! Verifica se uma string pode ser usada como nome.
        /*!
            Nomes somente podem usar caracteres ASCII de texto, não de controle.
            Ademais, eles devem ter pelo menos dois caracteres.
        */
        static bool validarNome(std::string nome);
        //! Adiciona um jogador quando dado seu nome e apelido.
        /*!
            Se outro jogador já usa o apelido dado, joga std::range_error.
            Se o nome ou apelido não é válido, joga std::invalid_argument.
            Do contrário, constrói e adiciona o jogador no final da lista.
        */
        void adicionarJogador(std::string apelido, std::string nome);
        //! Remove um jogador quando dado seu apelido.
        /*!
            Se nenhum jogador usa o apelido dado, joga std::invalid_argument.
            Do contrário, constrói e adiciona o jogador no final da lista.
        */
        void removerJogador(std::string apelido);
        //! Ordena os jogadores por nome ou apelido e imprime suas informações.
        /*!
            Se modo é 'A', usa o apelido para ordenar os jogadores.
            Se modo é 'N', usa o nome para ordenar os jogadores.
            Se modo é qualquer outro char, joga std::invalid_argument.
            Após ordenar a lista, imprime nome, apelido e estatísticas de cada jogador.
        */
        void listarJogadores(char modo);
        //! Dá um iterador para o jogador com o ID dado.
        /*!
            Se o jogador nao existe, joga std::invalid_argument.
        */
        std::list<Jogador>::iterator buscarJogador(std::string apelido);
        //! Retorna a quantidade de jogadores registrados.
        unsigned int numeroDeJogadores();
};

#endif