#if !defined(BT_CLIENT_H)
#define BT_CLIENT_H
int connection;

int get_devices_in_range(int max_rsp, int len, int *num_discovered, char **addresses, char **names);
int start_server(); // For testing.
int stop_server();  // For testing.
int connect_to_device(char dest[18]);
int disconnect_from_device();
int send_byte(char message);
int receive_byte(char *response);

#endif

