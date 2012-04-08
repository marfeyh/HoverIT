#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned char serial_read(void);
void serial_binary_write(unsigned char*);
void serial_string_write(char*);
void debug_print (unsigned char*);
void debug_write (unsigned char*);
void debug_print_string (char*);
void serial_setup (void);

#ifdef __cplusplus
}
#endif
#endif
