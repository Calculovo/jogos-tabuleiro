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

obj/jogodavelha.o: src/jogodavelha.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/jogodavelha.cpp $(INCL) -o obj/jogodavelha.o

obj/raposaeovelhas.o: src/raposaeovelhas.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/raposaeovelhas.cpp $(INCL) -o obj/raposaeovelhas.o

obj/damas.o: src/damas.cpp include/jogobase.hpp obj/jogobase.o
	$(CC) $(FLAG) -c src/damas.cpp $(INCL) -o obj/damas.o

clean:
	rm -f bin/* obj/*

testAll: bin/teste_tabuleiro bin/teste_jogo_da_velha bin/teste_raposa_e_ovelhas

bin/teste_tabuleiro: obj/teste_tabuleiro.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_tabuleiro.o obj/tabuleiro.o -o bin/teste_tabuleiro

obj/teste_tabuleiro.o: tests/teste_tabuleiro.cpp include/tabuleiro.hpp
	$(CC) $(FLAG) -c tests/teste_tabuleiro.cpp $(INCL) -o obj/teste_tabuleiro.o

bin/teste_jogo_da_velha: obj/teste_jogo_da_velha.o obj/jogodavelha.o
	$(CC) $(FLAG) obj/teste_jogo_da_velha.o obj/jogodavelha.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_jogo_da_velha

obj/teste_jogo_da_velha.o: tests/teste_jogo_da_velha.cpp include/jogodavelha.hpp obj/jogodavelha.o
	$(CC) $(FLAG) -c tests/teste_jogo_da_velha.cpp $(INCL) -o obj/teste_jogo_da_velha.o

bin/teste_raposa_e_ovelhas: obj/teste_raposa_e_ovelhas.o obj/raposaeovelhas.o
	$(CC) $(FLAG) obj/teste_raposa_e_ovelhas.o obj/raposaeovelhas.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_raposa_e_ovelhas

obj/teste_raposa_e_ovelhas.o: tests/teste_raposa_e_ovelhas.cpp include/raposaeovelhas.hpp obj/raposaeovelhas.o
	$(CC) $(FLAG) -c tests/teste_raposa_e_ovelhas.cpp $(INCL) -o obj/teste_raposa_e_ovelhas.o

bin/teste_damas.o: obj/teste_damas.o obj/raposaeovelhas.o
	$(CC) $(FLAG) obj/teste_damas.o obj/raposaeovelhas.o obj/jogobase.o obj/tabuleiro.o -o bin/teste_damas

obj/teste_damas.o: tests/teste_damas.cpp include/raposaeovelhas.hpp obj/raposaeovelhas.o
	$(CC) $(FLAG) -c tests/teste_damas.cpp $(INCL) -o obj/teste_damas.o