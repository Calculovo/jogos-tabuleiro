#include "partida.hpp"
#include "placar.hpp"
#include "jogobase.hpp"
#include <iostream>

void coletaCaracter(char& comando){
    string comandoString;
    do {
        std::cout << "Digite sua escolha: ";
        getline (cin, comandoString);
        std::cout << std::endl;

        if (comandoString.size() !=1){
            std::cout << "ERRO: Comando inválido." << std::endl;
        }
    } while (comandoString.size() != 1);

    comando = comandoString[0];
}

void imprimirOpcoesDeJogos() {
    std::cout << "V - Jogo da Velha;" << std::endl;
    std::cout << "L - Ligue 4;" << std::endl;
    std::cout << "R - Reversi;" << std::endl;
    std::cout << "O - Raposa e Ovelhas;" << std::endl;
    std::cout << "D - Damas;" << std::endl;
    std::cout << "M - Voltar ao Menu Principal." << std::endl << std::endl;
}

void escolherJogador(Jogador*& jogador1, Jogador*& jogador2, std::string apelido_p1, std::string apelido_p2, Placar& placar){
    bool jogadorValido = false;
    while (!jogadorValido){
        std::cout << "Digite o apelido do Jogador 1: ";
        getline(cin, apelido_p1);
        std::cout << std::endl;
        jogador1 = placar.buscarJogador(apelido_p1);
        if (jogador1 != nullptr){
            jogadorValido = true;
        }
        else {
        std::cout << "ERRO: Jogador não existe." << std::endl;
        }
    }
    jogadorValido = false;
    while (!jogadorValido){
        std::cout << "Digite o apelido do Jogador 2: ";
        getline(cin, apelido_p2);
        std::cout << std::endl;
        if (apelido_p2 == apelido_p1){
            std::cout << "ERRO: Jogador já selecionado." << std::endl;
        }
        else {
            jogador2 = placar.buscarJogador(apelido_p2);
            if (jogador2 != nullptr){
                jogadorValido = true;
            }
            else {
            std::cout << "ERRO: Jogador não existe." << std::endl;
            }
        }
    }
}

void menuPrincipal() {
    std::cout << "O que deseja fazer?" << std::endl << std::endl;
    std::cout << "P - Inicar uma nova partida;" << std::endl;
    std::cout << "C - Cadastrar um novo jogador;" << std::endl;
    std::cout << "R - Remover um jogador existente;" << std::endl;
    std::cout << "L - Listar informações dos jogadores;" << std::endl;
    std::cout << "H - Ler as regras de algum jogo;" << std::endl;
    std::cout << "S - Sair." << std::endl << std::endl;
}

void menuPartida(Placar placar){
    bool comandoValido = false;
    if (placar.numeroDeJogadores() < 2) {
        std::cout << "ERRO: quantidade de jogadores insuficiente." << std::endl;
        std::cout << "São necessários, no mínimo, dois jogadores cadastrados para iniciar uma partida." << std::endl << std::endl;
        return;
    }
    while (!comandoValido){
            
        char comandoJogo;
        
        std::string apelido_p1, apelido_p2;
        std::string comandosExistentes = "VRLOD";

        std::cout << "Qual jogo deseja inciar?" << std::endl << std::endl;
        imprimirOpcoesDeJogos();
        coletaCaracter(comandoJogo);

        if (comandoJogo == 'M'){
            comandoValido = true;
        }

        else if (comandosExistentes.find(comandoJogo) != std::string::npos){
            comandoValido = true;
            Jogador* jogador1 = NULL;
            Jogador* jogador2 = NULL;

            escolherJogador(jogador1, jogador2, apelido_p1, apelido_p2, placar);
            Partida partida(comandoJogo, jogador1, jogador2);
            partida.jogar();
        }
        
        else {
            std::cout << "ERRO: Comando inválido." << std::endl;
        }
    }
}

void menuHelp(){
    bool comandoValido = false;

    while (!comandoValido){
        
        char comandoHelp;
        std::cout << "Deseja ler as regras de qual jogo?" << std::endl << std::endl;
        imprimirOpcoesDeJogos();

        coletaCaracter(comandoHelp);

        switch (comandoHelp) {
            case 'M':
                comandoValido = true;
                break;

            case cVELHA:
                comandoValido = true;
                std::cout << "Regras a serem escritas" << std::endl;
                break;

            case cLIG4:
                comandoValido = true;
                std::cout << "Regras a serem escritas" << std::endl;
                break;

            case cREVERSI:
                std::cout << "Bem vindo às regras do REVERSI!" << std::endl;
                std::cout << "Objetivo: ter o maior número de peças da sua cor viradas pra cima ao fim da partida." << std::endl;
                std::cout << "Regras para colocar peças: Para fazer uma jogada válida você deve colocar uma peça de forma que vire, pelo menos, uma peça do seu oponente;" << std::endl;
                std::cout << "As peças podem ser viradas na vertical, horizontal e diagonal ao mesmo tempo, desde que haja uma peça sua cercando as peças do seu oponente na direção;" << std::endl;
                std::cout << "Fim de jogo: o jogo termina quando algum jogador não tiver mais jogadas válidas ou quando o tabuleiro estiver cheio." << std::endl;
                std::cout << "Dica: seja estratégico, pense nos possíveis movimentos do seu oponente, ";
                std::cout << "lembre que, para ganhar, o que importa é o tabuleiro final!" << std::endl;

                comandoValido = true;
                break;

            case cDAMAS:
                comandoValido = true;
                std::cout << "Regras a serem escritas" << std::endl;
                break;

            case cRAPOSA:
                comandoValido = true;
                std::cout << "Regras a serem escritas" << std::endl;
                break;

            default:
                std::cout << "ERRO: Comando inválido." << std::endl;
                break;
        }
    }
}

int main() {
    Placar placar;

    std::cout << "Seja bem-vindo ao Fliperama!" << std::endl << std::endl;
    std::cout << "Prepare-se para mergulhar no mundo dos jogos clássicos de tabuleiro!" <<
    "Aqui, você pode jogar e se divertir com o Jogo da Velha, Reversi, Raposa e Ovelhas, Ligue 4 e Damas." << std::endl;
    std::cout << "Se você não conhece ou quer relembrar as regras de algum jogo, não se preocupe!" << 
    "Nosso programa oferece um guia completo para as regras de cada jogo. Basta consultá-las antes de começar." << std::endl << std::endl;
    std::cout << "Para participar das partidas, você precisará cadastrar os jogadores. O programa também mantém" <<
    " um histórico das suas vitórias e derrotas, permitindo que você acompanhe" <<
    " o desempenho de cada jogador ao longo das partidas." << std::endl << std::endl;
    std::cout <<"Chame seus amigos, desafie seus rivais e aproveite a diversão!" << std::endl << std::endl;

    while(true){
    
        string comandoString;
        char comando;
        menuPrincipal();

        coletaCaracter(comando);

        switch (comando) {
            case 'P':
                menuPartida(placar);
                break;

            case 'C': {
                std::string nome, apelido;
                std::cout << "Digite o apelido do novo jogador: ";
                getline (cin, apelido);
                std::cout << std::endl;
                std::cout << "Digite o nome do novo jogador: ";
                getline (cin,nome);
                std::cout << std::endl;

                placar.adicionarJogador(apelido, nome);
                break;
            }

            case 'R': {
                std::string apelido;
                std::cout << "Digite o apelido do jogador a ser removido:";
                getline (cin, apelido);
                std::cout << std::endl;

                placar.removerJogador(apelido);
                break;
            }

            case 'L': {
                char modo;
                std::cout << "Como deseja listar os jogadores?" << std::endl;
                std::cout << "A - Por apelido;" << std::endl;
                std::cout << "N - Por nome;" << std::endl << std::endl;
                std::cout << "Digite sua escolha: ";
                coletaCaracter(modo);

                placar.listarJogadores(modo);
                
                break;
            }

            case 'H':
                menuHelp();
                break;

            case 'S':
                std::cout << "Obrigado por jogar!" << std::endl;
                return 0;

            default:
                std::cout << "ERRO: Comando inválido." << std::endl;
                break;
        }
    }
    return 0;
}