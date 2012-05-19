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
 @file call_processor.cpp
 @authors Yavor Paunov, Anita Blazheva
 @date April 24, 2012
 */

/*
 Allowing communication with another device
 */
#include <Arduino.h>

/*
 Header File
 */
#include "call_processor.h"
#include "pincode.h"
#include "sms_com.h"
#include "blink.h"
#include "pin.h"
/*
 String manipulation
 */
#include <string.h>

/*
 Data in the buffer
 */
int dataIn = 0;

/*
 First time starting
 */
int firstTimeInLoop = 1;

char buffidx;

char at_buffer[BUFFSIZ];

boolean in_convo;

unsigned char receivedCode[5];

int newToneIndex = 0;

boolean in_hash_mode;

/*!
 @brief Check if 1 or if conversation has ended
 @authors Yavor Paunov, Anita Blazheva.
 @return rining or hang up
 */
int checkGSMInput(char * c) {
	//if(Serial2.available() > 0){
	//c = Serial2.read();
	if (c[0] == 'R') {
		//c = Serial2.read();
		if (c[1] == 'I') {
			//c = Serial2.read();
			if (c[2] == 'N') {
				//c = Serial2.read();
				if (c[3] == 'G') {
					return RINGING;
				}
			}
		}
	}

	if (c[0] == 'N') {
		//c = Serial2.read();
		if (c[1] == 'O') {
			//c = Serial2.read();
			if (c[2] == ' ') {
				//c == Serial2.read();
				if (c[3] == 'C') {
					return HANG_UP;
				}
			}
		}
	}
	//}
	return 0;
}

/*!
 @brief Read from the decoder if a tone is pressed
 @authors Yavor Paunov, Anita Blazheva.
 @return pressed key tone
 */
int readDTMF() {
	boolean dtmfProcessed = false;
	char detected = digitalRead(PIN_DTMF_DETECTED);
	dtmfProcessed = (detected && dtmfProcessed);
	if (!dtmfProcessed & detected) {
		dtmfProcessed = true;

		char tone = 0;
		tone = shiftIn(PIN_DTMF_DATA, PIN_DTMF_ACK, LSBFIRST) & 0xF;

		Serial.print("DTMF :");
		Serial.println((int) tone);

		delay(1000);
		return tone;
	}
	return -1;
}

/*!
 @brief Loop check if 1 or not
 @authors Yavor Paunov, Anita Blazheva.
 */
int loop_GSM() {
	char buffer[90];

	int index = readString(buffer);
	if (index > 0) {
		Serial.println(buffer);
	}

	int event = checkGSMInput(buffer);
	if (event == RINGING) {
		// If the bluetooth connection is established then the phone would not be answered
		if (0 == digitalRead(COMMUNICATION_STATUS_PIN)) {
			Serial2.println("ATA");
			//set_led_On(pinNumber);
			in_convo = true;
		}
	} else if (event == HANG_UP) {
		in_convo = false;
		//set_led_Off(pinNumber);
	} else {
		check_sms_inbox(buffer);
	}

	int currentTone = readDTMF();
	if (currentTone != -1) {
		processTone(currentTone);

	}

	delay(50);
	return 0;
}

/*!
 @brief Switch case for tone parsing and executing
 @authors Stepan Stepasyuk.
 */
int processTone(int tone) {

	if (in_hash_mode) {

		if (tone != 12) {
			if (newToneIndex <= 3) {
				unsigned char toneByte = tone | 0b10100000;
				receivedCode[newToneIndex++] = toneByte;
			}
		} else {
			in_hash_mode = !in_hash_mode;
			Serial.print("in hash tone is: ");
			Serial.println(in_hash_mode);

			//checkpin here

		}

	} else if (receivedCode[0] != '\0' || tone == 12) {

		switch (tone) {

		case 1:
			Serial.println("processTone says 1");
			break;

		case 2:
			Serial.println("processTone says 2");
			break;

		case 3:
			Serial.println("processTone says 2");
			break;

		case 4:
			Serial.println("processTone says 4");
			break;

		case 5:
			Serial.println("processTone says 2");
			break;

		case 6:
			Serial.println("processTone says 6");
			break;

		case 7:
			Serial.println("processTone says 2");
			break;

		case 8:
			Serial.println("processTone says 8");
			break;

		case 9:
			Serial.println("processTone says 2");
			break;

		case 10:
			Serial.println("processTone says 2");
			break;

		case 11:
			Serial.println("processTone says 2");
			break;

		case 12:
			Serial.println("processTone says #");
			if (receivedCode[0] == '\0') {

				in_hash_mode = !in_hash_mode;
				Serial.print("in hash tone is: ");
				Serial.println(in_hash_mode);
			}
			break;

		default:
			Serial.print("processTone says unknown tone: ");
			Serial.println(tone);
		}

	}
	return 0;
}

/* 
 Reads AT String from the SM5100B
 */

/*void readATString(void) {
 Serial.println("start read at");
 char c;

 buffidx= 0;
 while (1) {
 readDTMF();
 
 if(Serial2.available() > 0) {
 c=Serial2.read();
 if (c == -1) {
 at_buffer[buffidx] = '\0';
 return;
 }

 if (c == '\n') {
 continue;
 }

 if ((buffidx == BUFFSIZ - 1) || (c == '\r')){
 at_buffer[buffidx] = '\0';
 return;
 }

 at_buffer[buffidx++]= c;
 }
 }

 }*/

