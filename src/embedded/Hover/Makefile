#*
#* @ Module name:  Main Makefile
#* @ Description:  Compiles the files and test files for control hovering fan
#*
#* @ Author names : Eva-Lisa Kedborn, Jing Liu 
#* 		    Seyed Ehsan Mohajerani, Navid Amiriarshad
#* @ Release      : 9 April 2012
#* @ Version      : 1
#* @ Refrences    : Arduino.cc, sandklef.com, Check manual
#*

# Searduino Path #
SEARDUINO_PATH=/opt/searduino

# Test path #
TEST_DIR = Tests/

# Compiled file #
PROG = hovering

# Source files #
SRC_C = hovering_motor.c hovering_control.c hovering_init_fix.c \
	hover_api.c pressure_check.c pressure.c
SHLIB = hovering.so

# For use in global main #
#ifndef GLOBAL_MAIN
#SRC_C += main.c
#endif
MAIN_SRC = main.c

# Arduino mode #
ARDUINO = stub

# User C flags used in program for test #
#USER_C_FLAGS=-DSTUB_TEST

# Includes #
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# When use make check #
check: SRC_C = pressure_check.c pressure.c hover_api.c \
	       hovering_motor.c hovering_control.c hovering_init_fix.c \
	       ../hovering_check.c
check: USER_LD_FLAGS = -lcheck
#check: hovering_motor.o hovering_control.o hovering_init_fix.o hover_api.o 
#check: pressure_check.o pressure.o $(TEST_DIR)hovering_check.o 
check:
	$(MAKE) check -C Tests

# When use make clean_tests #
clean-tests:
	$(MAKE) clean -C Tests

.PHONY: check
