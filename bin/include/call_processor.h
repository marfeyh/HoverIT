#ifndef CALL_PROCESSOR_H_
#define CALL_PROCESSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFSIZ 9
#define RINGING 1
#define HANG_UP 2

int checkGSMInput();
int readDTMF();
int loop_GSM();
int processTone(int tone);

#ifdef __cplusplus
}
#endif
#endif
