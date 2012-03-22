// test.c -
//
// Created By: 	Yavor Paunov
// Time:	Thursday, March 22 2012
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

#include "bt_client.h"

char address[18] = {0};

int main() {
  init();
  return 0;
}

int init(){
  //inquiry_info *devices = NULL;
  char **names, **addresses;

  int num_discovered;
  int sel_dev, max_rsp, len, max_name_size, address_size;
  int i;

  len = 7;
  max_rsp = 255;

  max_name_size = 248;
  address_size = 18;

  // Allocate memory for the array of inquiry_infos of each device
  //devices = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));

  // Allocate memory for the array of inquiry_infos of each device
  addresses = malloc(255 * sizeof(char*));
  for (i = 0; i < max_rsp; i++)
    addresses[i] = malloc((address_size)*sizeof(char));

  // Allocate memory for the array of names of each device
  names = malloc(max_rsp * sizeof(char*));
  for (i = 0; i < max_rsp; i++)
    names[i] = malloc((max_name_size)*sizeof(char));
 
  get_devices_in_range(max_rsp, len, &num_discovered, addresses, names);

  printf("%d devices have been discovered: \n", num_discovered);
  for (i = 0; i < num_discovered; i++)
    printf("%d. %s  %s\n", i, addresses[i], names[i]);
  printf("Select device to connect:");

  // Read device number from command linex E.g. 0
  scanf("%d", &sel_dev);
  printf("selected %d %s \n", sel_dev, addresses[sel_dev]);

  // Get device address
  strcpy(address, addresses[sel_dev]);
  connect_to_device(address);
  //loop();
  return 0;
}


/*void loop() {
  char input;
  scanf("%s", &input);
  send_to_device(input);
  }*/
