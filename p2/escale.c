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

    Escale *step = malloc(sizeof(Escale));
    if(step==NULL)
        return NULL;

    step->x = x;
    step->y = y;
    step->name = name;

    return step;


};//end create()


Escale *set_time(Escale *step, float time){

    assert(step!=NULL);
    if(step==NULL);
        return NULL;
        
    step->time=time;

    return step;

};//end set_time()


void *get(Escale *step){

    

};//end get



   