/*
   This file is part of Hoverit.

   Hoverit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hoverit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Hoverit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 @file conventions.h
 @details This header file contains all conventions number based on project Wiki
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.6
 @see http://hoveritu.com/projects/semb2012/wiki for more information
 */

#ifndef CONVENTIONS_H_
#define CONVENTIONS_H_

/*
 For the messages
 */
#define FAN_FORWARD_SPEED 0 // based on protocl 0000
#define FAN_HOVERING_SPEED 1 // based on protocl 0001
#define RUDER_DIRECTION 2 // based on protocl 0010
#define HOVERCRAFT_SPEED 3 // based on protocl 0011
#define HOVERCRAFT_PRESSURE 4 // based on protocl 0100
#define BATTERY_LEVEL 5 // based on protocl 0101
#define CONNECTION 6 // // based on protocl 0110
#define BACKWARD 8 // // based on protocl 1000
#define HOVERCRAFTOFF 9 // // based on protocl 1001

/*
 For the values
 */
#define STRAIGHT 0
#define HARD_LEFT 1
#define HARD_RIGHT 2
#define SOFT_RIGHT 3
#define SOFT_LEFT 4
#define BRAKE 5
/*
 For only one bit of value to show increase or decrease
 */
#define INCREASING 0
#define DECREASING 1
/*
 For only three bits of value for the stop and turbo commands
 */
#define TURBO 7
#define STOP 0

#define HOVERINGOFF 0
#define TOTALLOFF 1

#define PASSSIZE 4
struct authentication {
	unsigned char user_login; // 0 stands for not login
	char* pass;
	unsigned char pass_size;
};

#endif /* CONVENTIONS_H_ */
