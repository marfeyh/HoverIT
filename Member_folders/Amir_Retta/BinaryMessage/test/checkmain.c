#include<check.h>
#include<stdlib.h>
#include<messageHandler.h>

START_TEST (parsebaniry) {
	
  
  fail_unless(parseBinary(16) == 1);
  //fail_if(parseBinary(16)==1);
  fail_unless(parseBinary(12) ==1);
  fail_unless(parseBinary(14) == 1);
  fail_unless(parseBinary(10) == 1);
  fail_unless(parseBinary(20) == 1);
 } END_TEST

START_TEST(fan_forward_speed) {
  unsigned char test = 0;
  fail_unless(findMessage(&test)==0);
  test=13;
  fail_unless(findMessage(&test)==0); 
  test=7;
  fail_unless(findMessage(&test)==0);
  test=17;
  fail_if(findMessage(&test)==0);
  
} END_TEST

START_TEST(fan_hovering_speed){
   unsigned char tes=16;
   fail_unless(findMessage(&tes)==1);
   tes=25;
   fail_unless(findMessage(&tes)==1);
   tes=18;
   fail_unless(findMessage(&tes)==1);
   tes=32;
   fail_if(findMessage(&tes)==1);
}END_TEST
START_TEST(ruder_direction){
   unsigned char te=37;
   fail_if(findMessage(&te)==1);
   te=25;
   fail_if(findMessage(&te)==2);
   te=72;
   fail_if(findMessage(&te)==1);
   te=47;
   fail_unless(findMessage(&te)==2);
   te=64;
   fail_if(findMessage(&te)==1);
}END_TEST



Suite* test_hello(void) {
  Suite* s = suite_create("Retta_Amir");
  TCase* tc = tcase_create("Main Test");
  tcase_add_test(tc, parsebaniry);
  tcase_add_test(tc, fan_forward_speed);
  tcase_add_test(tc, fan_hovering_speed);
tcase_add_test(tc, ruder_direction);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int number_failed;
  Suite* suite = test_hello();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner,CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

