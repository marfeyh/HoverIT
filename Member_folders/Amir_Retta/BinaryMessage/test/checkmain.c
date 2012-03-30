#include<check.h>
#include<stdlib.h>
#include<messageHandler.h>

START_TEST (parsebaniry) {
	
  static const int binary[6]={16, 12, 14, 10, 20, -20};
 // int i=0;
  fail_unless(parseBinary(binary[_i]) == 1);
  //fail_if(parseBinary(16)==1);
 // fail_unless(parseBinary(i) ==1);
 // fail_unless(parseBinary(i) == 1);
  //fail_unless(parseBinary(i) == 1);
 // fail_unless(parseBinary(i) == 1);
 } END_TEST

START_TEST(fan_forward_speed) {
   static  unsigned char forward[5]={0, 13, 7, 15, 7};
   static unsigned char forward2[5]={19, 18, 21, 27, -12};
 
  fail_unless(findMessage(&forward[_i])==0);
  fail_if(findMessage(&forward2[_i])==0);
    //  test=13;
    //  fail_unless(findMessage(&test)==0); 
    // test=7;
    //  fail_unless(findMessage(&test)==0);
    //  test=17;
    //  fail_if(findMessage(&test)==0);
  
} END_TEST


START_TEST(fan_hovering_speed){
   static unsigned char hovering_speed[6]={16, 17, 21, 29, 25, 30};
   static unsigned char hovering_speed2[6]={-2,12, 14, 45, 32, 35};

   fail_unless(findMessage(&hovering_speed[_i])==1);
   fail_if(findMessage(&hovering_speed2[_i])==1);
   /***
   fail_unless(findMessage(&tes)==1);
   tes=18;
   fail_unless(findMessage(&tes)==1);
   tes=32;
   fail_if(findMessage(&tes)==1);
  **/
}END_TEST
/**
 START_TEST(ruder_direction){
   static unsigned char ruder_direction[6]={16, 17, 21, 29, 25, 30};
   static unsigned char ruder_direction2[6]={16, 17, 21, 29, 25, 30};
  
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
**/


Suite* test_hello(void) {
  Suite* s = suite_create("Retta_Amir");
  TCase* tc = tcase_create("Main Test");
  tcase_add_loop_test(tc, parsebaniry, 0, 6);
  tcase_add_loop_test(tc, fan_forward_speed, 0, 5);
  tcase_add_loop_test(tc, fan_hovering_speed, 0, 6);
 //tcase_add_test(tc, ruder_direction);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int number_failed;
  Suite* suite = test_hello();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner,CK_NOFORK);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

