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

int main(int argc, char **argv)
{
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };
    // What is dev id?
    dev_id = hci_get_route(NULL);
    printf("dev id %d \n", dev_id);

    // Assign and open socket.
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
      // Opening socket has failed; exit.
        perror("opening socket");
        exit(1);
    }
    printf("sock %d \n", sock);
    // Max time to look for devices. (mult. by 1.28 sec)
    len  = 8;
    // Max devices to look for:
    max_rsp = 255;
    // Flushes the cache of previously detected devices.
    flags = IREQ_CACHE_FLUSH;
    // Allocates memory for the returned devices.
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    // Look for devices and assign to pointer ii. Return number of found devices.
    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    // If number of found devices is less than 0, crash with error.
    if( num_rsp < 0 ) perror("hci_inquiry");
    // Loop through found devices.
    for (i = 0; i < num_rsp; i++) {
      // Convert the bdaddr_t structure of the device to a readable string of the format XX:XX:XX:XX:XX:XX
        ba2str(&(ii+i)->bdaddr, addr);
	
        memset(name, 0, sizeof(name));
	// Get the user friendly name of the device.
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
            name, 0) < 0)
	  // If name is empty, set to [unknown]
        strcpy(name, "[unknown]");
        printf("%d. %s  %s\n", i, addr, name);
    }

    free( ii );
    close( sock );
    return 0;
}
