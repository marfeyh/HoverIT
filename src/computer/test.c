// test.c -
//
// Created By: 	Yavor Paunov
// Time:	Thursday, March 22 2012
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "hcraft_remote_api.h"


#define ADDRESS "00:0C:84:00:0F:63"

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d\n"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

char address[18] = {0};

int main() {
  hc_connect(address);
  control_loop();
  return 0;
}


/* int print_devices(){ */
/*   //inquiry_info *devices = NULL; */
/*   char **names, **addresses; */

/*   int num_discovered; */
/*   int sel_dev, max_rsp, len, max_name_size, address_size; */
/*   int i; */

/*   len = 7; */
/*   max_rsp = 255; */

/*   max_name_size = 248; */
/*   address_size = 18; */


/*   // Allocate memory for the array of inquiry_infos of each device */
/*   addresses = malloc(255 * sizeof(char*)); */
/*   for (i = 0; i < max_rsp; i++) */
/*     addresses[i] = malloc((address_size)*sizeof(char)); */

/*   // Allocate memory for the array of names of each device */
/*   names = malloc(max_rsp * sizeof(char*)); */
/*   for (i = 0; i < max_rsp; i++) */
/*     names[i] = malloc((max_name_size)*sizeof(char)); */
 
/*   get_devices_in_range(max_rsp, len, &num_discovered, addresses, names); */

/*   printf("%d devices have been discovered: \n", num_discovered); */
/*   for (i = 0; i < num_discovered; i++) */
/*     printf("%d. %s  %s\n", i, addresses[i], names[i]); */
/*   printf("Select device to connect:"); */

/*   // Read device number from command linex E.g. 0 */
/*   scanf("%d", &sel_dev); */
/*   printf("selected %d %s \n", sel_dev, addresses[sel_dev]); */

/*   // Get device address */
/*   strcpy(address, addresses[sel_dev]); */
/*   connect_to_device(address); */
/*   control_loop(); */
/*   return 0; */
/* } */


int control_loop() {
  unsigned char val;
  get_speed(&val);
  printf("Speed:"BYTETOBINARYPATTERN, BYTETOBINARY(val));
  get_pressure(&val);
  printf("Pressure:"BYTETOBINARYPATTERN, BYTETOBINARY(val));
  return 0;
}
