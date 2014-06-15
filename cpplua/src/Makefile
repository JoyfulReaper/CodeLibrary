CC = g++
CC = clang++
CFLAGS = -c -Wall -Wextra -std=c++11 -ggdb -O0
#CFLAGS = -c -std=c++11 -march=native -O2



all: test

test: test.o luaEngine.o
	$(CC) test.o luaEngine.o -llua -lm -o test

luaEngine.o: luaEngine.cxx luaEngine.hpp luaExcept.hpp luaStackItem.hpp luaStackResult.hpp
	$(CC) $(CFLAGS) -c luaEngine.cxx
	
test.o: test.cpp luaEngine.cxx
	$(CC) $(CFLAGS) -c test.cpp
	
clean:
	rm -rf *.o test