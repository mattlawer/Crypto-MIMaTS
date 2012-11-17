CC = gcc
OBJ = dh.o

GMPIPATH  = -I/opt/local/include
GMPLIB    = -lgmp
GMPLPATH  = -L/opt/local/lib

LDFLAGS = $(GMPIPATH) $(GMPLIB) $(GMPLPATH)
CFLAGS = -g -Wall -O3

all : dh clean

dh : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o dh

dh.o : dh.c
	$(CC) $(CFLAGS) -c dh.c

clean :
	rm *.o
	