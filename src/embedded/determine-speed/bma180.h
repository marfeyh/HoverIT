/******************************************
 * Embedded project - Determining Speed
 * Accelerometer BMA180
 *
 * Copyright (c) Whatever, no warranty.
 *
 * Author: Viktor Green
 ******************************************/

#if defined __cplusplus
extern "C" {
#endif

void bma180_initialize(void);
float getXAccel(float);
float calcXBias(void);


#if defined __cplusplus
}
#endif
