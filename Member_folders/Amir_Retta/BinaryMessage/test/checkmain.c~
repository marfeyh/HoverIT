#include<check.h>
#include<stdlib.h>
#include<messageHandler.h>

START_TEST (parsebaniry) {
	
  static const int binary[6]={16, 12, 14, 10, 20, -20};
 
  fail_unless(parseBinary(binary[_i]) == 1);
  
 } END_TEST

START_TEST(fan_forward_speed) {
   static  unsigned char forward[5]={0, 13, 7, 15, 7};
   static unsigned char forward2[5]={19, 18, 21, 27, -12};
 
  fail_unless(findMessage(&forward[_i])==0);
  fail_if(findMessage(&forward2[_i])==0);
   
  
} END_TEST


START_TEST(fan_hovering_speed){
   static unsigned char hovering_speed[6]={16, 17, 21, 29, 25, 30};
   static unsigned char hovering_speed2[6]={-2,12, 14, 45, 32, 35};

   fail_unless(findMessage(&hovering_speed[_i])==1);
   fail_if(findMessage(&hovering_speed2[_i])==1);
  
}END_TEST

 START_TEST(ruder_direction){
   static unsigned char ruder_direction[6]={32, 35, 41, 45, 46, 33};
   static unsigned char ruder_direction2[6]={16, 49, 21, 29, 25, 55};
  
  
   fail_unless(findMessage(&ruder_direction[_i])==2);
  
   fail_if(findMessage(&ruder_direction2[_i])==2);

}END_TEST

START_TEST(hovecraft_speed){
   static unsigned char hove_speed[6]={48, 51, 53, 57, 60, 63};
   static unsigned char hove_speed2[6]={16, 31, 47, 29, 72, 65};

   fail_unless(findMessage(&hove_speed[_i])==3);
   fail_if(findMessage(&hove_speed2[_i])==3);
  
}END_TEST

START_TEST(hovecraft_pressure){
   static unsigned char hove_pressure[7]={64, 66, 69, 70, 73, 77, 79};
   static unsigned char hove_pressure2[7]={1, 31, 47, 63, 80, 100,200};

   fail_unless(findMessage(&hove_pressure[_i])==4);
   fail_if(findMessage(&hove_pressure2[_i])==4);
 
}END_TEST

START_TEST(battery_level){
   static unsigned char battery_level[7]={80, 85, 89.99, 91, 93, 94.555, 95};
   static unsigned char battery_level2[7]={1, -31, 79, 63, -80, 100,200};

   fail_unless(findMessage(&battery_level[_i])==5);
   fail_if(findMessage(&battery_level2[_i])==5);
 
}END_TEST

START_TEST(check_number){
   /*
      test case for chek number limit function
   */
   static unsigned char limit[2]={2, 4};
   static unsigned char limit2[2]={17, 31};
   static unsigned char limit3[2]={15, 0};

   fail_unless(check_number_limit(&limit[_i])==1);
   fail_unless(check_number_limit(&limit2[_i])==255);
   fail_if(check_number_limit(&limit3[_i])==255);
  
}END_TEST


START_TEST(forward_speed){
   /*
      testing fan forwarding speed function  
      range 0 to 15 inclusive
   */
   static unsigned char message=0b00000000;
   for( ; message <= 0b00001111; message++)
        fail_unless(create_fan_forward_speed(&message)==message);
  
    for(message=0b00001111; message < 0b11111111; message++)
       fail_if(create_fan_forward_speed(&message)==message);
   
}END_TEST



START_TEST(hovering_speed){
  /* 
     teasting the creating hover speed function 
     the range should be b/n 16 and 31
   */
   static unsigned char message=0b00010000;
    for (; message <= 0b00011111 ; message++)
   	  fail_unless(create_fan_hovering_speed(&message)== (message|(1<<4)));
    for( message=  0b00011111; message < 0b11100000; message++);
        fail_if(create_fan_hovering_speed(&message)== (message|(1<<4)));
  
}END_TEST

START_TEST(cr_rub_direction){
   /*
     testing creating the ruber direction message
     range is 32 to 47
   */
   static unsigned char message=0b00100000;
   for (; message < 0b00101111 ; message++)
   	  fail_unless(create_ruder_direction(&message)== (message|(1<<5)));
    for( message=0b00101111; message < 0b1100000; message++);
        fail_if(create_ruder_direction(&message)== (message|(1<<5)));
  
}END_TEST

START_TEST(cr_hvc_speed){
 /*
  testing creating the hover creaft messsage function
  range 48 to 63
 */
   static unsigned char message=0b00110000;
   for (; message < 0b00111111 ; message++)
   	  fail_unless(create_hovercraft_speed(&message)== (message|(1<<6)));
    for( message=0b00111111; message < 0b1100000; message++);
        fail_if(create_hovercraft_speed(&message)== (message|(1<<6)));
  
}END_TEST
START_TEST (create_battery_level_Test) {
  unsigned char i = 0b01010000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0101
  for (; i < 0b01011111 ; i++)
	  fail_unless(create_battery_level(&i)== (i | (5<<4)));
  
 for(i=0b01011111; i < 0b10000000; i++)
    fail_if(create_battery_level(&i)== (i | (5<<4)));
 } END_TEST



Suite* test_hello(void) {
  Suite* s = suite_create("Retta_Amir");
  TCase* tc = tcase_create("Main Test");
  tcase_add_loop_test(tc, parsebaniry, 0, 6);
  tcase_add_loop_test(tc, fan_forward_speed, 0, 5);
  tcase_add_loop_test(tc, fan_hovering_speed, 0, 6);
  tcase_add_loop_test(tc, ruder_direction, 0, 6);
  tcase_add_loop_test(tc, hovecraft_speed, 0, 6);
  tcase_add_loop_test(tc, hovecraft_pressure, 0, 7);
  tcase_add_loop_test(tc, battery_level, 0, 7);
  tcase_add_loop_test(tc, check_number, 0, 2);
  tcase_add_test(tc, forward_speed);
  tcase_add_test(tc, hovering_speed);
  tcase_add_test(tc, cr_rub_direction);
  tcase_add_test(tc, cr_hvc_speed);
  tcase_add_test(tc, create_battery_level_Test);
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

