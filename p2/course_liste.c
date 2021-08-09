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


int how_many_escale(Course *race){
    int longueur = 0;
    Course *p = race;
    
    while(p!=NULL){
        longueur++;
        p = p->next;
    }//end while
    
    return longueur;
}//end length()


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

