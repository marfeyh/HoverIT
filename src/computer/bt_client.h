#if !defined(BT_CLIENT_H)
#define BT_CLIENT_H
int connection;

int get_devices_in_range(int max_rsp, int len, int *num_discovered, char **addresses, char **names);
int connect_to_device(char dest[18]);
int send_to_device(char message);
#endif

