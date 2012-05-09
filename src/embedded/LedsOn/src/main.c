/*!
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
 @file main.c
 @details main file to run functions in fourLedson.c
 @authors Nahid Vafaie
 @version 2 May 9 2012
 @note this is a note about this module (optional)
 @todo if anything should be further developed on this module (optional)
 */



#include <Arduino.h>
#include<searduino.h>
#include "fourLedson.h"

int main(void)
{
  init();
  init_leds();

  for(;;){
    run_leds();
  }
}
