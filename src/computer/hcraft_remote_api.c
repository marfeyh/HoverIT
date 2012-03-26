// hcraft_remote_api.c -
//
// Created By: 	Yavor Paunov
// Time:	Monday, March 26 2012
//

// Header
#include "hcraft_remote_api.h"

// External
#include <stdio.h>
#include <stdlib.h>

#include "bt_client.h"

// Macros
#define RUDDER 0b01010000
#define ADDRESS "00:0C:84:00:0F:63"

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d\n"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

int hc_connect() {
  int status = connect_to_device(ADDRESS);
  return status;
}

int hc_disconnect() {
  disconnect_from_device();
}

int set(unsigned char id, unsigned char value) {
  printf("id: "BYTETOBINARYPATTERN, BYTETOBINARY(id));
  printf("value: "BYTETOBINARYPATTERN, BYTETOBINARY(value));
  unsigned char command = id | value;
  int status = send_byte(command);
  printf("command: "BYTETOBINARYPATTERN, BYTETOBINARY(command));
  return status;
}

int set_rudder(unsigned char value) {
  return set(RUDDER, value);
}
