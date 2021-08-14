/**
 * \file course.h
 * \brief ADT for managing the 'Course' type
 * \author Luca Matagne -- Université de Liège (ULg)
 * \date 16/07/2021
 *
 * Presents a 'course' (race) as an abstract data type
 */


#include "seatest.h"
#include"course.h"

static void test_best_time_race(){

    Escale *step1 = creation(50.632557, 5.579666, 'Liege');
    Escale *step2 = creation(50.56515, 4.68843, 'Gembloux');
    Course *race = create(step1, step2);

    set_time(step1, 5.346);
    set_time(step2, 12.447);

    

}