all: main.o callback.o
	g++ -o main main.o callback.o
main.o: main.cpp callback.h
	g++ -c main.cpp
callback.o: callback.cpp callback.h
	g++ -c callback.cpp
test: all
	./main

