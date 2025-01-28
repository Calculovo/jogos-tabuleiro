#include "partida.hpp"
#include "placar.hpp"
#include "jogobase.hpp"
#include <iostream>

//!Coleta um único caractere como entrada do usuário.
//!Se forem dados mais de um caractere como entrada, imprime uma mensagem de erro até que um único caractere seja dado.

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

//!Exibe as opções de jogos disponíveis e seus comandos correspondentes.

void imprimirOpcoesDeJogos() {
    std::cout << "V - Jogo da Velha;" << std::endl;
    std::cout << "L - Ligue 4;" << std::endl;
    std::cout << "R - Reversi;" << std::endl;
    std::cout << "O - Raposa e Ovelhas;" << std::endl;
    std::cout << "D - Damas;" << std::endl;
    std::cout << "M - Voltar ao Menu Principal." << std::endl << std::endl;
}

//!Exibe instruções específicas sobre como devem ser digitados os inputs do jogo selecionado.
//!Recebe o comando do jogo escolhido como parâmetro.
void imprimirInstrucoes(char comandoJogo) {
    switch (comandoJogo) {
        case cDAMAS:
            std::cout << "Lembre-se, as jogadas devem ser digitadas em letra maíuscula e sem espaço, sendo a coordenada de origem seguida da coordenada de destino." << std::endl;
            std::cout << "Exemplos: A2B3, C6D5" << std::endl;
        break;

        case cRAPOSA:
            std::cout << "Lembre-se, as jogadas devem ser digitadas em letra maíuscula e sem espaço."<< std::endl;
            std::cout << "Para mover a raposa, deve ser digitada somente a coordenada de destino. Exemplos: A1, C3" << std::endl;
            std::cout << "Para mover uma ovelha, deve ser digitada a coordenada de origem seguida da coordenada de destino. Exemplos: A2B3, D1E2" << std::endl;
        break;

        default:
        std::cout << "Lembre-se, as jogadas devem ser digitadas em letra maíuscula e sem espaço. Exemplos: A1, C3" << std::endl;
        break;
    }
    std::cout << "Digite o comando S para sair do jogo a qualquer momento." << std::endl << std::endl;
}

//! Solicita ao usuário que selecione dois jogadores cadastrados no placar.
//! Recebe ponteiros para os jogadores e o placar como parâmetro, por referência.
void escolherJogador(Jogador*& jogador1, Jogador*& jogador2, Placar& placar){
    string apelido1, apelido2;
    bool jogadorValido = false;
    while (!jogadorValido){
        std::cout << "Digite o apelido do Jogador 1: ";
        getline(cin, apelido1);
        std::cout << std::endl;
        jogador1 = placar.buscarJogador(apelido1);
        if (jogador1 != nullptr){
            jogadorValido = true;
        }
        else {
        std::cout << "ERRO: Jogador não existe." << std::endl << std::endl;
        }
    }
    jogadorValido = false;
    while (!jogadorValido){
        std::cout << "Digite o apelido do Jogador 2: ";
        getline(cin, apelido2);
        std::cout << std::endl;
        if (apelido2 == apelido1){
            std::cout << "ERRO: Jogador já selecionado." << std::endl << std::endl;
        }
        else {
            jogador2 = placar.buscarJogador(apelido2);
            if (jogador2 != nullptr){
                jogadorValido = true;
            }
            else {
            std::cout << "ERRO: Jogador não existe." << std::endl << std::endl;
            }
        }
    }
}

//!Exibe a lista dos comandos principais do programa
void menuPrincipal() {
    std::cout << "O que deseja fazer?" << std::endl << std::endl;
    std::cout << "P - Inicar uma nova partida;" << std::endl;
    std::cout << "C - Cadastrar um novo jogador;" << std::endl;
    std::cout << "R - Remover um jogador existente;" << std::endl;
    std::cout << "L - Listar informações dos jogadores;" << std::endl;
    std::cout << "H - Ler as regras de algum jogo;" << std::endl;
    std::cout << "S - Sair." << std::endl << std::endl;
}

//! Gerencia o menu de seleção da partida
/*!
    Receba o placar como parâmetro por referência.
    Verifica se há jogadores suficientes. 
    Se sim, inicia o jogo cujo comando é dado como input pelo usuário, e solicita que escolha os jogadores.
    Ao final,usa a função placar.escreverArquivo() para atualizar o arquivo do placar de acordo com o resultado da partida.
*/

void menuPartida(Placar& placar){
    bool comandoValido = true;
    if (placar.numeroDeJogadores() < 2) {
        std::cout << "ERRO: quantidade de jogadores insuficiente." << std::endl;
        std::cout << "São necessários, no mínimo, dois jogadores cadastrados para iniciar uma partida." << std::endl << std::endl;
        return;
    }
    do{
        char comandoJogo;
        
        std::string apelido_p1, apelido_p2;
        std::string comandosExistentes = "VRLOD";

        std::cout << "Qual jogo deseja inciar?" << std::endl << std::endl;
        imprimirOpcoesDeJogos();
        coletaCaracter(comandoJogo);

        if (comandoJogo == 'M'){
            break;
        }

        else if (comandosExistentes.find(comandoJogo) != std::string::npos){
            Jogador* jogador1 = nullptr;
            Jogador* jogador2 = nullptr;
            
            escolherJogador(jogador1, jogador2, placar);

            imprimirInstrucoes(comandoJogo);
            
            Partida partida(comandoJogo, jogador1, jogador2);
            partida.jogar();
            placar.escreverArquivo();

            delete jogador1;
            delete jogador2;
        }
        
        else {
            comandoValido = false;
            std::cout << "ERRO: Comando inválido." << std::endl << std::endl;
        }
    } while (!comandoValido);
}

//!Exibe as regras dos jogos
/*!
    Pede para o usuário digitar o comando do jogo cujas regras deja ler.
    Exibe as regras desse jogo.
*/
void menuHelp(){
    bool comandoValido = true;

    do{
        char comandoHelp;
        std::cout << "Deseja ler as regras de qual jogo?" << std::endl << std::endl;
        imprimirOpcoesDeJogos();

        coletaCaracter(comandoHelp);

        switch (comandoHelp) {
            case 'M':
                break;

            case cVELHA:
                std::cout << "Regras do JOGO DA VELHA:" << std::endl;
                std::cout << "Objetivo: Colocar três peças da sua cor em uma linha, coluna, ou diagonal. As peças do jogador 1 são representadas por 'X' e as do jogador 2 são representadas por 'O'." << std::endl;
                std::cout << "Regras para colocar peças: Você só pode colocar peças em espaços em branco do tabuleiro 3x3, e jogadores alternam colocando peças." << std::endl;
                std::cout << "Se não houver espaços em branco, e nenhum jogador tiver uma linha, coluna, ou diagonal, o jogo é um empate." << std::endl;
                break;

            case cLIG4:
                std::cout << "Regras do jogo LIGUE 4:" << std::endl;
                std::cout << "Objetivo: alinhar quatro peças da sua cor em linha reta, seja na horizontal, vertical ou diagonal." << std::endl;
                std::cout << "Regras para colocar peças: A cada jogada, você deve escolher uma coluna para colocar sua peça. A peça irá cair até a posição mais baixa disponível dentro dessa coluna." << std::endl;
                std::cout << "A partida é jogada por dois jogadores, alternadamente, e cada jogador deve tentar bloquear o oponente enquanto tenta alinhar suas próprias peças." << std::endl;
                std::cout << "Fim de jogo: O jogo termina quando um jogador conseguir alinhar quatro peças consecutivas ou quando todas as células do tabuleiro estiverem preenchidas (empate)." << std::endl;
                std::cout << "Dica: Fique atento tanto ao seu objetivo de alinhar 4 peças quanto às possíveis ameaças do seu oponente!" << std::endl << std::endl;

                break;

            case cREVERSI:
                std::cout << "Regras do jogo REVERSI:" << std::endl;
                std::cout << "Objetivo: ter o maior número de peças da sua cor viradas pra cima ao fim da partida." << std::endl;
                std::cout << "Regras para colocar peças: Para fazer uma jogada válida você deve colocar uma peça de forma que vire, pelo menos, uma peça do seu oponente." << std::endl;
                std::cout << "As peças podem ser viradas na vertical, horizontal e diagonal ao mesmo tempo, desde que haja uma peça sua cercando as peças do seu oponente na direção;" << std::endl;
                std::cout << "Fim de jogo: o jogo termina quando algum jogador não tiver mais jogadas válidas ou quando o tabuleiro estiver cheio;" << std::endl;
                std::cout << "Dica: seja estratégico, pense nos possíveis movimentos do seu oponente,";
                std::cout << "lembre que, para ganhar, o que importa é o tabuleiro final!" << std::endl << std::endl;

                break;

            case cDAMAS:
                std::cout << "Regras do jogo DAMAS:" << std::endl;
                std::cout << "Objetivo: comer todas as peças inimigas antes que ele coma todas as suas. As peças do jogador 1 são representadas por 'X' e a dos jogador 2 por 'O'." << std::endl;
                std::cout << "Regras de movimento da DAMAS: Normalmente, você pode se mover apenas uma casa na diagonal para frente. Caso exista uma peça inimiga a ser comida, você vai poder se mover para a casa após a peça inimiga na diagonal dela." << std::endl;
                std::cout << "Caso uma peça sua chegue ao lado oposto do tabuleiro, ela vira uma peça coroa. Peças coroas normalmente conseguem se mover 1 casa na diagonal para trás e para frente." << std::endl;
                std::cout << "No cenário onde existe uma peça inimiga na diagonal de uma peça coroa, independentemente da distância, estando todas as casas na diagonal entre a coroa e a peça inimiga livres, a peça coroa consegue comer a peça inimiga." << std::endl;
                break;

            case cRAPOSA:
                std::cout << "Regras do jogo RAPOSA E OVELHAS:" << std::endl;
                std::cout << "Trata-se de um jogo de tabuleiro assimétrico onde o jogador 1 move uma única raposa, representada por 'X', e o jogador 2 consegue mover 4 ovelhas, representadas por 'O';" << std::endl;
                std::cout << "Regras de movimento da RAPOSA: se move diagonalmente, em um quadrado de distância, tanto para frente quanto para trás;" << std::endl;
                std::cout << "Regras de movimento das OVELHAS: se movem diagonalmente, em um quadrado de distância, somente para a frente;" << std::endl;
                std::cout << "Objetivo das OVELHAS: encurralar a raposa, impedindo seu movimento;" << std::endl;
                std::cout << "Objetivo da RAPOSA: ultrapassar as ovelhas, ou seja, chegar em uma posição onde não haja mais ovelhas nas linhas acima dela;" << std::endl;
                std::cout << "Observação: NÃO existem capturas neste jogo." << std::endl <<std::endl;

                break;

            default:
                comandoValido = false;
                std::cout << "ERRO: Comando inválido." << std::endl << std::endl;
                break;
        }
    } while (!comandoValido);
}

//! Função principal que inicializa o programa e gerencia os menus
/*!
    Imprime uma mensagem de boas-vindas que explica o funcionamento do programa
    incia um loop que que coleta o input do usuário e realiza a ação do comando dado.

*/
int main() {
    Placar placar;

    std::cout << "Seja bem-vindo ao Fliperama!" << std::endl << std::endl;
    std::cout << "Prepare-se para mergulhar no mundo dos jogos clássicos de tabuleiro! " <<
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
                std::cout << "Digite o apelido do novo jogador, em letras minúsculas: ";
                getline (cin, apelido);
                std::cout << std::endl;
                std::cout << "Digite o nome do novo jogador: ";
                getline (cin,nome);
                std::cout << std::endl;

                placar.adicionarJogador(apelido, nome);
                std::cout << std::endl;
                break;
            }

            case 'R': {
                std::string apelido;
                std::cout << "Digite o apelido do jogador a ser removido: ";
                getline (cin, apelido);
                std::cout << std::endl;
                placar.removerJogador(apelido);
                std::cout << std::endl;
                break;
            }

            case 'L': {
                char modo;
                std::cout << "Como deseja listar os jogadores?" << std::endl;
                std::cout << "A - Por apelido;" << std::endl;
                std::cout << "N - Por nome;" << std::endl << std::endl;
                coletaCaracter(modo);

                placar.listarJogadores(modo);
                
                break;
            }

            case 'H':
                menuHelp();
                break;

            case 'S':
                std::cout << "Obrigado por jogar!" << std::endl << std::endl;
                return 0;

            default:
                std::cout << "ERRO: Comando inválido." << std::endl << std::endl;
                break;
        }
    }
    return 0;
}