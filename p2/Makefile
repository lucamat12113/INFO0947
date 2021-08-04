CC=gcc
LD=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LDFLAGS=

all:$(EXEC)

tableau: escale.o course_tableau.o course_tableau_test.o 
	$(LD) -o output escale.o course_tableau.o course_tableau_test.o  $(LDFLAGS)

course_tableau_test.o: course_tableau_test.c
	$(CC) -c course_tableau_test.c -o course_tableau_test.o $(CFLAGS)

course_tableau.o: course_tableau.c course.h
	$(CC) -c course_tableau.c -o course_tableau.o $(CFLAGS)

liste: escale.o course_liste.o course_liste_test.o 
	$(LD) -o output escale.o course_liste.o course_liste_test.o  $(LDFLAGS)

course_liste_test.o: course_liste_test.c
	$(CC) -c course_liste_test.c -o course_liste_test.o $(CFLAGS)

course_liste.o: course_liste.c course.h
	$(CC) -c course_liste.c -o course_liste.o $(CFLAGS)

escale.o: escale.c esscale.h
	$(CC) -c escale.c -o escale.o $(CFLAGS)