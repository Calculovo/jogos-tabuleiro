CC := g++
FLAG := -Wall -std=c++11
INCL := -I include

all: bin/main

bin/main: obj/main.o
	$(CC) $(FLAG) obj/main.o -o bin/main

obj/main.o: src/main.cpp
	$(CC) $(FLAG) -c src/main.cpp $(INCL) -o obj/main.o

clean:
	rm -f bin/* obj/*