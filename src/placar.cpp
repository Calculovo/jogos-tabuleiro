#include "placar.hpp"

#include "jogador.hpp"
#include <list>
#include <string>
#include <iostream>

Placar::Placar() {};

Placar::~Placar() {};

void Placar::escreverArquivo() const {};

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