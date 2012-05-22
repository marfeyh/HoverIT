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

#ifndef EXTERNAL_H
#define EXTERNAL_H
extern void check_serial_input(void);

// Propulsion package propulsion_api.h
extern int start_propulsion_fan();
extern int increase_propulsion();
extern int speedLevel;
extern int decrease_propulsion();
extern int get_propulsion_level();
//extern int newprospeed;
extern int stop_propulsion_fan();

// Hover package hover_api.h
extern int initialize(); /* initialize hover fan */
extern int start_hover(); /* start the hovering fan */
extern int stop_hover(); /* stop the fan */
extern int hover_min(); /* minimize the speed */
extern int hover_max(); /* maximize the speed */
extern int decrease_hover_auto(); /* decrease the speed */
extern int increase_hover_auto(); /* increase the speed */
extern int autocontrol(); /* let the fan speed be cotrolled by pressure  sensor automatically */

// Rudder Direction
extern void control_rudder(int);

extern int set_propulsion_fan(int);

// Brake
extern int brake_hovercraft();
extern int change_polarity();

// Wifi
extern unsigned char wifi_read(void);

// GSM
int loop_GSM();

#endif
