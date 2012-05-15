/*!
 @file bma180.cpp
 @headerfile stdio.h
 @headerfile bma180.h
 @headerfile Arduino.h
 @headerfile Wire.h
 @brief Geting information of accelometer 
 @author Viktor Green
 @date April 1 2012
 @Collaborator: Sorush Arefipour
 */

#include <stdio.h>
#include <Arduino.h>
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

/*!
 @brief Initializing the accelometer
 */
void bma180_initialize(void) {
  Wire.begin();
 
  // Reset the sensor
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_RESET_REGISTER);
  Wire.write(BMA180_TRIGER_RESET_VALUE);
  Wire.endTransmission();

  delay(10);  

  // Enable writing to control registers
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_ENABLE_WRITE_CONTROL_REGISTER);
  Wire.write(BMA180_CONTROL_REGISTER);
  Wire.endTransmission();

  // Set bw (filter bandwith) & temperature correction value
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_BW_TCS);
  Wire.write(BMA180_1200HZ_LOW_PASS_FILTER_VALUE);
  Wire.endTransmission();

  // Set sensitivity/range
  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_OFFSET_REGISTER);
  //0x04 means +/-2g 
  Wire.write(0x04);                        
  Wire.endTransmission();
}
const char *byte_to_binary ( uint8_t x ) {
  static char b[9];
  uint8_t z;
  char* p = b;

  b[8] = '\0';

  for (z = 128; z > 0; z >>= 1)
    {
      *p++ = (x & z) == z ? '1' : '0';
      /*      strcat(b, ((x & z) == z) ? "1" : "0"); */
    }

  return b;
}

/*!
 @brief Geting Acceleration in X-axis 
 @param float bias: will be added to actual value of accelormeter
 @return float Current acceleration
 */
float getXAccel(float bias) {
 
  int data;
  uint8_t high;
  uint8_t low;

  Wire.beginTransmission(BMA180_ADDRESS);
  Wire.write(BMA180_READ_X_ACC_ADDRESS);
  Wire.endTransmission();
  // we want two bytes of data
  Wire.requestFrom(BMA180_ADDRESS, 2);

  /*!
   * The first value read is the lsb, the second is the msb.
   * We shift the msb right, past the lsb, befor they are or'ed together.
   * The acctual value we want doesn't use the last two bits,
   * therefore we right shift the combined value two steps.
   */
  /*low = Wire.read();
  printf("low:  %s\n", byte_to_binary(low));
  high = Wire.read();
  printf("high: %s\n", byte_to_binary(high));
  */

  data = ( Wire.read() | (Wire.read() << 8)) >> 2;

  /*data = (low | (high << 8)) >> 2;*/
  /*data = high << 8;
  printf("data: %s", byte_to_binary(data >> 8));
  printf("%s\n", byte_to_binary(data));
  data |= low;
  printf("data: %s", byte_to_binary(data >> 8));
  printf("%s\n", byte_to_binary(data));
  data >>= 2;
  printf("data: %s", byte_to_binary(data >> 8));
  printf("%s\n", byte_to_binary(data));
  */
  return data * 0.00245 + bias;

}

/*!
 @brief Calculating Bias to compansate angled accelerometer 
 @return float bias
 */
float calcXBias(void) {
  int samples;
  float sum = 0.0;
  /*
  printf("3:   %s\n", byte_to_binary(3));
  printf("4:   %s\n", byte_to_binary(4));
  printf("3+4: %s\n", byte_to_binary(3+4));
  */
  for(samples = 0; samples < 400; samples++) {
    sum += getXAccel(0.0);
    // 625 microseconds "should" represent 1200Hz  
    delayMicroseconds(625);
  }

  return sum/(-400);
}
