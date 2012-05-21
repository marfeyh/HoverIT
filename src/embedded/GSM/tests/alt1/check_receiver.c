/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distodributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public
License along with this program.  If not, see
<http://www.gnu.org/licenses/gpl-3.0.html>.
*/

/*!
 @file check_receiver.c 
 @details This test module tests all the functions in receiver.c
 @author Anita Blazheva, Yavor Paunov
 @version 0.1
 @time: Tuesday, May 15 2012
*/

#include <icrmacros.h>
#include <NewSoftSerial.h>
#include <string.h>
#include <check.h>

/*!
 @brief test checking if connection can be established
 @par Test ID: \n
  *r001 \n
 @par Test Name: Setup \n
 @par Procedure: \n
  * call the function \n
  * try to connect \n
 @par Outcome: \n
  * Connection established
*/
START_TEST(set_up)
{
  fail_unless(setup() == 0, "Cannot setup communication.");
}
END_TEST

/*!
 @brief Attempt checking if GSM input is available
 @par Test ID: \n
  * r002 \n
 @par Test Name: Event \n
 @par Procedure: \n
  * try to check if calling \n
  * try to check if hanged up \n
 @par Outcome: \n
  * 1 for call
  * 2 for hang up
*/

START_TEST(event)
{
  fail_unless(loop() == 0, "Cannot get any input.");
}
END_TEST

/*!
 @brief Attempt checking if ringing or not 
 @par Test ID: \n
  * r003 \n
 @par Test Name: Input \n
 @par Procedure: \n
  * read calling \n
  * read hanged up \n
 @par Outcome: \n
  * Call established
  * User hang up
*/

START_TEST(input)
{
  fail_unless(checkGSMInput() == 0, "Cannot ring or hang up.");
}
END_TEST

/*!
 @brief Attempt to read AT String from SM5100B 
 @par Test ID: \n
  *r004 \n
 @par Test Name: Read \n
 @par Procedure: \n
  * try to read \n
 @par Outcome: \n
  * Read AT string
*/

START_TEST(read)
{
  fail_unless(readATString() == 0, "Cannot read AT String from the SM5100B.");
}
END_TEST

/*!
 @brief Attempt to read a tone
 @par Test ID: \n
  *r005 \n
 @par Test Name: Tone \n
 @par Procedure: \n
  * try to read from the decoder what tone is pressed \n
 @par Outcome: \n
  * Get a pressed tone
*/

START_TEST(tone)
{
  fail_unless(readDTMF() == 0, "Cannot get a pressed tone.");
}
END_TEST


Suite * receiver_suite() {
  Suite *s = suite_create("Receiver");
 
  TCase *tc = tcase_create("setup");
  tcase_add_test(tc, set_up);
  suite_add_tcase(s, tc);

  tc = tcase_create("loop");
  tcase_add_test(tc, event);
  suite_add_tcase(s, tc);

  tc = tcase_create("checkGSMInput");
  tcase_add_test(tc, input);
  suite_add_tcase(s, tc);
  
  tc = tcase_create("readATString");
  tcase_add_test(tc, read);
  suite_add_tcase(s, tc);

  tc = tcase_create("readDTMF");
  tcase_add_test(tc, tone);
  suite_add_tcase(s, tc);

return s;
}

