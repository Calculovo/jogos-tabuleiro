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
    string nome, apelido;
    int valores[5][3];
    while (!savefile.eof()) {
        getline(savefile, nome, '\t');
        getline(savefile, apelido);
        for (int i = 0; i < N_DE_JOGOS; i++) {
            for (int j = 0; j < N_DE_RESULTADOS; j++) {
                savefile >> valores[i][j];
            }
        }
        jogadores.push_back(Jogador(nome,apelido,valores));
    }
    savefile.close();
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
        savefile << p.getApelido() << "\t" << p.getNome() << std::endl;
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
    std::cout << "Estatisticas salvas!" << std::endl;
    return;
};

void Placar::adicionarJogador(std::string apelido, std::string nome) {
    for (Jogador p: jogadores) {
        if (p.getApelido() != apelido) continue;
        std::cout << "ERRO: Jogador " << apelido << " ja existe." << std::endl;
        return;
    }
    for (char c: apelido) {
        if (('a' <= c and c <= 'z') or ('0' <= c <= '9') or (c == '_'))
            continue;
        std::cout << "ERRO: Apelidos de jogador somente podem usar letras minusculas, numerais, ou underline." << std::endl;
        return;
    }
    for (char c: nome) {
        if ((' ' <= c <= '~'))
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
    std::cout << "ERRO: Jogador " << apelido << "nao existe." << std::endl;
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
            throw std::range_error("Modo desconhecido.");
            break;
    }
    for (Jogador &j: jogadores)
        j.imprimir();
};

Jogador* Placar::buscarJogador(std::string apelido) {
    for (Jogador& j: jogadores) {
        if (j.getApelido() != apelido) continue;
        return &j;
    }
    return NULL;
};

unsigned int Placar::numeroDeJogadores() {
    return jogadores.size();
};