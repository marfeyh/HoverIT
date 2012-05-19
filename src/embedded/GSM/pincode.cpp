
/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as
 published by the Free Software Foundation, either version 3 of the
 License, or (at your option) any later version.
 
 This program is distodributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public
 License along with this program.  If not, see
 <http://www.gnu.org/licenses/gpl-3.0.html>.
 */
/*!
 @file pincode.cpp
 @details Accepting the call and requires PIN code
 @authors Makiko Taira, Andreas Johansson
 @note The module uses SoftSerial library
 @date May 12, 2012
 */


#include <string.h>         
#include <Arduino.h>

#include "pin.h"
#include "eeprom_api.h"
#include "pincode.h" 


//! Will hold the incoming character from the Serial Port.
char incoming_char=0;
//! True if the user is logged in with the correct PIN code, otherwise false
boolean isLoggedIn;
//! Index in the PIN code String for the next incoming DTMF tone
short pinCodeIndex = 0;
//Create a serial port. Pin 2 is the Rx pin, pin 3 is the Tx pin.
char password[6];


/*
 void playHappyTone(){
 Serial2.println("AT+STONE=1,262,20"); //start, frequency, duration(200milliseconds)
 delay(100);
 Serial2.println("AT+STONE=1,330,20"); //start, frequency, duration(200milliseconds)
 delay(100);
 Serial2.println("AT+STONE=1,392,20"); //start, frequency, duration(200milliseconds)
 }
 void playSadTone(){
 Serial2.println("AT+STONE=1,330,3"); //start, frequency, duration(300milliseconds)
 delay(200);
 Serial2.println("AT+STONE=1,311,3"); //start, frequency, duration(300milliseconds)
 delay(200);
 Serial2.println("AT+STONE=1,294,3"); //start, frequency, duration(300milliseconds)
 } */

/**
 * Process incoming command from the GSM modem
 * @param command The command to process
 */
void processCommand(const char* command){
    if(strcmp(command,"RING") == 0){

        Serial.println("\nPicking up a phone");
        Serial2.println("ATA"); //to answer the incoming calls from remote users
        pinCodeIndex = 0; //start from the beginning of the PIN code because it is bad if it remembers the PIN code from the last time and continued
        isLoggedIn = false;
    }
}
/**
 * Process incoming DTMF signal from the MT3271BE chip
 * @param tone the DTMF signal to process
 */
int processDTMF(char tone){
 
    Serial.print("DTMF :");
    Serial.println(tone);
    static char receivedCode[5];
 
    if(!isLoggedIn){ // do only this if nobody is logged in

        receivedCode[pinCodeIndex++] = tone; //add the tone to the array
 
        if(pinCodeIndex >= 4) { // if we have received 4 numbers, check it

            receivedCode[pinCodeIndex] = '\0'; //adds character NULL in the end
 
            itoa(get_password(),password,10);
	    Serial.println(password);
		
		//#pincode#

		if(strcmp(receivedCode, password) == 0){
                //playHappyTone();
                isLoggedIn = true;
                Serial.println("PIN code OK");
                //Pin code was ok, run the function that gets commands from the phone
            }
            else{
                Serial.println("PIN code BAD");
                //playSadTone();
                Serial2.println("ATH"); //Hang up all connected calls
		return 1;
            }
        }
    }
    return 0;  
}


int pincodeProcessor() {
    
    static char command[50]; // 
    static short cmd_index = 0; // the index in the string to put the next received character
    static boolean dtmfProcessed = false;

    // If a DTMF tone is being detected:
    char detected = digitalRead(PIN_DTMF_DETECTED);//check if DTMF is being detected.  digitalRead: read the value for the specified digital PIN
    dtmfProcessed = (detected && dtmfProcessed);//dtmfProcess should be true if it is already true, and a DTMF tone still being detected

    if (!dtmfProcessed & detected) {//If DTMF is being detected and it hasn't been processed yet
        Serial.println("pincode inside !dtmfProcessed & detected");
	dtmfProcessed = true;
        char tone = 0;
        
	//Read which tone was detected by shifting in bits from the DTMF chip
        tone = shiftIn(PIN_DTMF_DATA, PIN_DTMF_ACK, LSBFIRST) & 0xF; //Keep only 4 lowest bits
        if(processDTMF(tone + '0') == 0){
		 Serial.println("pincode inside processDTMF");
		return 0;
		//playHappyTone();
	}else{
		return 1;
        	//playSadTone();
    }
    
    //If there is data on the serial port connected to the GSM moduel
/*    if(Serial2.available() >0){

        incoming_char = Serial2.read();
        Serial.print(incoming_char); //when one byte comes on the serial port from the GSM module, send to the PC

        if (incoming_char == '\r'){ //When we get carriage return, we know the line is finished and we can see what we got

            command[cmd_index] = '\0'; //terminate Command String
            processCommand(command);
            cmd_index = 0;//Start from the beginning
            
        }else if(cmd_index < 49){

            if(incoming_char != 10)//10 is the ascii code for line feed 
                command[cmd_index++] = incoming_char;

        }*/
    }
    return 0;
}
