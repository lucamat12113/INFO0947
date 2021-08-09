
#include <stdlib.h>
#include <assert.h>

#include "course.h"

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2

struct Course_t {

Escale *step;
char *circuit;
int nbr_escale;
int nbr_step;
float best_time_race;

};


struct List_t{

int array_size;// current size (i.e., number of squares in the array)
int length;// number of element recorded in the array
Course *array; //the array itself

};


/**
 * \fn List *realloc_array(List *race);
 * \brief Reallocates the size associated to a given array list (i.e., increase its size).
 *
 * \param race The list to increase.
 *
 * \return a pointer to the new list.  Or NULL in case of allocation issue.
 */
static List *realloc_array(List *race){
    assert(race!=NULL);
    
    race->array_size *= REALLOCATION_FACTOR;
    race->array = realloc(race->array, race->array_size*sizeof(Course *));
    
    return race;
}//end realloc_array()

/**
 * \fn List *shift_right(List *race, int begin)
 * \brief Shifts by one position to the right the elements in the array starting from begin
 * to the end of the array.  If required, the array size is increased.
 *
 * \param race, the List to manipulate
 * \param begin, the position where to start the shift
 * 
 * \return A pointer to the new List.
 */
static List *shift_right(List *race, int begin){
    assert(race != NULL && 0<= begin && begin <= length(race));
    
    if(race->length + 1 >= race->array_size)
        race = realloc_array(race);
    
    int i;
    
    for(i=race->length; i>=begin; i--)
        race->array[i+1] = race->array[i];
    
    return race;
}//end shift_right()

/**
 * \fn List *shift_left(List *race, int begin)
 * \brief Shifts by one position to the left the elements in the array starting from begin
 * to the end of the array.
 *
 * \param race, the List to manipulate
 * \param begin, the position where to start the shift
 *
 * \return A pointer to the new List.
 */
static List *shift_left(List *race, int begin){
    assert(race!=NULL && 0 < begin && begin <= race->length);
    
    int i;
    
    for(i=begin; i<race->length; i++)
        race->array[i-1] = race->array[i];
    
    return race;
}//end shift_left()



Course *create(Escale *step1, Escale *step2){

    List *race = malloc(sizeof(List));
    if(race==NULL)
        return NULL;

    race->array_size = INITIAL_SIZE;
    race->length = 2;
    

    race->array = malloc(INITIAL_SIZE * sizeof(Course*));
    if(race->array==NULL){
        free(race);

        return NULL;
    }

    race->array->step[0] = step1;

    return race;

}//end creat()


char *is_a_loop(Course *race){
    
    assert(race!=NULL);

    if(race->array->step[0]==race->step[race_length-1])
        race->circuit="oui";
        else
        race->circuit="non";
    
    return race->circuit;

}//end is_a_loop()


int how_many_escale(Course *race){

    assert(race!=NULL);

    race->nbr_escale=race_length;

    return race->nbr_escale; 

}//end how_many_escape()


int how_many_step(Course *race){

    assert(race!=NULL);

    race->nbr_step=race_length-1;

    return race->nbr_step; 

}//end how_many_escape()


float best_time_race(Course *race){

    assert(race!=NULL);

    int i;
    float btr=0;
    for(i=0; i<race_length; i++){
        
        btr += race->step[i]->time;
          
    };

    race->best_time_race = btr;

    return race->best_time_race;

}//end best_time_race()


float best_time_step(Course *race, Escale *step){

    assert(step!=NULL && race!=NULL);

    int i;
    float bts=0;
    for(i=0; i<race_length; i++){

        if(step==race->step[i])
            bts = race->step[i]->time;

    };

    return bts;

}//end best_time_step()


Course *add_step(Course *race, Escale *step){

race_length+=1;
    race = realloc(race, sizeof(Course));
    if(race==NULL)
        return NULL;

    int i;
    for(i=0; i<race_length; i++){
        
        if(i==race_length-1)
            race->step[i]=step;
          
    };

    return race;

}//end add_step()


Course *remove_step(Course *race, Escale *step){

race_length-=1;
    race = realloc(race, sizeof(Course));
    if(race==NULL)
        return NULL;
    else
        return race;



}//end remove_step()