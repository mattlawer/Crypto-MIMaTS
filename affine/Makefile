CC = gcc
OBJ = affine.o
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : affine clean

affine : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o affine

affine.o : affine.c
	$(CC) $(CC_OPTIONS) -c affine.c

clean :
	rm *.o
