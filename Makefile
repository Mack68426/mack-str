PROJECT_NAME = uustr
EXEC_PATH = bin
OBJ_PATH = obj\$(PROJECT_NAME)
INCLUDE_PATH = include
LIB_PATH = ../lib/core
SRC_PATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions


EXEC = $(EXEC_PATH)\$(PROJECT_NAME).exe
OBJS = $(OBJ_PATH)\$(PROJECT_NAME).o $(OBJ_PATH)\Main.o


all: dir build

init: dir
#	type nul > $(SRC_PATH)/main.c
#	mv $(wildcard *.c) $(wildcard $(SRC_PATH)/*.c)
#	mv $(wildcard *.h) $(wildcard $(INCLUDE_PATH)/*.h)
#	mv $(wildcard *.o) $(wildcard $(OBJ_PATH)/*.o)
	mv $(wildcard *.exe) $(wildcard $(EXEC_PATH)\*.exe) || mv $(wildcard *.out) $(wildcard $(EXEC_PATH)/*.out)


dir:
	mkdir -p $(INCLUDE_PATH)
	mkdir -p $(OBJ_PATH)
	mkdir -p $(EXEC_PATH)
	mkdir -p $(SRC_PATH)

build: $(OBJS) $(EXEC)

run: $(EXEC)
	.\$<

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJ_PATH)\$(PROJECT_NAME).o: $(SRC_PATH)\$(PROJECT_NAME).c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

$(OBJ_PATH)\Main.o: $(SRC_PATH)\Main.c
	$(CC) -g -c $< -I $(LIB_PATH) -I $(INCLUDE_PATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)

