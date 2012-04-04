#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

unsigned char serial_read(void);
unsigned char* serial_binary_write(unsigned char*);
unsigned char* serfial_string_write(char*);

#endif
