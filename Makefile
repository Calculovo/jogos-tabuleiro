CC := g++
FLAG := -Wall -std=c++11
INCL := -I include

all: bin/main

bin/main: obj/main.o
	$(CC) $(FLAG) obj/main.o -o bin/main

obj/main.o: src/main.cpp
	$(CC) $(FLAG) -c src/main.cpp $(INCL) -o obj/main.o

obj/tabuleiro.o: src/tabuleiro.cpp include/tabuleiro.hpp
	$(CC) $(FLAG) -c src/tabuleiro.cpp $(INCL) -o obj/tabuleiro.o

obj/jogobase.o: src/jogobase.cpp include/jogobase.hpp obj/tabuleiro.o
	$(CC) $(FLAG) -c src/jogobase.cpp $(INCL) -o obj/jogobase.o

obj/partida.o: src/partida.cpp include/partida.hpp obj/raposaeovelhas obj/damas obj/ligue4 obj/reversi obj/jogodavelha
	$(CC) $(FLAG) -c src/partida.cpp $(INCL) -o obj/partida.o

obj/jogador.o: src/jogador.cpp include/jogador.hpp
	$(CC) $(FLAG) -c src/jogador.cpp $(INCL) -o obj/jogador.o

obj/placar.o: src/placar.cpp include/placar.hpp obj/jogador.o
	$(CC) $(FLAG) -c src/placar.cpp $(INCL) -o obj/placar.o

obj/jogodavelha.o: src/jogodavelha.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/jogodavelha.cpp $(INCL) -o obj/jogodavelha.o

obj/raposaeovelhas.o: src/raposaeovelhas.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/raposaeovelhas.cpp $(INCL) -o obj/raposaeovelhas.o

obj/damas.o: src/damas.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/damas.cpp $(INCL) -o obj/damas.o

obj/reversi.o: src/reversi.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/reversi.cpp $(INCL) -o obj/reversi.o

obj/teste_tabuleiro.o: tests/teste_tabuleiro.cpp include/tabuleiro.hpp
	$(CC) $(FLAG) -c tests/teste_tabuleiro.cpp $(INCL) -o obj/teste_tabuleiro.o

bin/teste_tabuleiro: obj/teste_tabuleiro.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_tabuleiro.o obj/tabuleiro.o -o bin/teste_tabuleiro

obj/teste_jogo_da_velha.o: tests/teste_jogo_da_velha.cpp include/jogodavelha.hpp obj/jogodavelha.o
	$(CC) $(FLAG) -c tests/teste_jogo_da_velha.cpp $(INCL) -o obj/teste_jogo_da_velha.o

bin/teste_jogo_da_velha: obj/teste_jogo_da_velha.o obj/jogodavelha.o obj/jogobase.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_jogo_da_velha.o obj/jogodavelha.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_jogo_da_velha

obj/teste_raposa_e_ovelhas.o: tests/teste_raposa_e_ovelhas.cpp include/raposaeovelhas.hpp obj/raposaeovelhas.o
	$(CC) $(FLAG) -c tests/teste_raposa_e_ovelhas.cpp $(INCL) -o obj/teste_raposa_e_ovelhas.o

bin/teste_raposa_e_ovelhas: obj/teste_raposa_e_ovelhas.o obj/raposaeovelhas.o obj/jogobase.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_raposa_e_ovelhas.o obj/raposaeovelhas.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_raposa_e_ovelhas

obj/teste_reversi.o: tests/teste_reversi.cpp include/reversi.hpp obj/reversi.o
	$(CC) $(FLAG) -c tests/teste_reversi.cpp $(INCL) -o obj/teste_reversi.o

bin/teste_reversi: obj/teste_reversi.o obj/reversi.o obj/jogobase.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_reversi.o obj/reversi.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_reversi

obj/teste_damas.o: tests/teste_damas.cpp include/damas.hpp obj/damas.o
	$(CC) $(FLAG) -c tests/teste_damas.cpp $(INCL) -o obj/teste_damas.o

bin/teste_damas: obj/teste_damas.o obj/damas.o obj/jogobase.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_damas.o obj/damas.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_damas

obj/ligue4.o: src/ligue4.cpp include/ligue4.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/ligue4.cpp $(INCL) -o obj/ligue4.o

obj/teste_ligue4.o: tests/teste_ligue4.cpp include/ligue4.hpp obj/ligue4.o
	$(CC) $(FLAG) -c tests/teste_ligue4.cpp $(INCL) -o obj/teste_ligue4.o

bin/teste_ligue4: obj/teste_ligue4.o obj/ligue4.o obj/jogobase.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_ligue4.o obj/ligue4.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_ligue4

clean:
	rm -f bin/* obj/*

testAll: bin/teste_tabuleiro bin/teste_jogo_da_velha bin/teste_raposa_e_ovelhas bin/teste_damas bin/teste_ligue4 bin/teste_reversi
