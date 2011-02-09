CC=gcc
CFLAGS=-O2 -I.
LDFLAGS=-lm

prj1: prj1.o prj1-bcd.o

prj1-bcd.o: prj1-bcd.c prj1-bcd.h

prj1.o: prj1.c prj1-bcd.h

clean:
	rm -f prj1 *.o
