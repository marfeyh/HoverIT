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

void Bma180Initialize(void);
float GetXAccel(float);
float CalcXBias(void);


#if defined __cplusplus
}
#endif
