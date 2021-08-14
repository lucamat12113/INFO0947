/**
 * \file course.h
 * \brief ADT for managing the 'Course' type
 * \author Luca Matagne -- Université de Liège (ULg)
 * \date 16/07/2021
 *
 * Presents a 'course' (race) as an abstract data type
 */

#include <assert.h>
#include <stdlib.h>

#include "course.h"
#include "escale.h"


static Course *print(Course *race){
    assert(race!=NULL);
    
    return race;
}//end print()

int main(){

    Escale *step1 = creation(50.63, 5.58, "Liège");
    Escale *step2 = creation(50.56, 4.69, "Gembloux");

    Course *race = create(step1, step2);

    Escale *step3 = creation(50.83, 4.39, "Bruxelles");

    race = add_step(race, 3, step3);

    print(race);
    
    return 1;
    
}//end main()