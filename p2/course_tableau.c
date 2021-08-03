
#include <stdlib.h>
#include <assert.h>
#include "course.h"

race_lenght = 2;

struct Course_t {

Escale step[race_lenght];
char *circuit;
int nbr_escale;
int nbr_step;
float best_time_race;
float best_time_step;

};

Course *create(Escale *step1, Escale *step2){

    Course *race = malloc(sizeof(Course));
    if(race==NULL)
        return NULL;

    
    race->step[0]=step1;
    race->step[1]=step2;

    return race;

};//end creat()


char *is_a_loop(Course *race){
    
    assert(race!=NULL);

    if(race->step[0]==race->step[race_lenght-1])
        race->circuit="oui";
        else
        race->circuit="non";
    
    return race->circuit;

};//end is_a_loop()


int how_many_escale(Course *race){

    assert(race!=NULL);

    race->nbr_escale=race_lenght;

    return race->nbr_escale; 

}//end how_many_escape()


int how_many_step(Course *race){

    assert(race!=NULL);

    race->nbr_step=race_lenght-1;

    return race->nbr_step; 

}//end how_many_escape()


float best_time_race(Course *race){

    assert(race!=NULL);

    int i;
    int btr=0;
    for(i=0; i<race_lenght; i++){
        
        btr += race->step[i]->time;
          
    };

    race->best_time_race = btr;

    return race->best_time_race;

}//end best_time_race()
