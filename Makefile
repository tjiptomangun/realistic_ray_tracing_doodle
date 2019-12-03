LDFLAGS=-g
LDLIBS=-lterong
LDDIR=-L src/lib
INCDIR=-I src/include

all: main

main: main.o image.o vector3.o
	g++ -o target/main target/main.o target/image.o target/vector3.o

main.o: src/bin/main.cc target
	g++ $(INCDIR) -c src/bin/main.cc -o target/main.o

image.o: src/bin/image.cc target
	g++ $(INCDIR) -c src/bin/image.cc -o target/image.o

vector3.o: src/bin/vector3.cc target
	g++ $(INCDIR) -c src/bin/vector3.cc -o target/vector3.o

target: 
	mkdir -p target

clean:
	rm target/main.o
	rm target/main

.PHONY: clean main main.o image.o vector3.o all


