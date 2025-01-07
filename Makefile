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

obj/jogodavelha.o: src/jogodavelha.cpp obj/jogobase.o
	$(CC) $(FLAG) -c src/jogodavelha.cpp $(INCL) -o obj/jogodavelha.o

obj/jogobase.o: src/jogobase.cpp include/jogobase.hpp
	$(CC) $(FLAG) -c src/jogobase.cpp $(INCL) -o obj/jogobase.o

clean:
	rm -f bin/* obj/*

testAll: bin/teste_tabuleiro bin/teste_jogo_da_velha

bin/teste_tabuleiro: obj/teste_tabuleiro.o obj/tabuleiro.o
	$(CC) $(FLAG) obj/teste_tabuleiro.o obj/tabuleiro.o -o bin/teste_tabuleiro

obj/teste_tabuleiro.o: tests/teste_tabuleiro.cpp include/tabuleiro.hpp
	$(CC) $(FLAG) -c tests/teste_tabuleiro.cpp $(INCL) -o obj/teste_tabuleiro.o

bin/teste_jogo_da_velha: obj/teste_jogo_da_velha.o obj/jogodavelha.o
	$(CC) $(FLAG) obj/teste_jogo_da_velha.o obj/jogodavelha.o -o bin/teste_jogo_da_velha

