CC = gcc
OBJ = sac.o
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : sac clean

sac : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o sac

sac.o : sac.c
	$(CC) $(CC_OPTIONS) -c sac.c

clean :
	rm *.o
