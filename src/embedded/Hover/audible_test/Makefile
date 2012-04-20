TEST_DIR = Tests/
SEARDUINO_PATH = /opt/searduino
PROG = audible_test

# Add your source files here
SRC_C = audible_test.cpp 

MAIN_SRC = main.c
ARDUINO = uno
#mega2560
SHLIB = audible_test.so

#LIB = 
LIB_H = audible_test.h
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
