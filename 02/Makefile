all: main

main: main.o mylib.o
	g++ -o main main.o mylib.o

main.o: main.cpp mylib.h
	g++ -c main.cpp 

mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp

test:
	valgrind ./main "1"
	valgrind ./main "abc1d2 		! "
	valgrind ./main "123Ab cd 45!6"
	./main " "
	./main "123 abc 456 def "
	./main "ab12c 345!6 d"
