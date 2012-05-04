#include "i2c_loader.h"
#include <stdio.h>

#include "bma180.h"

int main(void) {
  int ret ;

  ret = i2c_add_device (0x40, "./bma180stub.so");

  printf("%d\n", ret);

  Bma180Initialize();

  return 0;
}
