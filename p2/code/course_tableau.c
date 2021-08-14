#include <stdlib.h>
#include <assert.h>

#include "course.h"

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2

struct Course_t {

int array_size;// current size (i.e., number of squares in the array)
int length;// number of element recorded in the array
Escale **step; //the array itself
char *circuit;
int nbr_step;
float best_time_race;

};


/**
 * \fn Course *realloc_array(Course *race);
 * \brief Reallocates the size associated to a given array Course (i.e., increase its size).
 *
 * \param race The Course to increase.
 *
 * \return a pointer to the new Course.  Or NULL in case of allocation issue.
 */
static Course *realloc_array(Course *race){
    assert(race!=NULL);
    
    race->array_size *= REALLOCATION_FACTOR;
    race->step = realloc(race->step, race->array_size*sizeof(Course *));
    
    return race;
}//end realloc_array()

/**
 * \fn Course *shift_right(Course *race, int begin)
 * \brief Shifts by one position to the right the elements in the array starting from begin
 * to the end of the array.  If required, the array size is increased.
 *
 * \param race, the Course to manipulate
 * \param begin, the position where to start the shift
 * 
 * \return A pointer to the new Course.
 */
static Course *shift_right(Course *race, int begin){
    assert(race != NULL && 0<= begin && begin <= race->length);
    
    if(race->length + 1 >= race->array_size)
        race = realloc_array(race);
    
    int i;
    
    for(i=race->length; i>=begin; i--)
        race->step[i+1] = race->step[i];
    
    return race;
}//end shift_right()

/**
 * \fn Course *shift_left(Course *race, int begin)
 * \brief Shifts by one position to the left the elements in the array starting from begin
 * to the end of the array.
 *
 * \param race, the Course to manipulate
 * \param begin, the position where to start the shift
 *
 * \return A pointer to the new Course.
 */
static Course *shift_left(Course *race, int begin){
    assert(race!=NULL && 0 < begin && begin <= race->length);
    
    int i;
    
    for(i=begin; i<race->length; i++)
        race->step[i-1] = race->step[i];
    
    return race;
}//end shift_left()



Course *create(Escale *step1, Escale *step2){

    Course *race = malloc(sizeof(Course));
    if(race==NULL)
        return NULL;

    race->array_size = INITIAL_SIZE;
    race->length = 2;
    

    race->step = malloc(INITIAL_SIZE * sizeof(Course*));
    if(race->step==NULL){
        free(race);

        return NULL;
    }

    race->step[0] = step1;
    race->step[1] = step2;

    return race;

}//end create()


char *is_a_loop(Course *race){
    
    assert(race!=NULL);

    if(race->step[0]==race->step[race->length-1])
        race->circuit="oui";
        else
        race->circuit="non";
    
    return race->circuit;

}//end is_a_loop()


int how_many_escale(Course *race){

    assert(race!=NULL);

    return race->length; 

}//end how_many_escape()


int how_many_step(Course *race){

    assert(race!=NULL);

    race->nbr_step=race->length-1;

    return race->nbr_step; 

}//end how_many_escape()


float best_time_race(Course *race){

    assert(race!=NULL);

    int i;
    float btr=0;
    for(i=0; i<race->length; i++){
        
        btr += get_time(race->step[i]);
          
    };

    race->best_time_race = btr;

    return race->best_time_race;

}//end best_time_race()


float best_time_step(Course *race, Escale *step){

    assert(step!=NULL && race!=NULL);

    int i;
    float bts=0;
    for(i=0; i<race->length; i++){

        if(step==race->step[i])
            bts = get_time(race->step[i]);

    };

    return bts;

}//end best_time_step()


Course *add_step(Course *race, int i, Escale *newStep){

    assert(0<=i && i<=race->array_size);

    if(race->length + 1 >= race->array_size)
        race = realloc_array(race);
    
    if(race->step[i]!=NULL)
        race = shift_right(race, i);
    
    race->step[i] = newStep;
    race->length++;

    return race;

}//end add_step()


Course *remove_step(Course *race, int i){

    assert(0<=i && i<race->length);
    
    free(race->step[i]);
    
    race = shift_left(race, i+1);
    free(race->step[race->length-1]);
    race->length--;
    
    return race;

}//end remove_step()
