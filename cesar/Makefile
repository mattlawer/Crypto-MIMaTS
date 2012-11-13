CC = gcc
OBJ = cesar.o
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : cesar clean

cesar : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o cesar

cesar.o : cesar.c
	$(CC) $(CC_OPTIONS) -c cesar.c

clean :
	rm *.o
