/*
Author: Dmitry Igoshin	
*/

#include <check.h>
#include <stdlib.h>

#include "../../src/loc_struct.h"
#include "../../src/job_queue.h"

void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);

START_TEST(jobs_test) {
        struct Job testJob;
        testJob.prio = HIGH;
        struct List * list1 = (struct List *)  calloc( 1, sizeof(struct List) );
        addJob(testJob,list1);
        struct Job result = pop(list1);

  fail_unless( result.prio == HIGH);

}END_TEST



/* Suite * new_suite(void) { */

/*   Suite *suite = suite_create("jobs_test Suite");	 */
/*   TCase *tcase = tcase_create("jobs_test Test Case"); */
/*   tcase_add_test(tcase, jobs_test); */
/*   suite_add_tcase(suite,tcase); */
/*   return suite; */
/* } */

/* int main(void) { */

/*   int number_failed; */
/*   Suite *suite = new_suite(); */
/*   SRunner *suiter = srunner_create(suite); */
/*   srunner_run_all(suiter,CK_NORMAL); */
/*   number_failed = srunner_ntests_failed(suiter); */
/*   srunner_free(suiter); */
/*   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; */
/* }  */

