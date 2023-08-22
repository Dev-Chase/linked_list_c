CC=clang
INCLUDE=include
CFLAGS=-g -Wall -I$(INCLUDE)
RELEASE=-Wall -O2 -I$(INCLUDE)
SRC=src
OBJ=obj
BIN=bin
EXE=testing
MAIN=testing
OBJS=$(OBJ)/$(MAIN).o $(OBJ)/linkedlist.o

all: $(BIN)/$(EXE)

run: all
	$(BIN)/$(EXE)

release:
	$(CC) $(RELEASE) -o $(BIN)/$(EXE) src/*.c

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(OBJ)/$(MAIN).o: $(SRC)/$(MAIN).c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN)/%: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM $(OBJ)/*.o $(BIN)/*

