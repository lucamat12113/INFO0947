/**
 * \file escale.h
 * \brief ADT for managing the 'Escale'' type
 * \author Luca Matagne -- Université de Liège (ULg)
 * \date 16/07/2021
 *
 * Presents a 'Escale' (stepover) as an abstract data type
 */


#ifndef __ESCALE__
#define __ESCALE__

/**
 * \struct escale
 * \brief Data structure representing a stepover
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
Escale *creation(float x, float y, char *name);

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
 * \fn Float get_time(Escale *step);
 * \brief get the best time to make this step of the race
 * 
 * \param step, the stepover for which we are looking for time. (!=NULL)
 * 
 * \return the stepover with the element 'time' that contains the time to finish the step.
 */
float get_time(Escale *step);

/**
 * \fn void *get(Escale *step);
 * \brief get an entire step whith all the informations from this stopover
 * 
 * \param step, the stepover to get. (!=NULL)
 * 
 * \return all the 'escale' ADT
 */ 
Escale *get(Escale *step);

/**
 * \fn float calc_distance(Escale *step1, Escale *step2);
 * \brief calculates the distance between two cities 
 * 
 * \param step1, the first step. (!= NULL)
 * \param step2, the second step. (!=NULL)
 * 
 * \return the distance between the two cities
 */
float calc_distance(Escale *step_depart, Escale *step);


#endif