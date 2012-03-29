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
#define FAN_MOVE 0b00000000
#define FAN_HOVER 0b00010000
#define RUDDER 0b00100000
#define SPEED 0b00110000
#define PRESSURE 0b01000000
#define BATTERY 0b01010000

#define REQ 0b01100000

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

int hc_connect(char address[18]) {
  int status;
  if(address == NULL){
    status = connect_to_device(ADDRESS);
  } else {
    status = connect_to_device(address);
  }
  return status;
}

int hc_disconnect() {
  disconnect_from_device();
}

int set(unsigned char id, unsigned char value) {
  unsigned char command = id | value;
  int status = send_byte(command);
  return status;
}

int set_rudder(unsigned char value) {
  return set(RUDDER, value);
}

int set_hover_speed(unsigned char value) {
  return set(FAN_HOVER, value);
}

int set_move_speed(unsigned char value) {
  return set(FAN_MOVE, value);
}

// Requests the value of the given 'id' and writes 
// it to the memory pointed to by value.
int get(unsigned char id, unsigned char *value) {
  int status = send_byte(id);
  if(status){
    status = receive_byte(value);
  }
  return status;
}

// Requests the speed.
int get_speed(unsigned char *value){
  return get(SPEED, value);
}

// Requests the pressure.
int get_pressure(unsigned char *value){
  return get(PRESSURE, value);
}

// Requests the battery.
int get_battery(unsigned char *value){
  return get (BATTERY, value);
}
