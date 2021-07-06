CC=gcc
LD=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LDFLAGS=
EXEC=output

all:$(EXEC)

output: main.o multiplicite.o
	$(LD) -o output main.o multiplicite.o $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

multiplicite.o: multiplicite.c multiplicite.h
	$(CC) -c multiplicite.c -o multiplicite.o $(CFLAGS)