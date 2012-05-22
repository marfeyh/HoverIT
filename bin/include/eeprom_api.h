#ifndef EEPROM_API_H_
#define EEPROM_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <EEPROM.h>

int set_password(int pincode);
unsigned int get_password();
int reset_password();
int check_password(int password);

#ifdef __cplusplus
}
#endif


#endif 
