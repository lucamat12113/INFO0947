/**
 * \file escale.h
 * \brief ADT for managing the Vector type
 * \author Luca Matagne -- Université de Liège (ULg)
 * \date 16/07/2021
 *
 * Presents a Vector as an abstract data type
 */


#ifndef __ESCALE__
#define __ESCALE__

/**
 * \struct escale
 * \brief Data structure representing a stopover
 */
typedef struct Escale_t Escale;

/**
 * \fn Escale *create(int x, int y, char *name, float time, float dist);
 * \brief Creates an instance of a stepover (Escale)
 * 
 * \param x, the X information
 * \param y, the Y information
 * \param name, the name of the city where the stepovoer is. (!=NULL)
 * 
 * \return a stepover (contact information and name) that is able to store all the necessary information (best time). NULL otherwise
 */
Escale *create(float x, float y, char *name);

/**
 * \fn Escale *set_time(Escale *step, float time);
 * \brief set thee best time to make this step of the race
 * 
 * \param step, the stepover to modify. (!=NULL)
 * \param time, the time to finish the step. (time<0)
 * 
 * \return the stepover with the element 'time' that contains the time to finish the step.
 */
Escale *set_time(Escale *step, float time);

/**
 * \fn void *get(Escale *step);
 * \brief get  
 * 
 * \param step, the stepover to get. (!=NULL)
 * 
 * \return all the 'escale' struct
 */ 
void *get(Escale *step);

/**
 * \fn float calc_distance(Escale *step1, Escale *step2);
 * \brief calculates the distance between two cities 
 * 
 * \param step1, the first step. (!= NULL)
 * \param step2, the second step. (!=NULL)
 * 
 * \return the distance between the two cities
 */
float calc_distance(Escale *step1, Escale *step2);



#endif