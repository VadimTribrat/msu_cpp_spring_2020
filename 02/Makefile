all: main

main: main.o mylib.o
	g++ -o main main.o mylib.o

main.o: main.cpp mylib.h
	g++ -c main.cpp 

mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp

test:
	./main "1"
	./main "abc1d2 		! "
	./main "123Ab cd 45!6"
	./main " "
	./main "123 abc 456 def "
