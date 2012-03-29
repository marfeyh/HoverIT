// check_hc_remote.c -
//
// Created By: 	Yavor Paunov
// Time:	Monday, March 26 2012
//
#include <check.h>

#include "check_hc_remote.h"
#include "../src/computer/hcraft_remote_api.h"

START_TEST(connection)
{
  fail_unless(hc_connect() == 0, "Connection could not be establieshed.");
}
END_TEST

START_TEST(set)
{
  fail_unless(set_rudder(0b00001111) < 0);
  fail_unless(set_move_speed(0b00001111) < 0);
  fail_unless(set_hover_speed(0b00001111) < 0);
}
END_TEST

START_TEST(get)
{
  char *value;
  fail_unless(get_speed(value) < 0);
  fail_unless(get_battery(value) < 0);
  fail_unless(get_pressure(value) < 0);
}
END_TEST
