CC = gcc
OBJ = carmichael.o
CC_OPTIONS = -g -Wall -lm
PREFIX=/usr/local

all : carmichael clean

carmichael : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o carmichael

carmichael.o : carmichael.c
	$(CC) $(CC_OPTIONS) -c carmichael.c

clean :
	rm *.o
