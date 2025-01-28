#include "placar.hpp"

#include "jogador.hpp"
#include <list>
#include <string>
#include <iostream>
#include <fstream>

Placar::Placar() {
    ifstream savefile;
    savefile.open("gamestats.tsv");
    if (!savefile.is_open()) {
        std::cout << "Nenhum arquivo de estatisticas foi achado." << std::endl;
        return;
    }
    string nome, apelido, wipe;
    int valores[5][3];
    while (!savefile.eof()) {
        getline(savefile, nome, '\t');
        getline(savefile, apelido);
        for (int i = 0; i < N_DE_JOGOS; i++) {
            for (int j = 0; j < N_DE_RESULTADOS; j++) {
                savefile >> valores[i][j];
            }
        }
        getline(savefile, wipe);
        if (!savefile.eof())
            jogadores.push_back(Jogador(nome,apelido,valores));
        else
            break;
    }
    savefile.close();
    cout << this->numeroDeJogadores() << " jogadores encontrados." << endl << endl;
};

Placar::~Placar() {
    escreverArquivo();
};

void Placar::escreverArquivo() const {
    ofstream savefile;
    savefile.open("gamestats.tsv");
    if (!savefile.is_open()) {
        std::cout << "Erro ao tentar salvar estatisticas." << std::endl;
        return;
    }
    for (Jogador p: jogadores) {
        savefile << p.getNome() << "\t" << p.getApelido() << std::endl;
        for (int i = 0; i < N_DE_JOGOS; i++) {
            for (int j = 0; j < N_DE_RESULTADOS; j++) {
                savefile << p.getResultados(i, j);
                if (j == N_DE_RESULTADOS-1) break;
                savefile << "\t";
            }
            savefile << std::endl;
        }
    }
    savefile.close();
    std::cout << "Estatisticas salvas!" << std::endl << std::endl;
    return;
};

void Placar::adicionarJogador(std::string apelido, std::string nome) {
    if (this->buscarJogador(apelido) != nullptr) {
        std::cout << "ERRO: Jogador " << apelido << " ja existe." << std::endl;
        return;
    }
    for (char c: apelido) {
        if (('a' <= c and c <= 'z') or ('0' <= c and c <= '9') or (c == '_'))
            continue;
        std::cout << "ERRO: Apelidos de jogador somente podem usar letras minusculas, numerais, ou underline." << std::endl;
        return;
    }
    for (char c: nome) {
        if ((' ' <= c and c <= '~'))
            continue;
        std::cout << "ERRO: Nomes de jogador nao podem usar caracteres de controle." << std::endl;
        return;
    }
    jogadores.push_back(Jogador(nome, apelido));
    std::cout << "Jogador " << apelido << " cadastrado com sucesso." << std::endl;
};

void Placar::removerJogador(std::string apelido) {
    list<Jogador>::iterator j = jogadores.begin();
    for (; j != jogadores.end(); j++) {
        if (j->getApelido() != apelido) continue;
        jogadores.erase(j);
        std::cout << "Jogador " << apelido << " removido com sucesso." << std::endl;
        return;
    }
    std::cout << "ERRO: Jogador " << apelido << " nao existe." << std::endl;
};

bool ordenarJogadoresPorApelido(const Jogador& first, const Jogador& second) {
    return first.getApelido() < second.getApelido();
}

bool ordenarJogadoresPorNome(const Jogador& first, const Jogador& second) {
    return first.getNome() < second.getNome();
}

void Placar::listarJogadores(char modo) {
    switch (modo) {
        case 'A':
            jogadores.sort(ordenarJogadoresPorApelido);
            break;
        case 'N':
            jogadores.sort(ordenarJogadoresPorNome);
            break;
        default:
            cout << "Modo de listar desconhecido." << endl;
            break;
    }
    cout << this->numeroDeJogadores() << " jogadores encontrados." << endl << endl;
    for (Jogador &j: jogadores) {
        j.imprimir();
    };
};

Jogador* Placar::buscarJogador(std::string apelido) {
    for (Jogador& j: jogadores) {
        if (j.getApelido() != apelido) continue;
        return &j;
    }
    return nullptr;
};

unsigned int Placar::numeroDeJogadores() {
    return jogadores.size();
};