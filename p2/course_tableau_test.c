#include <assert.h>
#include <stdlib.h>

#include "course.h"
#include "escale.h"


static void print(Course *race){
    assert(race!=NULL);
    
    int i;
    Escale *step;
    
    for(i=0; i<how_many_escale(race); i++){
        step = (Escale *)get(race);
        
    }//end for - i
}//end print()

int main(){

    Escale *step1 = creation(50.63, 5.58, "Liège");
    Escale *step2 = creation(50.56, 4.69, "Gembloux");

    Course *race = create(step1, step2);

    Escale *step3 = creation(50.83, 4.39, "Bruxelles");

    race = add_step(race, 3, step3);
    
    return 1;
    
}//end main()