include ../Makefile.compilation

all: $(BINARY)

$(BINARY): multiplicite.o main.o
	$(LD) -o $(BINARY) multiplicite.o main.o $(LDFLAGS)

multiplicite.o: multiplicite.c multiplicite.h
	$(CC) -c multiplicite.c -o multiplicite.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o $(BINARY)
