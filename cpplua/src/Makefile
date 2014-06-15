CC = g++
#CC = clang++
CFLAGS = -c -Wall -Wextra -std=c++11 -ggdb -O0
#CFLAGS = -c -std=c++11 -march=native -O2



all: test

test: test.o luaEngine.o luaStackResult.o luaStackItem.o
	$(CC) test.o luaEngine.o luaStackResult.o luaStackItem.o -llua -lm -o test

luaEngine.o: luaEngine.cxx luaEngine.hpp luaExcept.hpp luaStackItem.hpp luaStackItem.cxx luaStackResult.hpp
	$(CC) $(CFLAGS) -c luaEngine.cxx
	
luaStackItem.o: luaStackItem.cxx
	$(CC) $(CFLAGS) -c luaStackItem.cxx
	
luaStackResult.o: luaStackResult.cxx
	$(CC) $(CFLAGS) -c luaStackResult.cxx
	
test.o: test.cpp luaEngine.cxx
	$(CC) $(CFLAGS) -c test.cpp
	
clean:
	rm -rf *.o test