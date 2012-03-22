// bluetooth_test.c -
//
// Created By: 	Yavor Paunov
// Time:	Tuesday, March 20 2012
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

int get_devices_in_range(int max_rsp, int len, int *num_discovered, char **addresses, char **names) {
  inquiry_info *ii;
  int dev_id, sock, flags;
  int i;
  int num_rsp;
  char name[248] = { 0 };
  char addr[19] = { 0 };
  num_rsp = 1;
  // Assign id of the bt adapter.
  dev_id = hci_get_route(NULL);

  // Assign and open socket.
  sock = hci_open_dev( dev_id );
  if (dev_id < 0 || sock < 0) {
    // Opening socket has failed; exit.
    perror("opening socket");
    exit(1);
  }

  // Flushes the cache of previously detected devices.
  flags = IREQ_CACHE_FLUSH;
    
  // Look for devices and assign to pointer ii. Return number of found devices.
  num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);

  // If number of found devices is less than 0, crash with error.
  if( num_rsp < 0 ) perror("hci_inquiry");

  // Loop through found devices.
  for (i = 0; i < num_rsp; i++) {
    // Convert the bdaddr_t structure of the device to a readable string of the format XX:XX:XX:XX:XX:XX
    ba2str(&(ii+i)->bdaddr, addr);

    strcpy(addresses[i], addr);

    // Get the user friendly name of the device.
    if (hci_read_remote_name(sock, &(ii+i)->bdaddr, 248, names[i], 0) < 0)      // If name is empty, set to [unknown]
      strcpy(names[i], "[unknown]");
    
  }
 
  *num_discovered = num_rsp;

  return 0;
}

int connect_to_device(char dest[18]){
  struct sockaddr_rc addr = { 0 };
  int status;
  
  printf("Connecting to %s... \n", dest);
  // allocate a socket
  connection = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

  // set the connection parameters (who to connect to)
  addr.rc_family = AF_BLUETOOTH;
  addr.rc_channel = (uint8_t) 1;
  str2ba(dest, &addr.rc_bdaddr);
  // send a message
  if( status == 0 ) {
    status = write(connection, "hello!", 6);
  }
  // connect to server
  status = connect(connection, (struct sockaddr *)&addr, sizeof(addr));
  if( status < 0 ) perror("uh oh");
  
  return status;
}

int send_to_device(char message){
  int status;

  status = write(connection, "hello!", 6);

  return status;
}
