#include "seatest.h"
#include "course.h"
#include <stdlib.h>

static void test_best_time_race(){

    Escale *step1 = creation(50.632557, 5.579666, 'Liege');
    Escale *step2 = creation(50.56515, 4.68843, 'Gembloux');
    Course *race = create(step1, step2);

    set_time(step1, 5.346);
    set_time(step2, 12.447);

    assert_false(best_time_race(race) < 0);
    assert_true(best_time_race(race) == get_time(step1) + get_time(step2));

    free(race);
    free(step1);
    free(step2);

}


static void test_add_step(){

    Escale *step1 = creation(50.632557, 5.579666, 'Liege');
    Escale *step2 = creation(50.56515, 4.68843, 'Gembloux');
    Escale *step3 = creation(50.850340, 4.351710, 'Bruxelles');
    Course *race1 = create(step1, step2);
    Course *race2 = create(step2, step3);

    assert_false(race1 == race2);

    add_step(race1, 2, step3);
    add_step(race2, 0, step1);

    assert_true(race1 == race2);   

    free(race2);
    free(race1);
    free(step1);
    free(step2);
    free(step3);

}


static void test_fixture(){
  test_fixture_start();
  run_test(test_best_time_race);
  run_test(test_add_step);
  test_fixture_end();
}//end test_fixture()

static void all_tests(){
  test_fixture();
}//end all_tests()

int main(){
  return run_tests(all_tests);
}//end main()