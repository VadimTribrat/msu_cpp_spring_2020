all: main.o mylib.o
	g++ -o main main.o mylib.o
main.o: main.cpp mylib.h
	g++ -c main.cpp
mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp

test: 
	./main 1 2 1 1 4
	./main -1 0 1 1 1
	./main 4 4 2 2 1
	./main 3 3 0 1 1
	./main 4 4 1 1 3
	./main 3 3 1 1 -2
