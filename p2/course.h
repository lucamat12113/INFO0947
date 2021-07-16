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
 * \return a brief race with a ingle step
 */
Course *create(Escale *step1, Escale *step2);




#endif