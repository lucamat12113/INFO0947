/**
 * \file course.h
 * \brief ADT for managing the 'Course' type
 * \author Luca Matagne -- Université de Liège (ULg)
 * \date 16/07/2021
 *
 * Presents a 'course' (race) as an abstract data type
 */

#ifndef __COURSE__
#define __COURSE__

#include "escale.h"

/**
 * \struct Course
 * \brief Data structure representing a race.
 */
typedef struct Course_t Course;

/**
 * \fn Course *create(Escale *step1, Escale *step2);
 * \brief create a race with two stepovers, the best time at the first one is set to 0
 * 
 * \param step1, the first stepover of the rece (the start). (step1!=NULL)
 * \param step2, the second stepover. (!=NULL)
 * 
 * \return a brief race with a single step
 */
Course *create(Escale *step1, Escale *step2);

/**
 * \fn char *is_a_loop(Course *race);
 * \brief determinates if the race is a loop or not
 * 
 * \param race, the race which is (or not) a loop
 */
char *is_a_loop(Course *race);

/**
 * \fn int how_many_escale(Course *race);
 * \brief counts how many stepover there is in a race
 * 
 * \param race, the race that we're talking about
 */
int how_many_escale(Course *race);

/**
 * \fn int how_many_step(Course *race);
 * \brief counts how many step there is in the race
 * 
 * \param race, the race that we are talking about
 */
int how_many_step(Course *race);

/**
 * \fn float best_time_race(Course *race);
 * \brief gets the best time for the whole race
 * 
 * \param race, the race that we're talking about
 */
float best_time_race(Course *race);

/**
 * \fn flaot best_time_step(Escale *step);
 * \brief gets the best time for a single step(from a stepover to the ext one)
 * 
 * \param step, the step that we are talking about (stored with the name of the stepover where the step finish)
 */
float best_time_step(Escale *step);

/**
 * \fn Course *add_step(Course *race, Escale *step);
 * \brief add a stepover (ADT 'Escale')to the race
 * 
 * \param step, the step to add to the race (!=NULL)
 * \param race, the race to add oa step in (!=NULL)
 * 
 * \return the new race with the new step
 */
Course *add_step(Course *race, Escale *step);

/**
 * \fn Course *remove_step(Course *race, Escale *step);
 * \brief rmeove a stepover (ADT Escale) 
 * 
 * \param step, the step to remove to the race (!=NULL)
 * \param race, the race to remove a step in (!=NULL)
 * 
 * \return the new race without the step that we removed
 */
Course *remove_step(Course *race, Escale *step);


#endif