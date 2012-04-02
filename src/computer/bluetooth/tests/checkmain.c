#include <stdlib.h>
#include <check.h>
#include "../src/processing.h"


START_TEST(makedouble) {

  fail_unless(processInformation(32) == 32,
		"Expected to be 32");
	//fail_unless(maketwo(3) == 6,
		//"Expected to be 6");
	 
}END_TEST

START_TEST(test_processing)
{
    int j, result;
    for(j= 0; j <= 5; j++){
        result = processMessage((j << 28) | (j+1));
        fail_unless(result == EXIT_SUCCESS, "Failed to process message");
        //printf("i send in: %d", ((j << 12 | (j+1))));
        //printf("\n");
    }
    fail_unless(angle == 1, "angle was not processed correctly");
    fail_unless(batteryLevel == 2, "batteryLevel was not processed correctly");
    fail_unless(fanForwardSpeed == 3, "fanForwardSpeed was not processed correctly");
    fail_unless(hoveringSpeed == 4, "hoveringSpeed was not processed correctly");
    fail_unless(pressure == 5, "pressure was not processed correctly");
    fail_unless(speed == 6, "speed was not processed correctly");
    
}
END_TEST

START_TEST(test_invalid_type)
{
    //Type is 15 so it should fail
    int result = processMessage(0xF<<28);
    fail_unless(result == EXIT_FAILURE, "invalid value not detected");
    
}
END_TEST


Suite * new_suite() {
  Suite *s = suite_create("MakeDouble"); 
  TCase *tc = tcase_create("mkay");
  //tcase_add_checked_fixture(tc,setup,teardown);
  //tcase_add_test(tc,test_addition);
  tcase_add_test(tc,makedouble);
  tcase_add_test(tc,test_processing);
  tcase_add_test(tc,test_invalid_type);
  suite_add_tcase(s,tc);
  return s;
}

main(void) {
  int number_failed;
  Suite *s = new_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

