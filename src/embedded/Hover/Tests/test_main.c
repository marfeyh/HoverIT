
/***************************************************************************
 * Copyright (C) 2012  Eva-Lisa Kedborn                     
 * 		       Jing Liu
 *		       Seyed Ehsan Mohajerani
 *		       Navid Amiriarshad	
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 @file test_main.c
 @author Eva-Lisa Kedborn
 @author Jing Liu
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @brief Contains the functions that check the hovering control files.
 @version 0.4
 @date 2012-04-09
 @see Arduino.cc
 @see sandklef.com
 @see hoveritu.com
 @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @see Turnigy_Plush_and_Sentry_ESC user manual
 @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
 .html
 @see reference for commenting stack.nl/~dimitri/doxygen/commands
 .html#cmdparam
 */

#include <stdlib.h>
#include <check.h>
#include "hovering_check.h"

/*!
@brief Main function to run hover unit tests
@param none
@returns 
*/
int main(void) {
	int number_failed;
	Suite *s = hovering_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS: EXIT_FAILURE;
}
