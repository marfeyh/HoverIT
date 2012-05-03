/*
 * Some kind of copyright thing
 * 
 * Author: Viktor Green viktor@student.gu.se
 *
 */

#include <stdio.h>
#include <inttypes.h>
#include "twi_mock.h"

uint8_t address;
uint8_t lastAddress;

/* Function that gets a value (byte) from the i2c master */
void i2c_write(uint8_t value) {
  printf("In write\n");
  fflush(stdout);
  if(0 == address) {
    address = value;
    printf("Set address to %d\n", value);
  }
  else {
    printf("Writing %d to %d\n", value, address++);
  }
}

/* Function that returns a value (byte) to the i2c master */
uint8_t i2c_read(void) {
  printf("In read %p\n", &i2c_read);
  if(0 == address) address = lastAddress;
  printf("Read from %d\n", address++);
  return 0;
}

void i2c_end(void) {
  /* this is where we should reset the address to read/write */

  lastAddress = address;
  address = 0;
}

int i2c_setup(unsigned int nr) {

  printf("Setup bma180 on id %u\n", nr);
  address = lastAddress = 0;
  twiMock_addTarget(nr, &i2c_write, &i2c_read, &i2c_end);

  return 0;
}
