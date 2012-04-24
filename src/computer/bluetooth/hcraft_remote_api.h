#if !defined(HCRAFT_REMOTE_API_H)
#define HCRAFT_REMOTE_API_H
int hc_connect();
int hc_disconnect();
int set_rudder(unsigned char value);
int set_hover_speed(unsigned char value);
int set_move_speed(unsigned char value);
int get_speed(unsigned char *value);
int get_pressure(unsigned char *value);
int get_battery(unsigned char *value);
#endif
