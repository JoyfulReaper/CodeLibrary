#CC = g++
CC = clang++
CFLAGS = -c -std=c++11 -Wall -ggdb
#CFLAGS = -c -Wall -g

all: test

test: test.o
	$(CC) test.o -o test

test.o: test.cpp bag.cxx bag.h BagIterator.h
	$(CC) $(CFLAGS) test.cpp 
	
clean:
	rm -rf *.o test
