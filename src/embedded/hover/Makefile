# 
# @ Module name:  Makefile
# @ Description:  Makefile for controlling hovering motor
#
# @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
# @ Release      :20 March 2012
# @ Version      :1.0
# @ Refrences    :Arduino.cc, http://www.sandklef.com
# http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
# Turnigy_Plush_and_Sentry_ESC user manual
#

TEST_DIR=tests/
SEARDUINO_PATH=/opt/searduino
PROG=hovering

# Add your source files here
SRC_C=hovering_motor.c hovering_control.c
SHLIB=hovering_motor.so
ARDUINO = stub
USER_C_FLAGS=-DSTUB_TEST
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check: SRC_C = hovering_motor.c hovering_control.c ../check_hovering.c
check: USER_LD_FLAGS = -lcheck
check: hovering_motor.o hovering_control.o $(TEST_DIR)check_hovering.o 
	$(MAKE) check -C tests

clean-tests:
	$(MAKE) clean -C tests

.PHONY: check
