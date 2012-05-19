#ifndef SMS_COM_H_
#define SMS_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFSIZE 90;

int send_sms_back(char *number, char *text);
void parse_gsm_input(char * buffer);
void check_sms_inbox(char * buffer);
int newPinMaster(char * wordString, char * buffer, char * text);
int newPin(char * wordString, char * buffer, char * text);
int readString(char *buffer);
int readWord(char* wrd, int pos, char* line);

#ifdef __cplusplus
}
#endif
#endif 
