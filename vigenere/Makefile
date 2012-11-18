CC = gcc
CC_OPTIONS = -g -Wall
PREFIX=/usr/local

all : vigenere clean

vigenere : vigenere.o
	$(CC) $(CC_OPTIONS) vigenere.o -o vigenere

vigenere.o : vigenere.c
	$(CC) $(CC_OPTIONS) -c vigenere.c

clean :
	rm *.o
