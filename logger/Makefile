CC = g++
#CC = clang++
CFLAGS = -c -Wall -Wextra -std=c++11 -ggdb -O0
#CFLAGS = -c -std=c++11 -march=native -O2

all: test

test: test.o logger.o
	$(CC) test.o logger.o -o test

logger.o: logger.cxx logger.hpp
	$(CC) $(CFLAGS) logger.cxx
	
test.o: test.cpp logger.o logger.hpp
	$(CC) $(CFLAGS) test.cpp
	
clean:
	rm -rf *.o test