#ifndef WIFI_WRAPPER_H
#define WIFI_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

int wifi_begin(void);

int wifi_write(unsigned char);

unsigned char wifi_read(void);

int wifi_available(void);


#ifdef __cplusplus
}
#endif
#endif
