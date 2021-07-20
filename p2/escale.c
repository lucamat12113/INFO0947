#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "escale.h"

struct Escale_t {

    float x;
    float y;
    float time;
    char *name;

};


Escale *create(float x, float y, char *name){

    Escale *stepover = malloc(sizeof(Escale));
    if(stepover==NULL)
        return NULL;

    stepover->x = x;
    stepover->y = y;
    stepover->name = name;

    return stepover;


};//end create()


