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


START_TEST (findMessageTest) {
  unsigned char i = 0b00000000;
  // Testing the Fan_Forward_Speed message, message range is 00000000 to 00001111

  for ( ; i < 0b00001111 ; i++){
	  fail_unless(findMessage(&i)==0);
  }
  for (i = 0b00010000 ; i < 0b00011111 ; i++){
	  fail_if(findMessage(&i)==0);
  }

  // Testing Fan_Hovering_Speed message, message range is 00010000 to 00011111
  for (i = 0b00010000 ; i < 0b00011111 ; i++){
	  fail_unless(findMessage(&i)==1);
  }
  for (i = 0b00100000 ; i < 0b00111111 ; i++){
	  fail_if(findMessage(&i)==1);
  }

  // Testing Ruder_Direction message, message range is 00100000 to 00101111
  for (i = 0b00100000 ; i < 0b00101111 ; i++){
	  fail_unless(findMessage(&i)==2);
  }
  for (i = 0b00110000 ; i < 0b00111111 ; i++){
	  fail_if(findMessage(&i)==2);
  }


  // Testing Hovercraft Speed message, message range is 00110000 to 00111111
  for (i = 0b00110000 ; i < 0b00111111 ; i++){
	  fail_unless(findMessage(&i)==3);
  }
  for (i = 0b01000000 ; i < 0b01001111 ; i++){
	  fail_if(findMessage(&i)==3);
  }


  // Testing Hovercraft Pressure message, message range is 01000000 to 01001111
  for (i = 0b01000000 ; i < 0b01001111 ; i++){
	  fail_unless(findMessage(&i)==4);
  }
  for (i = 0b01010000 ; i < 0b01011111 ; i++){
	  fail_if(findMessage(&i)==4);
  }


  // Testing Battery Level message, message range is 01010000 to 01011111
  for (i = 0b01010000 ; i < 0b01011111 ; i++){
	  fail_unless(findMessage(&i)==5);
  }
  for (i = 0b01100000 ; i < 0b01101111 ; i++){
	  fail_if(findMessage(&i)==5);
  }

 } END_TEST



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



Suite* test_hello(void) {
  Suite* s = suite_create("Amir_Retta");
  TCase* tc = tcase_create("Main Test");
  tcase_add_test(tc,parseBinaryTest);
  tcase_add_test(tc,findMessageTest);
  tcase_add_test(tc,create_fan_forward_speed_Test);
  tcase_add_test(tc,create_fan_hovering_speed_Test);
  tcase_add_test(tc,create_ruder_direction_Test);
  tcase_add_test(tc,create_hovercraft_speed_Test);
  tcase_add_test(tc,create_hovercraft_pressure_Test);
  tcase_add_test(tc,create_battery_level_Test);
  tcase_add_test(tc,check_number_limit_Test);
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

