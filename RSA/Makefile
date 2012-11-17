CC = gcc

GMPIPATH  = -I/usr/local/include
GMPLIB    = -lgmp
GMPLPATH  = -L/usr/local/lib

LDFLAGS = $(GMPIPATH) $(GMPLIB) $(GMPLPATH)
CFLAGS = -g -Wall -O3

all : rsa clean

rsa : rsa.o numlib.o
	$(CC) $(CFLAGS) $(LDFLAGS) rsa.o numlib.o -o rsa

rsa.o : rsa.c
	$(CC) $(CFLAGS) -c rsa.c
	
numlib.o : numlib.c numlib.h
	$(CC) $(CFLAGS) -c numlib.c

clean :
	rm *.o
	