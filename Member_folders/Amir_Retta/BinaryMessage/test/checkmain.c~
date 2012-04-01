#include<check.h>
#include<stdlib.h>
#include<messageHandler.h>

START_TEST (parseBinaryTest) {
  int i = 0b00000000;
  // Testing the Fan_Forward_Speed message
  for ( ; i < 0b00001111 ; i++){
	  fail_unless(parseBinary(i)==0);
  }
  for (i = 0b00010000 ; i < 0b00011111 ; i++){
	  fail_if(parseBinary(i)==0);
  }

  // Testing Fan_Hovering_Speed message
  for (i = 0b00010000 ; i < 0b00011111 ; i++){
	  fail_unless(parseBinary(i)==1);
  }
  for (i = 0b00100000 ; i < 0b00111111 ; i++){
	  fail_if(parseBinary(i)==1);
  }

  // Testing Ruder_Direction message
  for (i = 0b00100000 ; i < 0b00101111 ; i++){
	  fail_unless(parseBinary(i)==2);
  }
  for (i = 0b00110000 ; i < 0b00111111 ; i++){
	  fail_if(parseBinary(i)==2);
  }


  // Testing Hovercraft Speed message
  for (i = 0b00110000 ; i < 0b00111111 ; i++){
	  fail_unless(parseBinary(i)==3);
  }
  for (i = 0b01000000 ; i < 0b01001111 ; i++){
	  fail_if(parseBinary(i)==3);
  }


  // Testing Hovercraft Pressure message
  for (i = 0b01000000 ; i < 0b01001111 ; i++){
	  fail_unless(parseBinary(i)==4);
  }
  for (i = 0b01010000 ; i < 0b01011111 ; i++){
	  fail_if(parseBinary(i)==4);
  }
  // Testing Battery Level message
  for (i = 0b01010000 ; i < 0b01011111 ; i++){
	  fail_unless(parseBinary(i)==5);
  }
  for (i = 0b01100000 ; i < 0b01101111 ; i++){
	  fail_if(parseBinary(i)==5);
  }

 } END_TEST



START_TEST(fan_forward_speed_test) {
   // Testing the Fan_Forward_Speed message, message range is 00000000 to 00001111
   static  unsigned char forward[5]={0, 13, 7, 15, 7};
   static unsigned char forward2[5]={19, 18, 21, 27, -12};
 
  fail_unless(findMessage(&forward[_i])==0);
  fail_if(findMessage(&forward2[_i])==0);
   
  
} END_TEST

START_TEST(fan_hovering_speed_test){
   // Testing Fan_Hovering_Speed message, message range is 00010000 to 00011111
   static unsigned char hovering_speed[6]={16, 17, 21, 29, 25, 30};
   static unsigned char hovering_speed2[6]={-2,12, 14, 45, 32, 35};

   fail_unless(findMessage(&hovering_speed[_i])==1);
   fail_if(findMessage(&hovering_speed2[_i])==1);
  
}END_TEST

 START_TEST(ruder_direction_test){
     // Testing Ruder_Direction message, message range is 00100000 to 00101111
   static unsigned char ruder_direction[6]={32, 35, 41, 45, 46, 33};
   static unsigned char ruder_direction2[6]={16, 49, 21, 29, 25, 55};
  
  
   fail_unless(findMessage(&ruder_direction[_i])==2);
  
   fail_if(findMessage(&ruder_direction2[_i])==2);

}END_TEST

START_TEST(hovecraft_speed_test){
  // Testing Hovercraft Speed message, message range is 00110000 to 00111111
   static unsigned char hove_speed[6]={48, 51, 53, 57, 60, 63};
   static unsigned char hove_speed2[6]={16, 31, 47, 29, 72, 65};

   fail_unless(findMessage(&hove_speed[_i])==3);
   fail_if(findMessage(&hove_speed2[_i])==3);
  
}END_TEST

START_TEST(hovecraft_pressure_test){
  
  // Testing Hovercraft Speed message, message range is 00110000 to 00111111
   static unsigned char hove_pressure[7]={64, 66, 69, 70, 73, 77, 79};
   static unsigned char hove_pressure2[7]={1, 31, 47, 63, 80, 100,200};

   fail_unless(findMessage(&hove_pressure[_i])==4);
   fail_if(findMessage(&hove_pressure2[_i])==4);
 
}END_TEST

START_TEST(battery_level_test){
 // Testing Battery Level message, message range is 01010000 to 01011111
   static unsigned char battery_level[7]={80, 85, 89.99, 91, 93, 94.555, 95};
   static unsigned char battery_level2[7]={1, -31, 79, 63, -80, 100,200};

   fail_unless(findMessage(&battery_level[_i])==5);
   fail_if(findMessage(&battery_level2[_i])==5);
 
}END_TEST



START_TEST (create_fan_forward_speed_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0000
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_fan_forward_speed(&i)== i);
  }
  for (i = 0b00010000 ; i < 0b11111111 ; i++){
	  fail_if(create_fan_forward_speed(&i)== i);
  }
 } END_TEST


START_TEST (create_fan_hovering_speed_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0001
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_fan_hovering_speed(&i)== (i | (1<<4)));
  }
 } END_TEST

START_TEST (create_ruder_direction_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0010
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_ruder_direction(&i)== (i | (1<<5)));
  }
 } END_TEST

START_TEST (create_hovercraft_speed_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0011
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_hovercraft_speed(&i)== (i | (3<<4)));
  }
 } END_TEST

START_TEST (create_hovercraft_pressure_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0100
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_hovercraft_pressure(&i)== (i | (1<<6)));
  }
 } END_TEST
START_TEST (create_battery_level_Test) {
  unsigned char i = 0b00000000;
  // The value of the message should be less than 16 which is 4 low value bits
  // The message should be 0101
  for (; i < 0b00010000 ; i++){
	  fail_unless(create_battery_level(&i)== (i | (5<<4)));
  }
 } END_TEST

START_TEST (check_number_limit_Test) {
  unsigned char i = 0b00000000;
 // the number limit should be less than 16 and bigger than -1
  for (; i < 0b00010000 ; i++){
	  fail_unless(check_number_limit(&i)== 1);
  }
  for (i = 0b00010000; i < 0b11111111 ; i++){
	  fail_if(create_battery_level(&i)== 1);
  }
 } END_TEST

/**
 * The follwoing test codes are for the all API functions 
 * to be availbale in weki to the other group so as they can call and 
 * use them when ever they want     
**/

START_TEST (API_fan_forward_speed_Test) {
  unsigned char i =  0b00000000;
  for (; i < 0b00010000 ; i++)
	  fail_unless(fan_forward_speed(i)== i); 
 
  for (i = 0b00010000 ; i < 0b11111111 ; i++)
	  fail_if(fan_forward_speed(i)== i); 

 } END_TEST

START_TEST (API_fan_hovering_speed_Test) {
  unsigned char i =  0b00000000;
  for (; i < 0b00010000 ; i++)
	  fail_unless(fan_hovering_speed(i)== (i | (1<<4))); 
 
  for (i = 0b00010000 ; i < 0b11111111 ; i++)
	  fail_if(fan_hovering_speed(i)==(i | (1<<4))); 

 } END_TEST

START_TEST (API_ruder_direction_Test) {
  unsigned char i =  0b00000000;
  for (; i < 0b00010000 ; i++)
	  fail_unless(ruder_direction(i)== (i | (1<<5)));  

 } END_TEST

START_TEST (API_hovercraft_speed_Test) {
  unsigned char i =  0b00000000;
  for (; i < 0b00010000 ; i++)
	  fail_unless(hovercraft_speed(i)== (i | (3<<4))); 
 
  for (i = 0b00010000 ; i < 0b11111111 ; i++)
	  fail_if(hovercraft_speed(i)==( i | (3<<4))); 

 } END_TEST

START_TEST (API_battery_level_Test) {
  unsigned char i =  0b00000000;
  for (; i < 0b00010000 ; i++)
	  fail_unless(battery_level(i)== (i | (5<<4))); 
 
  for (i = 0b00010000 ; i < 0b11111111 ; i++)
	  fail_if(battery_level(i)==(i | (5<<4))); 

 } END_TEST



Suite* test_hello(void) {
  Suite* s = suite_create("Amir_Retta");
  TCase* tc = tcase_create("Main Test");
  tcase_add_test(tc,parseBinaryTest);
  tcase_add_loop_test(tc, fan_forward_speed_test, 0, 5);
  tcase_add_loop_test(tc, fan_hovering_speed_test, 0, 6);
  tcase_add_loop_test(tc, ruder_direction_test, 0, 6);
  tcase_add_loop_test(tc, hovecraft_speed_test, 0, 6);
  tcase_add_loop_test(tc, hovecraft_pressure_test, 0, 7);
  tcase_add_loop_test(tc, battery_level_test, 0, 7);

 // tcase_add_test(tc,findMessageTest);
  tcase_add_test(tc,create_fan_forward_speed_Test);
  tcase_add_test(tc,create_fan_hovering_speed_Test);
  tcase_add_test(tc,create_ruder_direction_Test);
  tcase_add_test(tc,create_hovercraft_speed_Test);
  tcase_add_test(tc,create_hovercraft_pressure_Test);
  tcase_add_test(tc,create_battery_level_Test);
  tcase_add_test(tc, check_number_limit_Test);
  tcase_add_test(tc, API_fan_forward_speed_Test);
  tcase_add_test(tc, API_fan_hovering_speed_Test);
  tcase_add_test(tc, API_ruder_direction_Test);
  tcase_add_test(tc, API_hovercraft_speed_Test);
  tcase_add_test(tc, API_battery_level_Test);
 
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

