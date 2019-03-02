LDFLAGS=-g
LDLIBS=-lterong
LDDIR=-L src/lib
INCDIR=-I src/include

all: main

main: main.o
	g++ -o target/main target/main.o

main.o: src/bin/main.cpp target
	g++ $(INCDIR) -c src/bin/main.cpp -o target/main.o

target: 
	mkdir -p target

clean:
	rm target/main.o
	rm target/main

.PHONY: clean main main.o all


