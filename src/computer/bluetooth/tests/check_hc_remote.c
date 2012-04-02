// check_hc_remote.c -
//
// Created By: 	Yavor Paunov
// Time:	Monday, March 26 2012
//
#include <stdlib.h>
#include <check.h>

#include "../hcraft_remote_api.h"

START_TEST(connection)
{
  fail_unless(hc_connect() == 0, "Connection could not be establieshed.");
}
END_TEST

START_TEST(set_value)
{
  fail_unless(set_rudder(0b00001111) < 0, "Could not set rudder.");
  fail_unless(set_move_speed(0b00001111) < 0, "Could not set move speed.");
  fail_unless(set_hover_speed(0b00001111) < 0, "Could not set hover speed.");
}
END_TEST

START_TEST(get_value)
{
  char *value;
  fail_unless(get_speed(value) < 0, "Could not get speed.");
  fail_unless(get_battery(value) < 0), "Could not get battery.";
  fail_unless(get_pressure(value) < 0, "Could not get pressure.");
}
END_TEST

START_TEST(disconnection)
{
  fail_unless(disconnect_from_device() < 0, "Could not disconnect from device. What?");
}
END_TEST

Suite * new_suite() {
  Suite *s = suite_create("BT_Comm");

  TCase *tc = tcase_create("connect");
  tcase_add_test(tc,connection);
  tcase_add_test(tc, disconnection);
  suite_add_tcase(s,tc);
  
  tc = tcase_create("send_bytes");
  tcase_add_test(tc, connection);
  tcase_add_test(tc, set_value);
  tcase_add_test(tc, disconnection);
  suite_add_tcase(s, tc);

  tc = tcase_create("receive_bytes");
  tcase_add_test(tc, connection);
  tcase_add_test(tc, get_value);
  tcase_add_test(tc, disconnection);
  suite_add_tcase(s, tc);

  return s;
}
