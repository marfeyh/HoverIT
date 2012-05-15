#include "i2c_loader.h"
#include <stdio.h>

/*#include "bma180.h"*/

#include "calculateSpeed.h"


int main(void) {
  int ret ;
  float acc;
  int i;
  Speed* sp;

  ret = i2c_add_device (0x40, "./bma180stub.so");

  printf("%d\n", ret);

  /*  Bma180Initialize();

  acc = GetXAccel(0.0);

  printf("%f\n", acc);  

  */

  sp = create_speed();

  printf("Bias: %f\n", sp->bias);

  for(i = 0; i < 20; i++) {
    calculate_speed(sp);
    printf("Speed: %f\n", get_speed(sp));
    delay(100);
  }

  printf("Speed: %f\n", get_speed(sp));

  speed_free(sp);

  return 0;
}
