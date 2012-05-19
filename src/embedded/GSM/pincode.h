
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
 @file pincode.h
 @details
 @authors Makiko Taira, Andreas Johansson
 @note 
 @date May 16, 2012
 */

#ifndef PINCODE_H
#define PINCODE_H

#ifdef __cplusplus
extern "C" {
#endif

//extern SoftwareSerial cell; 
//! Will hold the incoming character from the Serial Port.
extern char incoming_char;
//! True if the user is logged in with the correct PIN code, otherwise false
extern boolean isLoggedIn;
//! Index in the PIN code String for the next incoming DTMF tone
extern short pinCodeIndex;

void processCommand(const char* command);
int processDTMF(char tone);
int pincodeProcessor();


#ifdef __cplusplus
}
#endif
#endif