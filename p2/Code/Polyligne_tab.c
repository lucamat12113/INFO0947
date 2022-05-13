#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


#include "Polyligne.h"

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2


struct Polyligne_t{
    Boolean open;
    unsigned int nbpoint;
    unsigned int arraysize;
    Point2D** pointArray;
};


static Polyligne*  ReallocArray(Polyligne* P){
    assert(P!=NULL);
    
    P->arraysize *= REALLOCATION_FACTOR;
    P->pointArray = realloc(P->pointArray, P->arraysize*sizeof(Polyligne *));
    
    return P;
}//end realloc()


Polyligne *CreatePolyligne(Point2D *A, Point2D *B){
    assert(A != NULL && B != NULL);


    Polyligne* P = malloc(sizeof(Polyligne));
    if(P==NULL)
        return NULL;

    P->arraysize = INITIAL_SIZE;
    P->nbpoint = 2;
    P->open = True;

    P->pointArray = malloc(INITIAL_SIZE * sizeof(Polyligne*));
    if(P->pointArray==NULL);
        free(P);

        return NULL;

    P->pointArray[0] = A;
    P->pointArray[1] = B;

    return P;    

}//end create()


void Open(Polyligne* P){
    assert(P!=NULL);

    if(P->open != True)
        P->open = True;
        SuppPoint(P);

}//end Open()


void Close(Polyligne* P){
    assert(P!=NULL);

    if(P->open == True)
        P->open = False;
        AddPoint(P, P->pointArray[0]);

}//end Close()



Boolean IsOpen(Polyligne* P){

    if(P->pointArray[0]==P->pointArray[P->nbpoint - 1])
        P->open = False;
    else
        P->open = True;

    return P->open;

}// en IsOpen


unsigned int NbrPoint(Polyligne* P){
    assert(P!=NULL);

    return P->nbpoint;

}//end NbrPoint()


Point2D* GetPoint(Polyligne* P, unsigned int numero){

//////////////////////////////////////////////////////////////////

}


Polyligne AddPoint(Polyligne* P, Point2D* A){

//////////////////////////////////////////////////////////////////

}


Polyligne SuppPoint(Polyligne* P){

//////////////////////////////////////////////////////////////////

}