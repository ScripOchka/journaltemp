all: a main.o class.o struct.o

a: main.o class.o struct.o
	g++ main.o class.o struct.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

class.o: class.cpp
	g++ -c class.cpp -o class.o

struct.o: struct.cpp
	g++ -c struct.cpp -o struct.o
