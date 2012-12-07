CC = gcc
OBJ = shank.o
CC_OPTIONS = -g -Wall -lm
PREFIX=/usr/local

all : shank clean

shank : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o shank

shank.o : shank.c
	$(CC) $(CC_OPTIONS) -c shank.c

clean :
	rm *.o
