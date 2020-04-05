all: main.o mylib.o
	g++ -o main main.o mylib.o
main.o: main.cpp mylib.h
	g++ -c main.cpp
mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp
test:
	./main
