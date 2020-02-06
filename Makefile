CC=g++
CFLAGS=-Wall -Werror -pedantic  -O3 -std=c++14
BIN=cmkv
INC=include/
LIB=lib/FreeImage/

compile: src/*.cc
	$(CC) $(CFLAGS) -I./$(INC) -lfreeimage -o $(BIN) src/*.cc

.PHONY: clean

clean:
	rm $(BIN)