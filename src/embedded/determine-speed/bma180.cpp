/****************************************** 
 * Embedded project - Determining Speed     
 * Accelerometer BMA180                     
 *                                          
 * Copyright (c) Whatever, no warranty.     
 *
 * Author: Viktor Green
 ******************************************/

#include <Wire.h>
#include "bma180.h"

#define BMA180_BW_TCS 0x20
#define BMA180_ADDRESS 0x40
#define BMA180_RESET_REGISTER 0x10
#define BMA180_OFFSET_REGISTER 0x35
#define BMA180_CONTROL_REGISTER 0x10
#define BMA180_READ_X_ACC_ADDRESS 0x02
#define BMA180_TRIGER_RESET_VALUE 0xB6
#define BMA180_1200HZ_LOW_PASS_FILTER_VALUE 0X70
#define BMA180_ENABLE_WRITE_CONTROL_REGISTER 0x0D

void initialize(void) {
  Wire.begin();
 
  /* Reset the sensor */
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_RESET_REGISTER);
  Wire.write(BMA180_TRIGER_RESET_VALUE);
  Wire.endTransmission();

  delay(10);  

  /* Enable writing to control registers */
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_ENABLE_WRITE_CONTROL_REGISTER);
  Wire.write(BMA180_CONTROL_REGISTER);
  Wire.endTransmission();

  /* Set bw (filter bandwith) & temperature correction value */
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_BW_TCS);
  Wire.write(BMA180_1200HZ_LOW_PASS_FILTER_VALUE);
  Wire.endTransmission();

  /* Set sensitivity/range */
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_OFFSET_REGISTER);
  Wire.write(0x04);                        /* 0x04 means +/-2g */
  Wire.endTransmission();
}

float getXAccel(float bias) {

  int data;

  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_READ_X_ACC_ADDRESS);
  Wire.endTransmission();

  Wire.requestFrom(BMA180_ADDRESS, 2);     /* we want two bytes of data */

  /*
   * The first value read is the lsb, the second is the msb.
   * We shift the msb right, past the lsb, befor they are or'ed together.
   * The acctual value we want doesn't use the last two bits,
   * therefore we right shift the combined value two steps to the left.
   */
  data = (signed short)( Wire.read() | (Wire.read() << 8)) >> 2;

  return data * 0.00245 + bias;

}

float calcBias(void) {
  int samples;
  float sum = 0.0;

  for(samples = 0; samples < 400; samples++) {
    sum += getXAccel(0.0);
    delayMicroseconds(1600);
  }

  return sum/(-400);
}
