all: my_prog

my_prog: allocator.o main.o
	g++ -o main main.o allocator.o

allocator.o: allocator.h allocator.cpp
	g++ -c allocator.cpp

main.o: main.cpp allocator.h
	g++ -c main.cpp
	
test: all
	./main 2 2 1 1
	./main 2 2 2 2
	./main 3 12 4 4 4 
	./main 0 0 0 0
