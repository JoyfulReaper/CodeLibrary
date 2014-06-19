# Quick shitty Makefile
CC = g++

all: test

test: test.o test.cpp greedyWrap.cxx greedyWrap.hpp
	$(CC) -ggdb test.cpp greedyWrap.cxx -o test
	
clean:
	rm -f *.o test