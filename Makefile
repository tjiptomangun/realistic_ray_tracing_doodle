LDFLAGS=-g
LDLIBS=-lterong
LDDIR=-L src/lib
INCDIR=-I src/include

all: main test_img

test_img: src/bin/test_img.cc
	g++ src/bin/test_img.cc -o target/test_img

main: main.o image.o vector3.o onb.o triangle.o sphere.o
	g++ -o target/main target/main.o target/image.o target/vector3.o target/onb.o target/triangle.o target/sphere.o

main.o: src/bin/main.cc target
	g++ $(INCDIR) -c src/bin/main.cc -o target/main.o

image.o: src/bin/image.cc target
	g++ $(INCDIR) -c src/bin/image.cc -o target/image.o

vector3.o: src/bin/vector3.cc target
	g++ $(INCDIR) -c src/bin/vector3.cc -o target/vector3.o

onb.o: src/bin/onb.cc target
	g++ $(INCDIR) -c src/bin/onb.cc -o target/onb.o
	
triangle.o: src/bin/triangle.cc target
	g++ $(INCDIR) -c src/bin/triangle.cc -o target/triangle.o

sphere.o: src/bin/sphere.cc target
	g++ $(INCDIR) -c src/bin/sphere.cc -o target/sphere.o

target: 
	mkdir -p target

clean:
	rm target/main.o
	rm target/main
	rm target/image.o
	rm target/vector3.o
	rm target/onb.o 
	rm target/triangle.o.o 

.PHONY: clean main main.o image.o vector3.o onb.o triangle.o all


