CC = gcc
OBJ = hill.o
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : hill clean

hill : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o hill

hill.o : hill.c
	$(CC) $(CC_OPTIONS) -c hill.c

clean :
	rm *.o
