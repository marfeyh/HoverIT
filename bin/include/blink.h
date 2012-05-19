/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distodributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public
License along with this program. If not, see
<http://www.gnu.org/licenses/gpl-3.0.html>.
*/


/*!
 @file blink.h
 @authors Bishare Stepan
 @date 20120502
*/

#ifndef BLINK_H
#define BLINK_H

#include <Arduino.h>

uint8_t blinker(uint8_t pin);
uint8_t set_led_On(uint8_t pin);
uint8_t set_led_Off(uint8_t pin);

#endif
