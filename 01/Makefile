all: main

main: main.o mylib.o
	g++ -o main main.o mylib.o
main.o: main.cpp mylib.h
	g++ -c main.cpp
mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp
test: 
	./main 8 4 4
	./main 12 18
	./main 1 99999
	./main 25 25
	./main
	./main 1
	./main 99999 1
	./main 25 12 13 2
	./main 12 18 12 9999 12
