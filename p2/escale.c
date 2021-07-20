#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "escale.h"

struct Escale_t {

    float x;
    float y;
    float time;
    char *name;
    float distance;

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
        
    step->time=time;

    return step;

};//end set_time()


void *get(Escale *step){

    assert(step!=NULL);

    return step;

};//end get


float calc_distance(Escale *step_depart, Escale *step){

    assert(step_depart!=NULL && step!=NULL);

    float x_squared = (step->x - step_depart->x)*(step->x - step_depart->x);
    float y_squared = (step->y - step_depart->y)*(step->y - step_depart->y);
    step->distance = sqrt(x_squared + y_squared);

    /*
    EUH OUAI FAUT VOIR SI JE PEUX INCLURE 'MATH.H'
    */

   return step->distance;

};




   