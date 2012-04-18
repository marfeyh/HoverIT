#include "gps.h"
#include "../GPS_Simulator/emulator_GPS.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  char *d = read_rmc_data();
  char *s = retrive_data(d,1);

  printf("%s\n",s);
  free(d);
  free(s);
    return 0;
}
