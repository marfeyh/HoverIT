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
 @file eeprom_api.cpp
 @details This module is providing the security with saving the pincode to the EEPROM
 @note Uses EEPROM library
 @authors Evelina Vorobyeva
 @date May 15, 2012
 */
#include <Arduino.h>
#include <EEPROM.h>
#include "eeprom_api.h"
#include <string.h>

int masterPin = 1234; //masterPin, set when reseted
int address = 10; //address in EEPROM to store the pincode

/*!
 @brief This function saves the pincode to EEPROM
 @param[in]  pincode The pincode to be stored
 @return 0 if successful
 */
int set_password(int pincode) {

	byte lByte = ((pincode >> 0) & 0xFF);
	byte hByte = ((pincode >> 8) & 0xFF);
	EEPROM.write(address, lByte);
	EEPROM.write(address + 1, hByte);
	return 0;
}
/*!
 @brief This function gets the pincode stored in EEPROM
 @return pincode
 */
unsigned int get_password() {
	byte lByte = EEPROM.read(address);
	byte hByte = EEPROM.read(address + 1);
	return ((lByte << 0) & 0xFF) + ((hByte << 8) & 0xFF00);
}
/*!
 @brief This function saves the pincode to EEPROM
 @param[in]  pincode The pincode to be stored
 @return 0 if successful
 */
int reset_password() {
	int result = set_password(masterPin);
	return result;
}
/*!
 @brief This function checks if the inputed pin matches pin in EEPROM
 @param[in]  password The pincode to be checked
 @return 0 if successful, 1 if not successful
 */
int check_password(int password) {
	int passFromMemory = get_password();
	if (passFromMemory == password) {
		return 0;
	} else {
		return 1;
	}
}
