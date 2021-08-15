#include "seatest.h"
#include "course.h"

static void test_best_time_race(){

    Escale *step1 = creation(50.632557, 5.579666, 'Liege');
    Escale *step2 = creation(50.56515, 4.68843, 'Gembloux');
    Course *race = create(step1, step2);

    set_time(step1, 5.346);
    set_time(step2, 12.447);

    assert_false(best_time_race(race) < 0);
    assert_true(best_time_race(race) == get_time(step1) + get_time(step2));


}