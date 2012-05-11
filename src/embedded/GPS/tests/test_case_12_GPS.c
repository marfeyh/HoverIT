/**
 * \file 		test_case_6_GPS.c
 * \date 		11-05-2012
 * \version 	0.1 
 * \author 		Gokul S. Evuri          
 * \attention 	Sections added/modified are as follow:
 * 		 none
 */


#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../gps.h"

#define LINEMA 300

/**
 *ID:12
 *Purpose: to test get_position().
 *Preparation: None.
 *Action: Check the returning position with GPS stub data.
 *Expected outcome: position != NULL.
  
**/




START_TEST(test_case_12) {
  struct position* posi = get_position();
  printf("POSITION: %f, %f, %c, %c\n", posi->longitude, posi->latitude, posi->ns, posi->ew);  
  fail_unless(posi->longitude == 0.000000," position is wrong");
  fail_unless(posi->latitude == 8960.000000," position is wrong");
  fail_unless(posi->ns == 'N'," position is wrong");
  fail_unless(posi->ew == 'E'," position is wrong");
  free(posi);
  posi = NULL;
}END_TEST
