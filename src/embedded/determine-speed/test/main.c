#include "i2c_loader.h"
#include <stdio.h>

int main(void) {
  int ret ;

  ret = i2c_add_device (40, "./bma180stub.so");

  printf("%d\n", ret);

  return 0;
}
