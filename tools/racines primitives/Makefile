CC = gcc
OBJ = rprimitiv.o
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : rprimitiv clean

rprimitiv : $(OBJ)
	$(CC) $(CC_OPTIONS) $(OBJ) -o rprimitiv

rprimitiv.o : rprimitiv.c
	$(CC) $(CC_OPTIONS) -c rprimitiv.c

clean :
	rm *.o
