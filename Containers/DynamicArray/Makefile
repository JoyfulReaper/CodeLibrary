CC = g++
#CC = clang++
CFLAGS = -c -Wall -std=c++11 -ggdb
#CFLAGS = -c -Wall -std=c++11 -g

all: test

test: test.o
	$(CC) test.o -o test

test.o: test.cpp DynamicArray.cxx DynamicArray.h
	$(CC) $(CFLAGS) test.cpp 
	
clean:
	rm -rf *.o test
