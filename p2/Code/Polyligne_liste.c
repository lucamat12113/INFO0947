#include <assert.h>
#include <stdlib.h>

#include "Polyligne.h"



/**
 * @fn struct cell
 * @brief Structure de donnée représentant liste doublement chainée
 * 
 */
typedef struct cell_t{
    cell* prec;
    Point2D *data;
    cell* suiv;

}cell;



struct Polyligne_t{
    Boolean open;
    unsigned int nbpoint;
    float length;
    cell* tete;
    cell* queue;
};


/**
 * @fn static cell *create_cell(Polyligne *data)
 * @brief Crée une nouvelle cellule
 *
 * @param data, la polyligne à stocker dans la partie utile de la cellule
 * 
 * @return un pointuer vers la nouvelle cellule créée, elle n'est liéeà rien pour l'instant.
 */
static cell *create_cell(Polyligne *data){
    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->prec = NULL;
    n_cell->data = data;
    n_cell->suiv = NULL;
    
    return n_cell;
}//end create_cell()



static Polyligne* create_senti(void){
    Polyligne* senti = malloc(sizeof(Polyligne));
    if(senti==NULL)
        return NULL;
    
    senti->open = True;
    senti->nbpoint = 0;
    senti->length = 0;
    senti->tete = NULL;
    senti->queue = NULL;

    return senti;

}//end create_senti()




Polyligne *CreatePolyligne(Point2D *A, Point2D *B){
    assert(A!=NULL && B!=NULL && A!=B);

    Polyligne* P = create_senti();
    P->nbpoint = 2;
    P->length = EuclDist(A,B);
    AddPoint(P, A);
    P->tete = A;
    P->queue = A;
    AddPoint(P,B);
    P->queue = B;
    P->open = True;   

}//end createPolyligne()


void Open(Polyligne* P){   
    assert(P!=NULL);
    


}//end Open()



Polyligne* AddPoint(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!= NULL);

    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->data = A;

    n_cell->suiv = NULL;
    
    cell* old_queue = P->queue;
    if(P->queue == NULL){
        P->queue = n_cell;
        P->tete = n_cell;
    }
    else{
        P->queue->suiv = n_cell;
        n_cell->prec = P->queue;
        P->queue = n_cell;
    }

    P->nbpoint += 1;
    P->length += EuclDist(old_queue,A);
    old_queue = NULL;
    free(old_queue);

    if(P->queue == P->tete)
        P->open = False;
    else{
        P->open = True;
    }

    return P;

}//end add()