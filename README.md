# Jogos de tabuleiro
Conjunto de jogos de tabuleiro. Trabalho final de PDS II.

Linguagem do progama: C++
Compilador: Um compilador C++ compatível com o padrão ISO C99 ou superior, de preferência o G++.

Requisitos de hardware:
- Processador: Qualquer processador com capacidade de rodar programas básicos em C++.
- Memória RAM: Qualquer memória RAM da atualidade.
- Armazenamento: Apenas o básico, para conseguir gerar o .tsv dos saves dos jogadores.
- Sistema operacional: Qualquer um que tenha suporte para a linguagem C++.
- Ambiente de execução: À preferência do usuário. Qualquer ambiente em que você consiga compilar e executar programas. De preferência, Linux.

## Problema
O problema envolve a implementação de uma série de jogos de tabuleiro, permitindo que o usuário jogue através do terminal. Há um sistema de cadastro e remoção de jogadores individuais com apelidos e nomes únicos atribuídos a cada usuário. Ademais, os dados dos jogadores, bem como seus resultados em cada jogo são salvos em um placar que pode ser acessadi a qualquer momento. Os jogos incluídos são: Reversi, Ligue4, Jogo da Velha, Raposa e Ovelhas e Damas.

## Solução
O problema foi abordado usando os conceitos de programação aprendidos durante esse semestre, como o uso de classes, construtores, destrutores, tratamento de exceções, smart pointers, dentre outros. Os detalhes de como essas ferramentas foram implementadas podem ser vistos no arquivo doxygen.

## Dificuldades encontradas
A maior dificuldade econtrada foi dominar o funcionamento do sistema git e seus comandos, principalmente a funcionalidade de diferentes branchs para manter a organização das diferentes versões do código. Além disso, no jogo de Damas, em específico, foi deveras complicado implementar a função da peça coroa, dado a quantidade de possibilidades de movimento (ou de não movimento) nos diferentes cenários em que as peças poderiam se encontrar. No Reversi, a implementação da checagem da existência de jogadas legais em todas as direções também se mostrou um obstáculo.


## Extras
Além dos requerimentos básicos passados para o projeto, optamos por fazer como extra a implementação de mais dois jogos de tabuleiro fora os listados: Damas e Raposa e Ovelhas. Ambos contam com um sistema de movimentação levemente diferenciado dos outros jogos. As regras de todos os jogos podem ser acessadas diretamente no menu principal.

# Instruções de Execução

Para compilar o código, utilize o comando `make main`.
Para iniciar o programa, após compilação, utilize o comando `./main`.

## Testes  com doctest

O projeto utiliza [doctest](https://github.com/doctest/doctest) para testes automatizados. No nosso projeto em específico utilizamos o doctest para validar o Arquivo tabuleiro_doctest.cpp. Para compilar esse teste em específico pelo doctest, utilize o seguinte comando:
`g++ -std=c++17 -Wall -Wno-unknown-warning-option -Iinclude tests/tabuleiro_doctest.cpp -o test`
[Ou o atalho `make test`]
Após a compilação, execute os testes com:
`./test`
Para um relatório mais detalhado, utilize a flag --success:
`./test --success`