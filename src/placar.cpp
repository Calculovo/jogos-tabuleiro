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

bool Placar::validarApelido(std::string apelido) {
    if (apelido.size() < 2)
        return false;
    for (char c: apelido) {
        if (('a' <= c and c <= 'z') or ('0' <= c and c <= '9') or (c == '_'))
            continue;
        return false;
    }
    return true;
};

bool Placar::validarNome(std::string nome) {
    if (nome.size() < 2)
        return false;
    for (char c: nome) {
        if ((' ' <= c and c <= '~'))
            continue;
        return false;
    }
    return true;
};

void Placar::adicionarJogador(std::string apelido, std::string nome) {
    try {
        this->buscarJogador(apelido);
        throw std::range_error("ERRO: Jogador ja existe.");
    } catch (std::invalid_argument& p) {/*intencionalmente deixado em branco*/};
    if (not validarApelido(apelido))
        throw std::invalid_argument("ERRO: Apelidos de jogador somente podem usar letras minusculas, numerais, ou underline.");
    if (not validarNome(nome))
        throw std::invalid_argument("ERRO: Nomes de jogador nao podem usar caracteres de controle ou fora da ASCII.");
    jogadores.push_back(Jogador(nome, apelido));
    std::cout << "Jogador " << apelido << " cadastrado com sucesso." << std::endl;
};

void Placar::removerJogador(std::string apelido) {
    std::list<Jogador>::iterator jogador = this->buscarJogador(apelido);
    jogadores.erase(jogador);
    std::cout << "Jogador " << apelido << " removido com sucesso." << std::endl;
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
            return;
            break;
    }
    cout << this->numeroDeJogadores() << " jogadores encontrados." << endl << endl;
    for (Jogador &j: jogadores) {
        j.imprimir();
    };
};

std::list<Jogador>::iterator Placar::buscarJogador(std::string apelido) {
    std::list<Jogador>::iterator p = jogadores.begin();
    while (p != jogadores.end()) {
        if (p->getApelido() != apelido) p++;
        else return p;
    }
    throw std::invalid_argument("ERRO: Jogador não existe.");
};

unsigned int Placar::numeroDeJogadores() {
    return jogadores.size();
};