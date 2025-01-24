#include "partida.hpp"
#include "placar.hpp"
#include "jogobase.hpp"
#include <iostream>

void imprimirOpcoesJogos() {
    std::cout << "V - Jogo da Velha;" << std::endl;
    std::cout << "L - Ligue 4;" << std::endl;
    std::cout << "R - Reversi;" << std::endl;
    std::cout << "O - Raposa e Ovelhas;" << std::endl;
    std::cout << "D - Damas;" << std::endl;
    std::cout << "M - Voltar ao Menu Principal." << std::endl;
}

void escolherJogador(Jogador* jogador1, Jogador* jogador2, string apelido_p1, string apelido_p2, Placar placar){
    bool jogador_valido = false;
    while (!jogador_valido){
        std::cout << "Digite o apelido do Jogador 1: ";
        std::cin >> apelido_p1;
        std::cout << std::endl;
        jogador1 = placar.buscarJogador(apelido_p1);
        if (jogador1 != NULL){
            jogador_valido == true;
        }
        else {
        std::cout << "ERRO: Jogador não existe." << std::endl;
        }
    }
    jogador_valido = false;
    while (!jogador_valido){
        std::cout << "Digite o apelido do Jogador 2: ";
        std::cin >> apelido_p2;
        std::cout << std::endl;
        if (apelido_p2 == apelido_p1){
            std::cout << "ERRO: Jogador já selecionado." << std::endl;
        }
        else {
            jogador2 = placar.buscarJogador(apelido_p2);
            if (jogador2 != NULL){
                jogador_valido == true;
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
    bool comando_valido = false;
    if (placar.numeroDeJogadores() < 2) {
        std::cout << "ERRO: quantidade de jogadores insuficiente." << std::endl;
        std::cout << "São necessários, no mínimo, dois jogadores registrados para iniciar uma partida." << std::endl << std::endl;
        return;
    }
    while (!comando_valido){
            
        char comando_jogo;
        string apelido_p1, apelido_p2;
        string comandos_existentes = "VRLOD";

        std::cout << "Qual jogo deseja inciar?" << std::endl << std::endl;
        imprimirOpcoesJogos();
        std::cout << "Digite sua escolha: ";
        std::cin >> comando_jogo;
        std::cout << std::endl << std::endl;

        if (comando_jogo == 'M'){
            comando_valido == true;
        }

        else if (comandos_existentes.find(comando_jogo) != std::string::npos){
            comando_valido == true;
            Jogador*jogador1 = NULL;
            Jogador*jogador2 = NULL;

            escolherJogador(jogador1, jogador2, apelido_p1, apelido_p2, placar);
            Partida partida; //ainda tenho que passar os parâmetros, esperando a classe partida ficar pronta
            partida.jogar();
        }
        
        else {
            std::cout << "ERRO: Comando inválido." << std::endl;
        }
    }
}

void menuHelp(){
    bool comando_valido = false;

    while (!comando_valido){
            
        char comando_help;
        std::cout << "Deseja ler as regras de qual jogo?" << std::endl << std::endl;
        imprimirOpcoesJogos();
        std::cout << "Digite sua escolha: ";
        std::cin >> comando_help;
        std::cout << std::endl;

        if (comando_help == 'M'){
            comando_valido == true;
        }

        else if (comando_help == 'V'){
            comando_valido == true;

        }

        else if (comando_help == 'L'){
            comando_valido == true;

        }

        else if (comando_help == 'R'){
            comando_valido == true;

        }

        else if (comando_help == 'D'){
            comando_valido == true;

        }

        else if (comando_help == 'O'){
            comando_valido == true;

        }

        else {
            std::cout << "ERRO: Comando inválido." << std::endl;
        }
    }
}

int main() {
    Placar placar;

    std::cout << "Seja bem-vindo!" << std::endl << std::endl;
    std::cout << "Prepare-se para mergulhar no mundo dos jogos clássicos de tabuleiro!" <<
    "Aqui, você pode jogar e se divertir com Jogo da Velha, Reversi, Raposa e Ovelhas, Ligue 4 e Damas." << std::endl;
    std::cout << "Se você não conhece ou quer relembrar as regras de algum jogo, não se preocupe!" << 
    "Nosso programa oferece um guia completo para as regras de cada jogo. Basta consultá-las antes de começar." << std::endl << std::endl;
    std::cout << "Para participar das partidas, você precisará registrar os jogadores. O programa também mantém" <<
    " um histórico das suas vitórias e derrotas, permitindo que você acompanhe" <<
    " o desempenho de cada jogador ao longo das partidas." << std::endl << std::endl;
    std::cout <<"Chame seus amigos, desafie seus rivais e aproveite a diversão!" << std::endl << std::endl;

    while(true){
    
        char comando;
        menuPrincipal();
        std::cout << "Digite sua escolha: ";
        std::cin >> comando;
        std::cout << std::endl << std::endl;

        if (comando=='P'){
            menuPartida(placar);
        }

        else if (comando=='C'){
            string nome, apelido;
            std::cout << "Digite o apelido do novo jogador:";
            std::cin >> apelido;
            std::cout << std::endl;
            std::cout << "Digite o nome do novo jogador:";
            std::cin >> nome;
            std::cout << std::endl;

            placar.adicionarJogador(apelido, nome);
        }

        else if (comando=='R'){
            string apelido;
            std::cout << "Digite o apelido do jogador a ser removido";
            std::cin >> apelido;
            std::cout << std::endl;
            
            placar.removerJogador(apelido);
        }

        else if (comando=='L'){
            char modo;
            std::cout << "Como deseja listar os jogadores?" << std::endl;
            std::cout << "A - Por apelido;" <<std::endl;
            std::cout << "N - Por nome;" <<std::endl;
            std::cout << "Digite sua escolha:";
            std::cin >> modo;
            std::cout << std::endl;

            placar.listarJogadores(modo);
        }

        else if (comando=='H'){
            menuHelp();
        }

        else if (comando=='S'){
            std::cout << "Obrigado por jogar!" << std::endl;
            return 0;
        }

        else {
            std::cout << "ERRO: Comando inválido." << std::endl;
        }
    }
    return 0;
}