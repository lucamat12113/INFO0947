#include <stdlib.h>
#include <assert.h>

#include "course.h"
#include "escale.h"

struct Course_t{
    Escale *step;
    struct Course_t *next;
};

typedef struct Course_t cell;


/**
 * \fn static struct cell *create_cell(void *step)
 * \brief Creates a new cell
 *
 * \param step The new step to store in the cell useful part.
 *
 * \return a pointer to a new cell.  The cell linked part is set to NULL.
 */
static cell *create_cell(Escale *step){
    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->step = step;
    n_cell->next = NULL;
    
    return n_cell;
}//end create_cell()


Course *create(Escale *step1, Escale *step2){
    assert(step1!=NULL && step2!=NULL);

    Course *race=NULL;

    if(race!=NULL)
        return NULL;

    Course *n_cell = create_cell(step1);
    race = n_cell;
    if(race==NULL)
        return NULL;

    Course *p = race;

    n_cell = create_cell(step2);

    while(p->next!=NULL){
        p=p->next;
    }//end while

    p->next = n_cell;

    
    return race;

}//end create()


char *is_a_loop(Course *race){
    assert(race!=NULL);

    Course *p = race;

    Escale* comp1 = p->step;

    while(p->next!=NULL){
        p=p->next;
    }//end while

    Escale* comp2 = p->step;
    char circuit[4] = "oui";
    char n_circuit[4] = "non";

    if(comp1==comp2)
        return circuit;
    else
        return n_circuit;

}//end is_a_loop()


int how_many_escale(Course *race){
    assert(race!=NULL);
    
    int longueur = 0;
    Course *p = race;
    
    while(p!=NULL){
        longueur++;
        p = p->next;
    }//end while
    
    return longueur;
}//how_many_escale()


int how_many_step(Course *race){
    assert(race!=NULL);

    int longueur = 0;
    Course *p = race;
    
    while(p!=NULL){
        longueur++;
        p = p->next;
    }//end while
    
    longueur--;

    return longueur;

}//end how_many_step()
    

float best_time_race(Course *race){
    assert(race!=NULL);

    Course *p = race;
    float btr = 0;

    while(p!=NULL){
        btr += get_time(p->step);
        p=p->next;
    }///end while

    return btr;

}//end best_time_race()


float best_time_step(Course *race, Escale *step){
    assert(race!=NULL && step!=NULL);

    Course *p = race;
    float bts = 0;

    while(p!=step){
        p=p->next;
    }//end while()
    
    bts = get_time(p->step);
    
    return bts;

}//end best_time_step()


Course *add_step(Course *race, int i, Escale *newStep){
    assert(race!=NULL && 0<=i && i<how_many_escale(race) && newStep!=NULL);

    if(i==0){
        Course *n_cell = create_cell(newStep);
        if(n_cell == NULL)
            return race;

        n_cell->next = race;

        return n_cell;
    }//fin if i=0
    else{
        int j=0;
        Course *p_cour = race;
        Course *p_prec = NULL;
    
        while(j<i){
            p_prec = p_cour;
            p_cour = p_cour->next;
            j++;
        }//end while()
    
        Course *n_cell = create_cell(newStep);
        if(n_cell == NULL)
            return race;
    
        n_cell->next = p_cour;
        p_prec->next = n_cell;
    
        return race;

    }//end else

}//end add_step()


Course *remove_step(Course *race, int i){
    assert(race!=NULL && 0<=i && i <= how_many_escale(race));

    int j=0;
    Course *p_cour = race;
    Course *p_prec = NULL;

    while(j<i){
        p_prec = p_cour;
        p_cour = p_cour->next;
        j++;
    }//end while()

    p_prec = p_cour->next;
    p_cour->next = NULL;
    free(p_cour);


}//end remove_step()