/**
 * Author:  Johan Wikström Schützer & Gokul Reddy
 * Date:    2012-04-10
 * Version: 1.0 - 2012-04-03 - Function prototypes
 * Version: 1.5 - 2012-04-10 - Added Gokuls parts (function prototypes and structs) 
 **/
if !defined __posi_gps
#define __posi_gps

struct position {
  float longitude;
  float latitude;
  char ns;
  char ew;
};

int check_command(char[],char[]);

/* returns 0 if the given data starts with "$GPRMC", 1 if not */
int is_GPRMC(char[]);

/* returns 0 if the given data starts with "$GPGGA", 1 if not */
int is_GPGGA(char[]);

/* returns 0 if the given data starts with "$GPGSV", 1 if not */
int is_GPGSV(char[]);

/* returns 0 if the given data starts with "$GPGSA", 1 if not */
int is_GPGSA(char[]);

char* read_rmc_data();

char* get_time(char[]);

struct position *get_position(char[]);

char* retrive_data(char[],int);

#endif
