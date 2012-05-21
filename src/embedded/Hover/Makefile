
#***************************************************************************
#* Copyright (C) 2012  Eva-Lisa Kedborn                     
#* 		       Jing Liu
#*		       Seyed Ehsan Mohajerani
#*		       Navid Amiriarshad	
#*
#* This program is free software: you can redistribute it and/or
#* modify it under the terms of the GNU General Public License as published
#* by the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#* 
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#* 
#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*
#****************************************************************************

#
# @file Main Makefile
# @brief Compiles the files and test files for control hovering fan
# @author Eva-Lisa Kedborn 
# @author Jing Liu 
# @author Seyed Ehsan Mohajerani
# @author Navid Amiriarshad
# @date 9 April 2012
# @version 0.9
# @see Arduino.cc
# @see sandklef.com
# @see hoveritu.com
# @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
# @see Turnigy_Plush_and_Sentry_ESC user manual
# @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
# .html
# @see reference for commenting stack.nl/~dimitri/doxygen/commands
# .html#cmdparam

TEST_DIR = Tests/
SEARDUINO_PATH = /opt/searduino
PROG = hovering

# Add your source files here
SRC_C = hovering_motor.c hovering_control.c hovering_init_fix.c \
	hover_api.c pressure_check.c
MAIN_SRC = main.c

#When using uno or mega,following line should be commented
#ARDUINO = stub
#When using stub or mega,following line should be commented 
#ARDUINO = uno
#When using uno or mega,following line should be commented
ARDUINO = mega2560

SHLIB = hovering.so

LIB = libhovering.a
LIB_H = hover_api.h
USER_LIB_INSTALL_PATH = ../../../bin

# Parameters for audible or print testing
#When using uno or mega,following line should be commented
#USER_C_FLAGS=-DSTUB_TEST
#When using uno or mega,following line should be commented
#SRC_C += print_test.c
#When using stub and not using audible test, following 2 line 
#should be commented
#SRC_C += audible_test.c
#USER_C_FLAGS=-DAUDIBLE_TEST
 
USER_C_FLAGS=-Istub/include
USER_LD_FLAGS=-Lstub/lib/$(BOARD) -lpressure_stub

export SRC_FILES = $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check:
	$(MAKE) check -C $(TEST_DIR)

gcovcheck:
	$(MAKE) gcovcheck -C $(TEST_DIR)

gcovbcheck:
	$(MAKE) gcovbcheck -C $(TEST_DIR)

memcheck:
	$(MAKE) memcheck -C $(TEST_DIR)

clean-tests:
	$(MAKE) clean-tests -C $(TEST_DIR)

.PHONY: check
