/*!
 @file check_propulsion.c
 @author Yohanes Kuma
 @author Xinran He
 @author Khatereh Khosravianarab
 @author Ezeh Prince Anthony Anayo
 @brief This file is header file for unit testing propulsion, propulsion
  API and brake propulsion functions.
 @date 2012-05-10
 @reference http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/

#ifndef CHECK_PROPULSION_H
#define CHECK_PROPULSION_H

void setup(void);
void teardown(void);
Suite* propulsion_suite(void);

#endif
