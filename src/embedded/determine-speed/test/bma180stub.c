/*
 * Some kind of copyright thing
 * 
 * Author: Viktor Green viktor@student.gu.se
 *
 */

#include <inttypes.h>
#include "twi_mock.h"


/* Function that gets a value (byte) from the i2c master */
void i2c_write(uint8_t value) {

}

/* Function that returns a value (byte) to the i2c master */
uint8_t i2c_read(void) {
  return 0;
}

void i2c_end(void) {
  /* this is where we should reset the address to read/write */
}

int i2c_setup(unsigned int nr) {

  twiMock_addTarget(nr, &i2c_write, &i2c_read, &i2c_end);

  return 0;
}
