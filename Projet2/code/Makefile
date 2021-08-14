include ../Makefile.compilation

test_array: escale.o course_tableau.o course_tableau_test.o 
	$(LD) -o course_tableau_test escale.o course_tableau.o course_tableau_test.o  $(LDFLAGS)

course_tableau_test.o: course_tableau_test.c
	$(CC) -c course_tableau_test.c -o course_tableau_test.o $(CFLAGS)

course_tableau.o: course_tableau.c course.h 
	$(CC) -c course_tableau.c -o course_tableau.o $(CFLAGS)

test_list: escale.o course_liste.o course_liste_test.o 
	$(LD) -o course_liste_test escale.o course_liste.o course_liste_test.o  $(LDFLAGS)

course_liste_test.o: course_liste_test.c
	$(CC) -c course_liste_test.c -o course_liste_test.o $(CFLAGS)

course_liste.o: course_liste.c course.h
	$(CC) -c course_liste.c -o course_liste.o $(CFLAGS)

escale.o: escale.c escale.h
	$(CC) -c escale.c -o escale.o $(CFLAGS)


clean:
	rm -f *.o test_array test_list