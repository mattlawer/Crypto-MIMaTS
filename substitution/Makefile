CC = gcc
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : substitution clean

substitution : substitution.o
	$(CC) $(CC_OPTIONS) substitution.o -o substitution

substitution.o : substitution.c
	$(CC) $(CC_OPTIONS) -c substitution.c

clean :
	rm *.o
