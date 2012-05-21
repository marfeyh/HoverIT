/*
 * Some kind of copyright thing
 * 
 * Author: Viktor Green viktor@student.gu.se
 *
 */

#include <stdio.h>
#include <inttypes.h>
#include "twi_mock.h"

#define MAX_VALUES 1024
#define CONST_BIAS 0

void setup_acc_values(void);
void set_acc_value(int index, int value);
void set_acc_set(uint8_t set);
void set_const_acc_values(int acc, int bias, int const_or_avg_bias);


uint8_t acc_values[MAX_VALUES][2];

int acc_index;
uint8_t address;
uint8_t lastAddress;

/* Function that gets a value (byte) from the i2c master */
void i2c_write(uint8_t value) {
  fflush(stdout);

 switch (address) {
 case 0: 
   address = value;
   break;

 case 0x10:
   if(0xB6 == value) {
     /* Reset accelerometer */
     acc_index = 0;
     address = 0;
     lastAddress = 0;
   }
   else {
     fprintf(stderr, "Writing unknown value (%d) to reset register(0x10)\n",value);
   }
   break; 

 case 0xFF:
   /* Set which set of acceleration values to use */
   set_acc_set(value);
   break;

 default:
    fprintf(stderr, "Writing %d to %d\n", value, address++);
    break;
  }
}

/* Function that returns a value (byte) to the i2c master */
uint8_t i2c_read(void) {
  if(0 == address) address = lastAddress;

  if(acc_index >= MAX_VALUES) acc_index = 0;

  switch(address++) {
  case 2:
    return acc_values[acc_index][0];

  case 3:
    return acc_values[acc_index++][1];

  default:

    fprintf(stderr, "Read from %d\n", address - 1);
    break;
  }

  return 0;
}

void i2c_end(void) {
  /* this is where we should reset the address to read/write */

  lastAddress = address;
  address = 0;
}

int i2c_setup(unsigned int nr) {

  /*  printf("Setup bma180 on id %u\n", nr); */
  address = lastAddress = 0;
  acc_index = 0;
  setup_acc_values();
  twiMock_addTarget(nr, &i2c_write, &i2c_read, &i2c_end);

  return 0;
}

void set_acc_set(uint8_t set) {
  switch(set) {
  case 0:
    setup_acc_values();
    break;

  case 1:
    set_const_acc_values(0, 0, CONST_BIAS);
    break;

  case 2:
    set_const_acc_values(0, 0, 255);
    break;

  default:
    fprintf(stderr, "Unknown acceleration set requested: %d\n", set);
    break;
  }

  return;
}

void setup_acc_values(void) {
  int i;

  for(i = 0; i < 400; i++) { 
    acc_values[i][0] = 0;
    acc_values[i][1] = 0;
  }

  for(;i < MAX_VALUES; i++) {
    /*   acc_values[i][0] = 160;
    acc_values[i][1] = 15;
    */

    set_acc_value(i, (i%10) * 100);
  }
  return;
}

void set_const_acc_values(int acc, int bias, int avg_bias) {
  int i;

  for(i=0; i < 400; i++) {
    if(avg_bias == CONST_BIAS) {
      set_acc_value(i, bias);
    }
    else {
      set_acc_value(i, bias * avg_bias * (i % 2 ? -1 : 1));
    }
  }

  for(;i < MAX_VALUES; i++) {
    set_acc_value(i, acc + bias);
  }
}

void set_acc_value(int index, int value) {
  uint8_t high;
  uint8_t low;

  low = value & 0x3F; /* Lower 6 bits */
  low <<= 2; /* shift two steps left too store the six bits in the "higher valued" "slots" */

  high = value >> 6; /* Upper 8 bits (remove lower 6) */

  if(value < 0) {
    high |= 0x80;   /* insert sign bit. 10000000 */  
  }
  else {
    high &= 0x7F;   /* Remove sign bit. 01111111 */
  }

  acc_values[index][0] = low;
  acc_values[index][1] = high;
}
