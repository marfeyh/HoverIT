#include <Arduino.h>
#include "pin.h"
#include "gsm_setup.h"


void gsm_setup(){

  //Initialize serial ports for communication.

    //Serial.begin(9600);
    Serial2.begin(9600);

    // Set sms format as text

    Serial2.println("AT+CMGF=1");

    // Receive only incoming sms, no delivery reports

    Serial2.println("AT+CNMI=3,3,0,0");

    //Clean all the messages on the simcard

    Serial2.println("AT+CMGD=1,4");
 
    pinMode(PIN_DTMF_DETECTED, INPUT); //receive the information on this PIN
    pinMode(PIN_DTMF_ACK, OUTPUT); //Send the acknowledgment on this PIN
    pinMode(PIN_DTMF_DATA, INPUT); // Receive the information on this PIN

    Serial2.println("AT+CLIP=1");
    Serial.println("say hi");
   
}