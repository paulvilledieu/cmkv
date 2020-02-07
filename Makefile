CC=g++
CFLAGS=-Wall -pedantic  -O5 -std=c++17
BIN=cmkv
INC=include/
LIB=lib/FreeImage/

compile: src/*.cc
	$(CC) $(CFLAGS) -I./$(INC) -lfreeimage -o $(BIN) src/*.cc

.PHONY: clean

clean:
	rm $(BIN)