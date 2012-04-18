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

TEST_DIR = Tests/
SEARDUINO_PATH = /opt/searduino
PROG = hovering

# Add your source files here
SRC_C = hovering_motor.c hovering_control.c hovering_init_fix.c \
	hover_api.c pressure_check.c pressure.c
MAIN_SRC = main.c
ARDUINO = mega2560
SHLIB = hovering.so

#LIB = 
LIB_H = hovering_motor.h hovering_control.h hovering_init_fix.h \
	hover_api.h pressure_check.h pressure.h pin.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES = $(SRC_C)

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
