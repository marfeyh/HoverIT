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
 @file sms_com.cpp
 @details This module is providing sms communication between the user and Hovercraft
 @authors Evelina Vorobyeva, Alireza Pazirandeh
 @note The module uses NewSoftSerial library
 @date May 10, 2012
 @todo GSM error handling
 */
#include <Arduino.h>
#include <string.h>

#include "sms_com.h"
#include "eeprom_api.h"
#include "pin.h"
#define BUFFSIZE 90

char masterNumber[] = "+46739292462"; //safety number, for restoring the pincode
char mobilenumber[16];

/*!
 @brief This function is for sending sms back to the user
 @param[out] number The user's phone number
 @param[out] text The text message to be sent
 */
int send_sms_back(char *number, char *text) {
	//Set sms format as text
	Serial2.println("AT+CMGF=1");
	//Sending message..
	Serial2.print("AT+CMGS=");
	// Add "" sign
	Serial2.print("\x22");
	// Add number
	Serial2.print(number);
	// "" sign
	Serial2.println("\x22");
	delay(500);
	// Send message
	Serial2.print(text);
	Serial2.print("\x1A");
	return 0;
}
/*!
 @brief This function parses the text messages and provides functionalit according to the content
 @param[out] buffer The message to be parsed
 */
void parse_gsm_input(char *buffer) {
	char text[50];
	char wordString[10];
	//get first word from the string
	readWord(wordString, 0, buffer);
	if (strncmp("+CMT", buffer, 4) == 0) {
		//check if it is an sms
		strncpy(mobilenumber, buffer + 7, 12);
		//copy and store a mobilenumber of the sender
		Serial.println(buffer);
		Serial.println(mobilenumber);
	} else if (strcmp("inst", wordString) == 0) {
		// check if it is inst
		strcpy(text, "Use 2,4,6,8 to navigate the hovercraft");
		//send the instructions back to the user
		send_sms_back(mobilenumber, text);
	} else if ((strcmp("getpin", wordString) == 0)
			&& (strcmp(mobilenumber, masterNumber) == 0)) {
		//check if the masterUser asks for the pincode
		char buf[6];
		Serial.println("inside getpin");
		//retrieve password from EEPROM
		int x = get_password();
		itoa(x, buf, 10);
		strcpy(text, buf);
		//send the password back
		send_sms_back(mobilenumber, text);
	} else if ((strcmp("setpin", wordString) == 0)
			&& (strcmp(mobilenumber, masterNumber) == 0)) {
		newPinMaster(wordString, buffer, text);
	} else if (strcmp("PIN", wordString) == 0) {
		newPin(wordString, buffer, text);
	}
}
/*!
 @brief This function sets a new pin, if it was requested by the masterUser
 @param[out] wordString The variable where the pin will be saved
 @param[out] buffer The message to be parsed, to get the pin from
 @param[out] text The variable where the sms will be saved to be sent back to the user
 */
int newPinMaster(char * wordString, char * buffer, char * text) {
	//check if the masterUser wants to set a new pincode
	Serial.println("Inside alireza's function");
	readWord(wordString, 1, buffer);
	//set the pincode
	int result = set_password(atoi(wordString));
	Serial.println(get_password());
	//send sms back, depending on the result of setting new pincode
	switch (result) {
	case 0:
		strcpy(text, "New password is set");
		send_sms_back(mobilenumber, text);
		Serial.println(get_password());
		return 0;
		break;
	case 1:
		strcpy(text, "Something went wrong with EEPROM");
		send_sms_back(mobilenumber, text);
		return 1;
		break;
	default:
		return 1;
	}
}
/*!
 @brief This function sets a new pin, when provided an old pin
 @param[out] wordString The variable where the pin will be saved
 @param[out] buffer The message to be parsed, to get the pin from
 @param[out] text The variable where the sms will be saved to be sent back to the user
 */
int newPin(char * wordString, char * buffer, char * text) {
// get first pin in sms
	readWord(wordString, 1, buffer);
	// check old pin
	if (check_password(atoi(wordString)) == 0) {
		Serial.println("oldpin = oldpin");
		//get second pin in sms
		readWord(wordString, 2, buffer);
		if (strlen(wordString) < 4) {
			Serial.println(strlen(wordString));
			Serial.println();
			strcpy(text, "New pin is too short!");
			send_sms_back(mobilenumber, text);
		} else if (strlen(wordString) > 4) {
			Serial.println(strlen(wordString));
			Serial.println(wordString);
			strcpy(text, "New pin is too long!");
			send_sms_back(mobilenumber, text);
		} else {
			//new pin code length is ok
			if (atoi(wordString) == 0) {
				strcpy(text, "New password is not numerical");
				send_sms_back(mobilenumber, text);
			} else {
				// everything ok, set new password
				set_password(atoi(wordString));
				Serial.println(get_password());
				strcpy(text, "New pin is set");
				send_sms_back(mobilenumber, text);
				return 0;
			}
		}
	} else {
		// the pin was wrong
		strcpy(text, "Wrong pin!");
		send_sms_back(mobilenumber, text);
	}
	return 1;
}

/*!
 @brief This function is a loop checking inbox for new sms
 */
void check_sms_inbox(char * buffer) {

	//char buffer[BUFFSIZE];
	//char* buffer;
	//int index = readString(buffer);
	//int index = 0;
	//if (index > 0) {
	//Serial.println(buffer);	
	//}

	parse_gsm_input(buffer);
	delay(50);
}

/*!
 @brief This function reads string from Serial
 @param[out] buffer A buffer for 90 characters for storing the string
 @return Index of the buffer
 */
int readString(char *buffer) {

	char buffidx;
	char c;
	// start at begninning
	buffidx = 0;
	//if there are characters coming from the Serial
	while (Serial2.available() > 0) {
		
		//bailout:
		//read each character
		c = Serial2.read();
		if (c == -1) {
			//a character is the end of the word
			buffer[buffidx] = '\0';
		//	Serial.println("sms_com say hi");
			return buffidx;
		}
		//continue to the new line
		if (c == '\n') {
		//	goto bailout;
			continue;
		}
		//the buffer is full
		if ((buffidx == BUFFSIZE - 1) || (c == '\r')) {
			buffer[buffidx] = '\0';
			return buffidx;
		}

		buffer[buffidx] = c;
		buffidx++;
		//goto bailout;

	}
	return buffidx;
}
/*!
 @brief This function splits a line into words
 @param[out] wrd Variable where a word will be stored
 @param[in]  pos A position of the word in the line/sentence
 @param[out] line A line to be splited
 */
int readWord(char* wrd, int pos, char* line) {

	char buffidx;
	char c;
	buffidx = 0;
	int wordidx = 0;
	int wordCount = 0;
	//go through untill get to the right word
	while (wordCount < pos) {
		//increase wordCount when "space" is reached
		if (line[buffidx] == 32) {
			wordCount++;
		}
		buffidx++;
	}
	c = line[buffidx];
	//read untill get to the space or end of the line
	while (!(c == ' ' || (c == 0))) {
		wrd[wordidx] = c;
		wordidx++;
		buffidx++;
		c = line[buffidx];
	}

	wrd[wordidx] = '\0';
	return 0;
}

