CC=clang
INCLUDE=include
CFLAGS=-g -Wall -I$(INCLUDE)
RELEASE=-Wall -O2 -I$(INCLUDE)
SRC=src
OBJ=obj
BIN=bin
EXE=testing
LIB_NAME=dbl_linked_list
MAIN=testing
OBJS=$(OBJ)/$(MAIN).o $(OBJ)/dbl_linked_list.o 
# OBJS =$(OBJ)/$(MAIN).o $(OBJ)/linked_list.o

all: $(BIN)/$(EXE)

run: all
	$(BIN)/$(EXE)

release: $(OBJ)/$(LIB_NAME).o
	ar rcs $(BIN)/$(LIB_NAME).a $(OBJ)/$(LIB_NAME).o

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(OBJ)/$(MAIN).o: $(SRC)/$(MAIN).c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN)/%: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN)/%.a: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM $(OBJ)/*.o $(BIN)/*

