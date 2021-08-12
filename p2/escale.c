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


Escale *creation(float x, float y, char *name){

    Escale *step = malloc(sizeof(Escale));
    if(step==NULL)
        return NULL;

    step->x = x;
    step->y = y;
    step->name = name;

    return step;


}//end create()


Escale *set_time(Escale *step, float time){

    assert(step!=NULL);
        
    step->time=time;

    return step;

}//end set_time()


float get_time(Escale *step){

    assert(step!=NULL);

    return step->time; 

}//end get_time()


void *get(Escale *step){

    assert(step!=NULL);

    return step;

}//end get


float calc_distance(Escale *step_depart, Escale *step){

    assert(step_depart!=NULL && step!=NULL);

    float arccos= acos((sin(step_depart->x)*sin(step->x))+(cos(step_depart->y)*cos(step->y)));
    step->distance =arccos * 6371;

    return step->distance;

}//end calc_distance()




   