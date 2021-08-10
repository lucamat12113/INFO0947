CC=gcc
LD=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LDFLAGS=

all:$(EXEC)

test_array: escale.o course_tableau.o course_tableau_test.o 
	$(LD) -o tableau escale.o course_tableau.o course_tableau_test.o  $(LDFLAGS)

course_tableau_test.o: course_tableau_test.c
	$(CC) -c course_tableau_test.c -o course_tableau_test.o $(CFLAGS)

course_tableau.o: course_tableau.c course.h 
	$(CC) -c course_tableau.c -o course_tableau.o $(CFLAGS)

test_list: escale.o course_liste.o course_liste_test.o 
	$(LD) -o liste escale.o course_liste.o course_liste_test.o  $(LDFLAGS)

course_liste_test.o: course_liste_test.c
	$(CC) -c course_liste_test.c -o course_liste_test.o $(CFLAGS)

course_liste.o: course_liste.c course.h
	$(CC) -c course_liste.c -o course_liste.o $(CFLAGS)

escale.o: escale.c escale.h
	$(CC) -c escale.c -lm -o escale.o $(CFLAGS)