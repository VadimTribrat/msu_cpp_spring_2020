all: main.o
	g++ -o main main.o
main.o: main.cpp mylib.h
	g++ -c main.cpp
test:
	./main
